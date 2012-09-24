/*
 *  VAD.cpp
 *  Voice Activity Detection
 *
 *  Created by Gary Grutzek on 12.10.10.
 *  Copyright 2010 Fachhochschule Koeln. All rights reserved.
 *
 */

#include "VAD.h"
#include <valarray>
#include <iostream>
#include <cstring>
#include <cmath>
#include "VIATUtilities.h"

#define EN_WINDOWSIZE 1000
#define EN_STEPSIZE 100
#define ACF_WINDOWSIZE 160  // 20ms @ 8kHz
#define ACF_STEPSIZE 16     // 2ms  @ 8kHz
#define WAV_LEN     6       // max wav length in seconds
#define SAMPLE_RATE 8000

using namespace std;

void EnergyInWindows(float *energy, 
                     float *data, 
                     unsigned int dataLen, 
                     int windowSize, 
                     int stepSize)
{
	int i,j;
    
	// init vector
	valarray<float>waveData(data, dataLen);
	valarray<float>buffer(windowSize);
	
	// normalize wave data already done in audio.cpp
	//float maxValue = waveData.max();
	//waveData /= maxValue; // normalize to +/-1
	waveData *= waveData; // x^2    
    
	// windowing & sum
	for (i = j = 0; i + windowSize < dataLen; i += stepSize, j++) 
	{
		// Organize the input wave data into a frame
		slice s(i,windowSize,1);
		buffer = waveData[s];
		energy[j] = buffer.sum();
        energy[j] /= windowSize;
        energy[j] = sqrt(energy[j]);
        //cout << energy[j] << " " << endl;
	}
	return;
}

void Energy(double *data, unsigned int dataLen, float *energy)
{
	int i,j;
    
	// init vector
	valarray<double>waveData(data, dataLen);
	valarray<double>buffer(EN_WINDOWSIZE);
	
	// normalize wave data
	double maxValue = waveData.max();
	waveData /= maxValue; // normalize to +/-1
	waveData *= waveData; // x^2
    
	// windowing & sum
	for (i = j = 0; i + EN_WINDOWSIZE < dataLen; i += EN_STEPSIZE, j++) 
	{
		// Organize the input wave data into a frame
		slice s(i,EN_WINDOWSIZE,1);
		buffer = waveData[s];
		energy[j] = (float)buffer.sum();
        // cout << energy[j] << endl;
	}
	return;
}


int Vad(double *data, unsigned int dataLen, int threshold)
{
	//int eLen;	// it's length, num of windows
    int eLen = (dataLen - (EN_WINDOWSIZE - EN_STEPSIZE))/EN_STEPSIZE; // No Of Windows
	float *energy = (float*)malloc(eLen*sizeof(float));
    int idx = -1; // return error -1 when not finding any valuable data
    
	Energy(data, dataLen, energy);
	
	for (int i=0; i<eLen-3; i++) 
	{
		if (energy[i] > threshold) {
			if (energy[i+1] > threshold) {
				if (energy[i+2] > threshold) {
					idx = (i*EN_STEPSIZE);	
                    // free memory
                    free(energy);
                    return idx;
				}
			}
		}
	}
    
    // free memory
    if (energy)
        free(energy);
    return idx;
}

/*
 * Voice activity detection, in place operation
 */
int cutVad_I(double *data, int *dataLen, int threshold)
{
    int idx = Vad(data, *dataLen, threshold);
    
    if (idx == -1) {
        //        cout << "No Audio found, try a lower threshold" << endl;
        idx = 0; // return error ??
        //        return -1;
        throw "No Audio found, try a lower threshold";
    }
    // cout << idx << endl;
    
    int len = *dataLen - idx;
    if (len > 0)
    {
        if (len > SAMPLE_RATE * WAV_LEN) // more than 6 seconds of audio after VAD
        {
            memmove(data, &data[idx], SAMPLE_RATE * WAV_LEN *sizeof(double));
            *dataLen = SAMPLE_RATE * WAV_LEN;
        }
        else // less than 6 seconds left
        {
            memmove(data, &data[idx], len *sizeof(double));
            *dataLen = len;
            //cout << "Shorter than 6s" << endl;
        }
        return 0;
    } 
    else
        return -2;
}

/*
 * Voice activity detection based on autocorrelation
 */
int AutocorrelationVad(Fw32f *data, int dataLen, int threshold)
{  
    int i,j=0;
    int len = getNoOfWindows(dataLen, ACF_WINDOWSIZE, ACF_STEPSIZE);
    int idx = -1; // return error -1 when not finding any valuable data
    
    Fw32f *c = fwsMalloc_32f(len); 
    Fw32f *acf = fwsMalloc_32f(ACF_WINDOWSIZE-1);
    
    // windowing & sum + calc AKF for each window
    for (i = j = 0; i + ACF_WINDOWSIZE < dataLen; i += ACF_STEPSIZE, j++) 
    {
        fwsAutoCorr_32f(&data[i], ACF_WINDOWSIZE, acf, ACF_WINDOWSIZE-1);
        fwsDivC_32f_I((1 + acf[0]), acf, ACF_WINDOWSIZE-1); // norm by energy
        fwsMax_32f(&acf[10], ACF_WINDOWSIZE-10, &c[j]); // take maximum from 0 to ACF SIZE/2 - 3 
    }
        
    float thresh = threshold/100.0f;
    
	for (int i=0; i<len-3; i++) 
	{
		if (c[i] > (thresh)) {
			if (c[i+1] > (thresh)) {
				if (c[i+2] > (thresh)) {
					idx = (i*ACF_STEPSIZE);	
                    // free memory
                    fwsFree(acf);
                    fwsFree(c);
                    return idx;
				}
			}
		}
	}
    if (acf) 
        fwsFree(acf);
    if (c) 
        fwsFree(c);
    return idx;
}

/*
 * Voice activity detection based on autocorrelation, inplace operation
 */
int cutACFVad_I(Fw32f *data, int *dataLen, int threshold)
{
    int idx = AutocorrelationVad(data, *dataLen, threshold);
    
    if (idx == -1) 
    {
        idx = 0; // return error ??
        //        return -1;
        throw "No Audio found, try a lower threshold";
    }
    // debug
    //cout << idx << endl;
    
    int len = *dataLen - idx;
    if (len > 0)
    {
        if (len > SAMPLE_RATE * WAV_LEN) // more than 6 seconds of audio after VAD
        {
            memmove(data, &data[idx], SAMPLE_RATE * WAV_LEN *sizeof(Fw32f));
            *dataLen = SAMPLE_RATE * WAV_LEN;
        }
        else // less than 6 seconds left
        {
            memmove(data, &data[idx], len *sizeof(Fw32f));
            *dataLen = len;
           // cout << "Shorter than 6s" << endl;
        }
        return 0;
    } 
    else
        return -2;
}

