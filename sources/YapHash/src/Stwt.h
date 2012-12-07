/**
 * @file		Stwt.h
 * @date		Nov 6, 2012
 * @author  	Julian Strobl
 * @brief		Short-Time Wavelet Transform.
 * @details		Calculates short time Wavelet transfrom + windowing stuff
 *
 * @copyright  	Copyright (c) 2012 Julian Strobl<br>
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

#ifndef STWT_H_
#define STWT_H_

#ifndef __APPLE__
#include <malloc.h>
#include <stdlib.h>
#endif

#include "Audio.h"

#include <cmath>
#include <fstream>
#include <iostream>

#include <math.h>
#include <gsl/gsl_wavelet.h>

class Stwt
{
	public:
	    /// default constructor.
		Stwt(const Audio& rAudio, int WindowSize, int FeedRate, int J, std::string nm);
		/// destructor.
	    ~Stwt();
	    /// short time wavelet transformation for each window is stored here (definition: mSpectrogramm[NoOfWindows][FwtLen]).
	    Fw32f** mSpectrogramm;
	    ///
	    int mFwtLen;
	    ///
	    int mNoOfWindows;
	    /// J-Level DWT
	    int mJ;
	    /// DWT name
	    std::string mNm;
	    /**
	     *
	     * @param rAudio
	     * @param WindowSize
	     * @param FeedRate
	     * @return
	     */
	    int CalcStwt(const Audio& rAudio, int WindowSize, int FeedRate); // calc stwt from audio file
	    /**
	     *
	     * @param w
	     * @param a
	     * @param stride
	     * @param n
	     * @param dir
	     * @param work
	     */
	    static void dwt_step(const gsl_wavelet * w, double *a, size_t stride, size_t n, gsl_wavelet_direction dir, gsl_wavelet_workspace * work);
	private:
	    /**
	     *
	     * @param pInAudio
	     * @param pWindowedAudio
	     * @param pHamming
	     * @param FwtLen
	     * @param WindowSize
	     */
	    void CopyConvertAndMultiply(float* pInAudio, double* pWindowedAudio, double* pHamming, int FwtLen, int WindowSize);
};

#endif /* STWT_H_ */
