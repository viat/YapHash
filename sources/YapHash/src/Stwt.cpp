/**
 * @file	Stwt.cpp
 * @date	Nov 6, 2012
 * @author  Julian Strobl
 * @brief	
 *              added debug knospe 2013
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


#include "Stwt.h"



// directly from gsl
#define ELEMENT(a,stride,i) ((a)[(stride)*(i)])

Stwt::Stwt(const Audio& rAudio, int WindowSize, int FeedRate, int J, std::string nm, size_t member, int debugLevel) :
		mSpectrogramm(NULL), mFwtLen(0), mNoOfWindows(0), mJ(J), mNm(nm), mMember(member), mdebugLevel(debugLevel)
{
	this->CalcStwt(rAudio, WindowSize, FeedRate);
}

Stwt::~Stwt()
{
	if (mSpectrogramm)
	{
		for (int j = 0; j < mNoOfWindows; j++)
			delete[] mSpectrogramm[j];
		delete[] mSpectrogramm;
	}
}

int Stwt::CalcStwt(const Audio& rAudio, int WindowSize, int FeedRate)
{
	// calculate dimension / num of columns
	mNoOfWindows = (rAudio.length() - (WindowSize - FeedRate)) / FeedRate;

	int FwtOrder;
	int i, j;

	// calc fwt length => next power of 2
	FwtOrder = ceil(logf(WindowSize) / logf(2.0f));
	mFwtLen = 1 << FwtOrder;
    
    if (mdebugLevel > 2)
	{
		
        std::cout << "<INFO> FwtLength=" << mFwtLen << std::endl;
        std::cout << "<INFO> NoOfWindows=" << mNoOfWindows << std::endl;

	}

	// alloc multidimensional array
	mSpectrogramm = new Fw32f *[mNoOfWindows]; // alloc some pointers ...
	for (int i = 0; i < mNoOfWindows; i++)
		mSpectrogramm[i] = new Fw32f[mFwtLen]; // ... and alloc an array for each pointer

	// allocate FrameBuffer for real audio data of each window
	double* FrameBuffer = (double*) malloc(mFwtLen * sizeof(double));

	// pre-calc Hamming window
	double* Hamming = (double*) malloc(WindowSize * sizeof(double));
	for (int i = 0; i < WindowSize; i++)
		Hamming[i] = 1 * (0.54 - 0.46 * cos(2 * M_PI * i / WindowSize));

	gsl_wavelet *w;
	gsl_wavelet_workspace *work;

	const gsl_wavelet_type *nm;
	if (mNm.compare(std::string("gsl_wavelet_daubechies")) == 0)
		nm = gsl_wavelet_daubechies;
	else if (mNm.compare(std::string("gsl_wavelet_haar")) == 0)
		nm = gsl_wavelet_haar;
	else if (mNm.compare(std::string("gsl_wavelet_bspline")) == 0)
		nm = gsl_wavelet_bspline;
	else
	{
		std::cerr << "<ERROR> wavelet name not found!" << std::endl;
		exit(-1);
	}

	w = gsl_wavelet_alloc(nm, mMember);
	work = gsl_wavelet_workspace_alloc(mFwtLen);
    
    
	// calc fwt for each window j
	for (i = j = 0; i + mFwtLen < rAudio.length(); i += FeedRate, j++)
	{
		this->CopyConvertAndMultiply(&rAudio.samples()[i], FrameBuffer, Hamming, mFwtLen, WindowSize);
        
        if (mJ >0) {
		  for (int z = mFwtLen; z >= mFwtLen/(int)pow(2.0,(double)(mJ - 1)); z >>= 1) {
			 dwt_step(w, FrameBuffer, 1, z, gsl_wavelet_forward, work);
         
          }
        }
		for (int a = 0; a < mFwtLen; a++)
			mSpectrogramm[j][a] = (Fw32f) FrameBuffer[a];
	}

	gsl_wavelet_free(w);
	gsl_wavelet_workspace_free(work);

	free(FrameBuffer);
	free(Hamming);

	return 0;
}

// copy with padding (if fftLen > windowSize), multiply with vector (hammming-window) and convert to double
void Stwt::CopyConvertAndMultiply(float* pInAudio, double* pWindowedAudio, double* pHamming, int FwtLen, int WindowSize)
{
	for (int i = 0; i < FwtLen; i++)
	{
		if (i > WindowSize)
			pWindowedAudio[i] = 0;
		else
			pWindowedAudio[i] = pInAudio[i] * pHamming[i];
	}
}

// one step dwt from gnu scientifc library. you can't use this function directly from their library.
// they have a function, which makes as many dwt_steps as possible (e.g. N = 4096 -> J = 12 = ceil(logf(WindowSize) / logf(2.0f)))
// we want to decide ourselves how many step (resp. level) we make
void Stwt::dwt_step(const gsl_wavelet * w, double *a, size_t stride, size_t n, gsl_wavelet_direction dir, gsl_wavelet_workspace * work)
{
	double ai, ai1;
	size_t i, ii;
	size_t jf;
	size_t k;
	size_t n1, ni, nh, nmod;

	for (i = 0; i < work->n; i++)
	{
		work->scratch[i] = 0.0;
	}

	nmod = w->nc * n;
	nmod -= w->offset; /* center support */

	n1 = n - 1;
	nh = n >> 1;

	if (dir == gsl_wavelet_forward)
	{
		for (ii = 0, i = 0; i < n; i += 2, ii++)
		{
			ni = i + nmod;
			for (k = 0; k < w->nc; k++)
			{
				jf = n1 & (ni + k);
				work->scratch[ii] += w->h1[k] * ELEMENT (a, stride, jf);
				work->scratch[ii + nh] += w->g1[k] * ELEMENT (a, stride, jf);
			}
		}
	}
	else
	{
		for (ii = 0, i = 0; i < n; i += 2, ii++)
		{
			ai = ELEMENT (a, stride, ii);
			ai1 = ELEMENT (a, stride, ii + nh);
			ni = i + nmod;
			for (k = 0; k < w->nc; k++)
			{
				jf = (n1 & (ni + k));
				work->scratch[jf] += (w->h2[k] * ai + w->g2[k] * ai1);
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		ELEMENT (a, stride, i)= work->scratch[i];
	}
}
