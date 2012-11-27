/**
 * @file	Stwt.cpp
 * @date	Nov 6, 2012
 * @author  Julian Strobl
 * @brief	
 */

#include "Stwt.h"

Stwt::Stwt(const Audio& rAudio, int WindowSize, int FeedRate) :
		mSpectrogramm(NULL), mFwtLen(0), mNoOfWindows(0), mJ(5), mNm("db4")
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
	int NumLowPassCoeff = 0;

	// calc fwt length => next power of 2
	FwtOrder = ceil(logf(WindowSize) / logf(2.0f));
	mFwtLen = 1 << FwtOrder;

	NumLowPassCoeff = (int)(mFwtLen / pow(2.0,(double)mJ));

	// alloc multidimensional array
	mSpectrogramm = new Fw32f *[mNoOfWindows]; // alloc some pointers ...
	for (int i = 0; i < mNoOfWindows; i++)
		mSpectrogramm[i] = new Fw32f[mFwtLen]; // ... and alloc an array for each pointer

	// number of stages
	vector<double> sig, dwt_output, flag;
	vector<int> length;

	// allocate FrameBuffer for real audio data of each window
	double* FrameBuffer = (double*) malloc(mFwtLen * sizeof(double));

	// pre-calc Hamming window
	double* Hamming = (double*) malloc(WindowSize * sizeof(double));
	for (int i = 0; i < WindowSize; i++)
		Hamming[i] = 1 * (0.54 - 0.46 * cos(2 * M_PI * i / WindowSize));

	// calc fwt for each window
	for (i = j = 0; i + mFwtLen < rAudio.length(); i += FeedRate, j++)
	{
		this->CopyConvertAndMultiply(&rAudio.samples()[i], FrameBuffer, Hamming, mFwtLen, WindowSize);

		sig.assign(FrameBuffer, FrameBuffer + mFwtLen);

//		ofstream dwtin("dwtin.txt", ofstream::app);
//		for (unsigned int z = 0; z < sig.size(); z++)
//			dwtin << sig[z] << ", ";
//		dwtin << endl;

		// perform J-Level DWT
		dwt(sig, mJ, mNm, dwt_output, flag, length);

//		ofstream dwtout("dwtout.txt", ofstream::app);
//		for (unsigned int z = 0; z < dwt_output.size(); z++)
//			dwtout << dwt_output[z] << ", ";
//		dwtout << endl;

		// ToDo: memcpy
		for (int a = 0; a < mFwtLen; a++)
			mSpectrogramm[j][a] = (Fw32f) dwt_output[a];

		sig.clear();
		dwt_output.clear();
	}

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
