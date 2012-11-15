/**
 * @file		STFT.cpp
 * @date		Mar 30, 2011
 * @author  	Gary Grutzek
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

#include "Stft.h"
#include <cmath>
#include <iostream>
//#include "VIATUtilities.h"
#include <stdlib.h>

#define FFTW // prefer FFTW over IPP

using namespace std;

Stft::Stft(const Audio& audio, int windowSize, int feedRate)
{
    calcStft(audio, windowSize, feedRate);
}

Stft::~Stft()
{
    if (spectrogramm != NULL)
    {
        for (int j = 0; j < NoOfWindows ; j++) 
			delete [] spectrogramm[j] ; 
        delete [] spectrogramm;  
    }
}

//read wav, calc mfcc and write to array
int Stft::calcStft(const Audio &audio, int windowSize, int feedRate) 
{	
	// calculate dimension / num of columns
    NoOfWindows = (audio.length() - (windowSize - feedRate))/feedRate;	
  	int fftOrder; 
    int i,j;
    
    // calc fft length => next power of 2
    fftOrder = ceil(logf(windowSize)/logf(2.0f));
    fftLen = 1 << fftOrder;
    
#ifdef FFTW    
    double *frame_buffer;
    fftw_complex *spectrum;
    fftw_plan p;
    
    // alloc multidimensional array
    spectrogramm = new Fw32f *[NoOfWindows]; // alloc some pointers ...
    for (int i = 0; i < NoOfWindows ; i++) 
        spectrogramm[i] = new Fw32f[fftLen/2]; // ... and alloc an array for each pointer    
    
    // alloc framebuffer for real audio data of each window
    frame_buffer = (double*) fftw_malloc(fftLen * sizeof(double));
    // alloc buffer for calculated complex spectrum of each window
    spectrum = (fftw_complex*) fftw_malloc(fftLen * sizeof(fftw_complex));
    
    // the real to complex fft plan
    p = fftw_plan_dft_r2c_1d(fftLen, frame_buffer, spectrum, FFTW_ESTIMATE );    
    
  //  Fw64u timeStamp1 = fwGetCpuClocks();      
    // pre-calc hamming window
    double* hamming = (double*)malloc(windowSize * sizeof(double)); 
    for(int i=0; i<windowSize; i++)
        hamming[i] = 1 * (0.54 - 0.46*cos(2*M_PI*i/windowSize));
    
    // calc FFT for each window
    for (i = j = 0; i + fftLen < audio.length(); i += feedRate, j++) {
        
        // copy with padding, convert to double and apply hamming window
        // CopyWithHamming(&audio.samples()[i], frame_buffer, fftLen, windowSize);
        CopyConvertAndMultiply(&audio.samples()[i], frame_buffer, hamming, fftLen, windowSize);
        
        // do fft
        fftw_execute(p); /* repeat as needed */ 
        //  calc power spectrum => re*re + im*im
        PowerSpectrum(spectrogramm[j], spectrum, fftLen);
    }
    // get timestamp
 //   Fw64u timeStamp2 = fwGetCpuClocks();
 //   cout << (timeStamp2 - timeStamp1)/(2.4*1E9) << endl;
    
    fftw_destroy_plan(p);
    fftw_free(spectrum); 
    fftw_free(frame_buffer);
    free(hamming);
    
#else  // Intel IPP 
    
    Ipp32f *frame_buffer; // the window buffer
    frame_buffer = ippsMalloc_32f(fftLen);
    
    // alloc multidimensional array
    spectrogramm = new Ipp32f *[NoOfWindows]; // alloc some pointers ...
    for (int i = 0; i < NoOfWindows ; i++) 
        spectrogramm[i] = new Ipp32f[fftLen/2+1]; // ... and alloc an array for each pointer    
    
    // alloc & init fft structure
    IppsFFTSpec_R_32f *pFFTSpec;
	status = ippsFFTInitAlloc_R_32f(&pFFTSpec, 
                                    fftOrder, 
                                    IPP_FFT_DIV_INV_BY_N, // INV ???????
                                    ippAlgHintFast);
    
    // alloc temporary complex buffer !
    // Ipp32fc *pTmp = (Ipp32fc*)ippsMalloc_32f((fftLen)+2); 
    Ipp32fc *pTmp = ippsMalloc_32fc((fftLen)+2); 
    
    Fw64u timeStamp1 = fwGetCpuClocks();
    // calc FFT for each window
    for (i = j = 0; i + windowSize < audio.length(); i += feedRate, j++) 
    { 
        // copy WINDOW_SIZE + evtl. PADDING samples into buffer 
        ippsCopyWithPadding_32f(&audio.samples()[i], windowSize, frame_buffer, fftLen);
        
        // Add the hamming window to the input signal
		ippsWinHamming_32f_I(frame_buffer, windowSize);
        //WinHamming_I((double*)frame_buffer, windowSize);
        
        ippsFFTFwd_RToCCS_32f(frame_buffer, (Ipp32f*)pTmp ,pFFTSpec, 0);
        //
        ippsPowerSpectr_32fc((Ipp32fc*)pTmp, spectrogramm[j], fftLen/2+1);
        //  ippsReal_32fc((Ipp32fc*)pTmp, spectrogramm[j], fftLen/2);        // cout << j << " " << i << endl;
    }
    // get timestamp
    Fw64u timeStamp2 = fwGetCpuClocks();
    cout << (timeStamp2 - timeStamp1)/(2.4*1E9) << endl;
    
    // free mem
    ippsFree(frame_buffer);
    ippsFree(pTmp);
    ippsFFTFree_R_32f(pFFTSpec);
#endif    
    
    return 0;
}

// Copy to double and apply hamming window 
// TODO: optimize this! 
void CopyWithHamming(float *inAudio, double* windowedAudio, int fftLen, int windowSize)
{
    for (int i=0; i<fftLen; i++) {
        if (i > windowSize) 
            windowedAudio[i] = 0;
        else 
            windowedAudio[i] = inAudio[i] * (0.54 - 0.46*cos(2*M_PI*i/windowSize));
    } 
}

// copy with padding (if fftLen > windowSize), multiply with vector (hammming-window) and convert to double
void CopyConvertAndMultiply(float *inAudio, double* windowedAudio, double* hamming, int fftLen, int windowSize)
{
    for (int i=0; i<fftLen; i++) {
        if (i > windowSize) 
            windowedAudio[i] = 0;
        else 
            windowedAudio[i] = inAudio[i] * hamming[i];
    }
//      fwsZero_64f(windowedAudio, windowSize);
//      fwsConvert_32f64f(inAudio, windowedAudio, windowSize);
//      fwsMul_64f_I(hamming, windowedAudio, windowSize);
}


// Inplace hamming window 
void WinHamming_I(double* data, int length)
{
    for(int i=0; i<length; i++)
        data[i] = data[i] * (0.54 - 0.46*cos(2*M_PI*i/length));
}


void PowerSpectrum(Fw32f* power_spectrum, fftw_complex* spectrum, int N)
{
    power_spectrum[0] = spectrum[0][0] * spectrum[0][0];
    for (int k = 1; k < (N+1)/2; ++k)  /* (k < N/2 rounded up) */
        //     power_spectrum[k] = spectrum[k][0] * spectrum[k][0] + spectrum[N-k][1]*spectrum[N-k][1];
        power_spectrum[k] = spectrum[k][0] * spectrum[k][0] + spectrum[k][1]*spectrum[k][1];
    if (N % 2 == 0) /* N is even */
        power_spectrum[N/2] = spectrum[N/2][0] * spectrum[N/2][0];  /* Nyquist freq. */
}
