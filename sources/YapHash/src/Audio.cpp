/**
 * @file		Audio.cpp
 * @date		April 04, 2011
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

#include "Audio.h"
#include "VAD.h"    // voice activity detection
#include <math.h>
#include <algorithm>
#include "iostream"
#include "VIATUtilities.h"
using namespace std;



#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

/**
 * In-place pre-emphasize audio
 */
void preEmphasize(Fw32f *samples, int len, Fw32f preemphasisFactor)
{
    // simple hi pass filter
    for (size_t n=1; n<len; n++)
        samples[n] = samples[n] - (samples[n-1] * preemphasisFactor);
}

/*
 *   declicker to reduce spikes in audio data
 */
void deClicker(Fw32f *samples, int len, int threshold)
{
    // mean of absolute wave data
    Fw32f mean;
    Fw32f *tmpAbs = fwsMalloc_32f(len);
    fwsAbs_32f(samples, tmpAbs, len);
    fwsMean_32f(tmpAbs, len, &mean, fwAlgHintFast);
    fwsFree(tmpAbs);
    
    // declicker, minimize clicks and pops higher than mean
    for (int i=0; i < len; i++) {
        if(fabs(samples[i]) > threshold * mean) {
            if (i > 0 && i < len)
                samples[i] = (samples[i-1] + samples[i+1]) / 2 ;
            else
                samples[i] = 0;
        }
    }
}


/**
 *  Audio Implementation
 */


/*  Konstruktor
 *  - Reads wave file. 
 *  - Applies Voice activity detection, preemphasize and declicker alg.
 *  - cuts to 6 seconds 
 *  - saves samples as scaled float between -1 and 1
 */
Audio::Audio(const char *filePath, int thresholdVAD, int thresholdDeclicker, int preEmphasizeFactor)
{
    waveFile wave;
    
    if(ReadWav(filePath, &wave))
        throw "Error in ReadWav()";
    
    fs = wave.fs;
    len = MIN(6*fs, wave.dataLength);// max 6s of audio 
    
    // len = wave.dataLength;
    
    // convert to float and divide by 2^15
    Fw32f *tmpWav = fwsMalloc_32f(len);
    fwsConvert_16s32f_Sfs(wave.data, tmpWav, len, 15);  
    
    // declicker reduces short spikes in audio data
    deClicker(tmpWav, len, thresholdDeclicker);
    
    // pre emphasize higher frequencies
    preEmphasize(tmpWav, len, (preEmphasizeFactor/100.0)); 
    
    // normalize to +/- 1
    Fw32f pMax = 0;
    fwsMax_32f(tmpWav, len, &pMax);
    Fw32f pMin = 0;
    fwsMin_32f(tmpWav, len, &pMin);
    pMax = max(pMax, pMin * (-1));
    if (pMax != 0) 
        fwsDivC_32f_I(pMax, tmpWav, len);
    
    // Voice activity detection / input alignement
    cutACFVad_I(tmpWav, &len, thresholdVAD);
    
    // copy samples and convert to float32
    samples32f = fwsMalloc_32f(len);
    fwsCopy_32f(tmpWav, samples32f, len);   
    
    delete wave.data;
    fwsFree(tmpWav);
}

Audio::Audio(double *waveSamples, int waveLength)
{
    len = waveLength;
    fs = 8000;
    
    // copy samples and convert to float32
    samples32f = fwsMalloc_32f(waveLength);
    fwsConvert_64f32f(waveSamples, samples32f, waveLength);
}

// Destruktor
Audio::~Audio()
{
    fwsFree(samples32f);
}




