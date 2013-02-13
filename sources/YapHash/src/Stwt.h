/**
 * @file		Stwt.h
 * @date		Nov 6, 2012
 * @author  	Julian Strobl
 * @brief		Short-Time Wavelet Transform.
 * @details		Calculates short time Wavelet transfrom + windowing stuff
 * 				using GSL - GNU Scientific Library v1.9
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
#include <stdio.h>


#include <math.h>
#include <gsl/gsl_wavelet.h>



class Stwt
{
	public:
	    /// default constructor.
		Stwt(const Audio& rAudio, int WindowSize, int FeedRate, int J, std::string nm, size_t member, int debugLevel);
		/// destructor.
	    ~Stwt();
	    /// short time wavelet transformation for each window is stored here (definition: mSpectrogramm[NoOfWindows][FwtLen]).
	    Fw32f** mSpectrogramm;
	    /// $N=2^{\lceil\log_{2}(L)\rceil}$
	    int mFwtLen;
	    /// Number of frames
	    int mNoOfWindows;
	    /// J-Level DWT
	    int mJ;
	    /// DWT name
	    std::string mNm;
	    /// Specific member of the wavelet family
	    size_t mMember;
        /// debug level
        int mdebugLevel;
	    /**
	     *
	     * @param rAudio audio material.
	     * @param WindowSize window size.
	     * @param FeedRate step.
	     * @return 1, if everything went fine. 0 otherwise.
	     */
	    int CalcStwt(const Audio& rAudio, int WindowSize, int FeedRate); // calc stwt from audio file
	    /**
	     * One DWT step directly taken from GSL v1.9.
	     * @param w the actual wavelet: gsl_wavelet_alloc.
	     * @param a input and output at the same time.
	     * @param stride 1
	     * @param n basically gives where the approximation layer is and so which coefficients have to be transformed, e.g. for input length = 4096: step 1: z=4096, 2: z=2048, 3: 1024 and so on.
	     * @param dir direction forwards or backwards (inverse).
	     * @param work workspace: temporary memory to convert input to output.
	     */
	    static void dwt_step(const gsl_wavelet * w, double *a, size_t stride, size_t n, gsl_wavelet_direction dir, gsl_wavelet_workspace * work);
	private:
	    /**
	     * Apply Hamming window to the audio material.
	     * @param pInAudio audio material.
	     * @param pWindowedAudio result.
	     * @param pHamming pre calculated Hamming window: window(n)=\left\{\begin{array}{ll}0.54-0.46\cdot\cos\left(\frac{2\pi n}{N-1}\right),&0\leq n\leq N-1\\0,&\text{else}\end{array}\right.
	     * @param FwtLen wavelet transform length.
	     * @param WindowSize window size.
	     */
	    void CopyConvertAndMultiply(float* pInAudio, double* pWindowedAudio, double* pHamming, int FwtLen, int WindowSize);
};

#endif /* STWT_H_ */
