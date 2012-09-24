/*
 *  Stft.h
 *  VIAT Feature-Extraction Framework
 *
 *  Short-Time Fourier-Transform based on Intel IPP
 *
 *  Created by Gary Grutzek on 30.03.11.
 *  Copyright 2011 Fachhochschule Koeln. All rights reserved.
 *
 */

#ifndef _STFT_H_
#define _STFT_H_

#include "fwBase.h"
#include "fwSignal.h"
#include "Audio.h"
//#include <complex.h>
#include <fftw3.h>

class Stft{
    
public:
    
    // Convenience constructor
    Stft(const Audio& audio, int windowSize, int feedRate);
    int calcStft(const Audio &audio, int windowSize, int feedRate);	// calc stft from audio file
    
    // destructor
    ~Stft(); 
    
    Fw32f **spectrogramm;  // Short time fourier transformation
    int fftLen;
    int NoOfWindows; 
    
private:
	//IppStatus status;
};


void WinHamming_I(double* data, int length);
void CopyWithHamming(float *inAudio, double* windowedAudio, int fftLen, int windowSize);
void CopyConvertAndMultiply(float *inAudio, double* windowedAudio, double* hamming, int fftLen, int windowSize);
void PowerSpectrum(Fw32f* power_spectrum, fftw_complex* spectrum, int N);


#endif

