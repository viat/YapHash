/**
 * @file	Stwt.h
 * @date	Nov 6, 2012
 * @author  Julian Strobl
 * @brief	Short-Time Wavelet Transform.
 */

#ifndef STWT_H_
#define STWT_H_

#ifndef __APPLE__
#include <malloc.h>
#include <stdlib.h>
#endif

#include "Audio.h"
#include "wavelet2s.h"

#include <cmath>
#include <fstream>
#include <iostream>

class Stwt
{
	public:
	    // Convenience constructor
		Stwt(const Audio& rAudio, int WindowSize, int FeedRate);
	    ~Stwt();

	    Fw32f** mSpectrogramm;  // short time wavelet transformation
	    int mFwtLen;
	    int mNoOfWindows;

	    int mJ; // J-Level DWT
	    string mNm; // DWT name

	    int CalcStwt(const Audio& rAudio, int WindowSize, int FeedRate); // calc stwt from audio file
	private:
	    void CopyConvertAndMultiply(float* pInAudio, double* pWindowedAudio, double* pHamming, int FwtLen, int WindowSize);
};

#endif /* STWT_H_ */
