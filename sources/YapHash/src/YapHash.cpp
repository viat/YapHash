/**
 * @file		YapHash.cpp
 * @date		Feb 11, 2012
 * @author  	Gary Grutzek
 * @brief		YapHash - Yet Another Perceptual Hash
 * @details		An audio fingerprinting system for speech content
 * 				- Hash is based on spectral and cepstral coefficients
 * 				- The differences (derivatives) in time and frequency direction are calculated
 * 				- the sign of this differences are mapped to 0 and 1
 * 				- the concatenated zeros and ones is the hash value
 *
 * @copyright  	Copyright (c) 2012 Gary Grutzek<br>
 * 				Cologne University of Applied Sciences<br>
 * 				<br>
 * 				This program is free software: you can redistribute it and/or modify
 *				it under the terms of the GNU General Public License as published by
 *				the Free Software Foundation, either version 3 of the License, or
 * 				(at your option) any later version.<br>
 *				This program is distributed in the hope that it will be useful,
 *				but WITHOUT ANY WARRANTY; without even the implied warranty of
 *				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *				GNU General Public License for more details.<br>
 *				You should have received a copy of the GNU General Public License
 *				along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "YapHash.h"
#include <iostream>
#include "VIATUtilities.h"
#include "fftw3.h"

#ifndef __APPLE__
#include <malloc.h>
#include <stdlib.h>
#endif



//#define LOGSPEC_MFCC // apply logarithm to spectrogram first, then apply mel-filterbank (takes some time)

using namespace std;

// convenience constructor
YapHash::YapHash(const Audio& audio, const MelFb& melBank, Parameter *param)
{
    int HashLen = getNoOfWindows(audio.length(), param->windowSize, param->stepSize) - 1;
    hash = (unsigned long*) malloc(sizeof(unsigned long)*HashLen);
    calcHash(audio, melBank, param);
}

YapHash::~YapHash()
{
    if (index)
        free(index);
}


void YapHash::calcHash(const Audio& audio, MelFb melBank, Parameter *param)
{
    // calc stft
    Stft stft = Stft(audio, param->windowSize, param->stepSize);
    
    if (param->debugLevel > 2){
        debugStftToCSV("debugStft.csv",&stft);
        cout << "Wrote STFT coefficients to file debugStft.csv" << endl;
        debugFbToCSV("debugMelFb.csv", &melBank);
        cout << "Wrote Mel Filterbank to file debugMelFb.csv" << endl;
    }
    
    int stftCoeffs = param->melCoeffs+1; // diff
    int mfccCoeffs = param->mfccCoeffs+2; // diff + no C(0)
    
    // get energy of windows
    float *e = (float *) malloc(stft.NoOfWindows * sizeof(float));
    
    EnergyInWindows(e, audio.samples(), audio.length(), param->windowSize, param->stepSize);
    
    // 2D buffer
    Array2d_32f melSpec = Array2d_32f(stft.NoOfWindows, stftCoeffs);
    Array2d_32f dStft = Array2d_32f(stft.NoOfWindows, stftCoeffs-1);
    Array2d_32f mfcc = Array2d_32f(stft.NoOfWindows, mfccCoeffs-1);
    Array2d_32f dMfcc = Array2d_32f(stft.NoOfWindows, mfccCoeffs-2);
    
    
    
    // Apply mel filterbank and write to buffer
    melBank.applyMelFB(melSpec.data, stft);  
    
    if (param->debugLevel > 2){
        debug2DToCSV("debugMelSpec.csv",&melSpec,stft.NoOfWindows,stftCoeffs);
        cout << "Wrote Mel Spectrum coefficients to file debugMelSpec.csv" << endl;
    }    
    // HASH - stft
    // derivation in frequency direction
    for (int y=0; y<stftCoeffs-2; y++) {  
        for (int x=0; x<stft.NoOfWindows; x++) 
            dStft.data[x][y] = melSpec.data[x][y+1] - melSpec.data[x][y];                   
    }
    // derivation in time direction
    for (int x=0; x<stft.NoOfWindows-1; x++) {
        for (int y=0; y<stftCoeffs-1; y++) {   
            dStft.data[x][y] = dStft.data[x+1][y] - dStft.data[x][y];
            // val <= 0 ? : 0 , val > 0 ? : 1
            if (dStft.data[x][y] > 0)
                dStft.data[x][y] = 1;
            else
                dStft.data[x][y] = 0;
        }
    }
    if (param->debugLevel > 2){
        debug2DToCSV("debugStftDiff.csv",&dStft,stft.NoOfWindows-1,stftCoeffs-1);
        cout << "Wrote STFT binary derivation coefficients to file debugStftDiff.csv" << endl;
    }
    
#ifdef LOGSPEC_MFCC 
    Array2d_32f melLogSpec = Array2d_32f(stft.NoOfWindows, stftCoeffs);
    
    // logarithmus naturalis of spectrogram
    for (int j=0; j<stft.NoOfWindows; j++) {
        fwsLn_32f_I(stft.spectrogramm[j], stft.fftLen/2);
    }
    // Apply mel filterbank and write to buffer
    melBank.applyMelFB(melLogSpec.data, stft);  
    
    // MFCC => LN + DCT
    Fw64f *pMel = fwsMalloc_64f(melLogSpec.rows);
    Fw64f *pTmp = fwsMalloc_64f(mfccCoeffs);
    
    // the real to real fft plan, Type II DCT
    fftw_plan p = fftw_plan_r2r_1d(mfccCoeffs, pMel, pTmp, FFTW_REDFT10 ,FFTW_ESTIMATE);    
    
    for (int i=0; i<melSpec.cols; i++) {
        fwsConvert_32f64f(melLogSpec.data[i], pMel, melLogSpec.rows);
        // dct
        fftw_execute(p); 
        // copy all coeffs but C(0)
        fwsConvert_64f32f(&pTmp[1], &mfcc.data[i][0], mfccCoeffs-1);
        
        if (param->debugLevel > 2){
            debug2DToCSV("debugMfcc.csv", &mfcc, stft.NoOfWindows, mfccCoeffs-1);
            cout << "Wrote MFCC coefficients to file debugMfcc.csv" << endl;
        }
    }
#else    
    // MFCC => LN + DCT
    Fw64f *pMel = fwsMalloc_64f(melSpec.rows);
    Fw64f *pTmp = fwsMalloc_64f(mfccCoeffs);
    
    // the real to real fft plan, Type II DCT
    fftw_plan p = fftw_plan_r2r_1d(mfccCoeffs, pMel, pTmp, FFTW_REDFT10 ,FFTW_ESTIMATE);    
    
    for (int i=0; i<melSpec.cols; i++) {
        fwsConvert_32f64f(melSpec.data[i], pMel, melSpec.rows);
        // logarithmus naturalis
        fwsLn_64f_I(pMel, stftCoeffs);
        // dct
        fftw_execute(p); 
        // copy all coeffs but C(0)
        fwsConvert_64f32f(&pTmp[1], &mfcc.data[i][0], mfccCoeffs-1);
        
    }
    if (param->debugLevel > 2){
        debug2DToCSV("debugMfcc.csv", &mfcc, stft.NoOfWindows, mfccCoeffs-1);
        cout << "Wrote MFCC coefficients to file debugMfcc.csv" << endl;
    }
    
#endif
    
    // free
    fftw_destroy_plan(p);
	fwsFree(pMel);
	fwsFree(pTmp);
    
    
    // HASH - mfcc
    // derivation in frequency direction
    for (int y=0; y<mfcc.rows-1; y++) {   
        for (int x=0; x<mfcc.cols; x++) {
            // derivation in frequency direction
            dMfcc.data[x][y] = mfcc.data[x][y+1] - mfcc.data[x][y];
            // val <= 0 ? : 0 , val > 0 ? : 1
            if (dMfcc.data[x][y] > 0)
                dMfcc.data[x][y] = 1;
            else
                dMfcc.data[x][y] = 0;
        }
        // the ipp way won't work ?!        
        // ippsSub_32f(&mfcc.data[0][y+1], &mfcc.data[0][y], &dMfcc.data[0][y], mfcc.cols); 
        // ippsThreshold_LTValGTVal_32f_I(&dMfcc.data[0][y], stft.NoOfWindows, 0, 0, 0, 1); 
    }
    
    if (param->debugLevel > 2){
        debug2DToCSV("debugMfccDiff.csv",&dMfcc,stft.NoOfWindows-1,mfccCoeffs-2);
        cout << "Wrote MFCC binary frequency differences to file debugMfccDiff.csv" << endl;
    }    
    // generate hash of each column
    
    unsigned long *mfcHash = (unsigned long*)malloc((stft.NoOfWindows-1) * sizeof(unsigned long));
    unsigned long *stftHash = (unsigned long*)malloc((stft.NoOfWindows-1) * sizeof(unsigned long));
    index = (unsigned long*)malloc(2 * (stft.NoOfWindows-1) * sizeof(unsigned long)); // index: [position, hash]
    
    if (!index) {
        printf("Malloc error!");
        return;
    }
    
    
    int k=0;
    for (int i=0; i<stft.NoOfWindows-1; i++) {
        //std::cout << "e: " << e[i] << std::endl;
        if (e[i] > (float)(param->energyThreshold/500.0) ) {
            mfcHash[k] = bin2Dec(&dMfcc.data[i][0], mfccCoeffs-2);
            stftHash[k] = bin2Dec(&dStft.data[i][0], stftCoeffs-2); 
            // cout << stftHash[k] << endl;
            // compose hash from mfccc and stft derivates
            hash[k] = (mfcHash[k] << (stftCoeffs-1)) + stftHash[k] + 1;
            index[2*k] = i+1; // position
            index[2*k+1] = hash[k];
            k++;
        }
    }
    indexLen = k;
    
    free(mfcHash);
    free(stftHash);
    free(e);
    
    if (param->debugLevel > 2){
        // writeIndexToCSV("debugMfcc.csv", mfcHash, stft.NoOfWindows-1);
        // writeIndexToCSV("debugStft.csv", stftHash, stft.NoOfWindows-1);
    }
}

// binary to decimal: vector € {0,1}, len < 32
Fw64u YapHash::bin2Dec(Fw32f *vector, int len)
{
    unsigned long hash=0;    
    //  cout << len << endl;
    for (int i=0; i<len; i++) {
        // cout << i << ": " << vector[i] << endl;
        hash |= (((int)vector[len-i-1]) << i);
    }
    return hash;
}



