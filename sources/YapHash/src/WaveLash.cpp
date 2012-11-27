/**
 * @file	WaveLash.cpp
 * @date	Nov 6, 2012
 * @author  Julian Strobl
 * @brief	
 */

#include "WaveLash.h"

using namespace std;

#define BIT_DEPTH 5

// convenience constructor
WaveLash::WaveLash(const Audio& rAudio, Parameter* pParam) :
		index(0), mIndexLen(0)
{
	mHashLen = (unsigned int) getNoOfWindows(rAudio.length(), pParam->windowSize, pParam->stepSize) - 1;
	mHash = (unsigned long*) malloc(sizeof(unsigned long) * mHashLen);

	this->CalcHash(rAudio, pParam);
}

WaveLash::~WaveLash()
{
	if (index)
		free(index);
}

void WaveLash::CalcHash(const Audio& rAudio, Parameter* pParam)
{
	// calc stwt
	Stwt stwt = Stwt(rAudio, pParam->windowSize, pParam->stepSize);

	if (pParam->debugLevel > 2)
	{
		debugStwtToCSV("debugStwt.csv", &stwt);
		cout << "<INFO> wrote STWT coefficients to file debugStwt.csv" << endl;
	}

	// get energy of windows
	float *e = (float *) malloc(stwt.mNoOfWindows * sizeof(float));

	EnergyInWindows(e, rAudio.samples(), rAudio.length(), pParam->windowSize, pParam->stepSize);

	Fw32f** variance = new Fw32f *[stwt.mNoOfWindows];
	for (int i = 0; i < stwt.mNoOfWindows; i++)
		variance[i] = new Fw32f[BIT_DEPTH + 1];

	CalculateVariance(&variance, stwt);

	bool** F = (bool**) calloc(stwt.mNoOfWindows - 1, sizeof(bool*));
	for (int i = 0; i < stwt.mNoOfWindows - 1; i++)
		F[i] = (bool*) calloc(stwt.mJ, sizeof(bool));

	for (int i = 0; i < stwt.mNoOfWindows - 1; i++)
	{
		for (int j = 0; j < stwt.mJ; j++)
		{
			if (variance[i][j] - variance[i][j + 1] - (variance[i + 1][j] - variance[i + 1][j + 1]) > 0)
				F[i][j] = 1;
			else
				F[i][j] = 0;
		}
	}

	if (variance)
	{
		for (int j = 0; j < stwt.mNoOfWindows; j++)
			delete[] variance[j];
		delete[] variance;
	}

	index = (unsigned long*) calloc(2 * (stwt.mNoOfWindows - 1), sizeof(unsigned long)); // index: [position, hash]
	if (!index)
	{
		cerr << "<ERROR> Memory allocation for 'mIndex' failed!" << endl;
		return;
	}

	// only energy-rich windows
	unsigned int k = 0;
	unsigned long a = 0;
	for (int i = 0; i < stwt.mNoOfWindows - 1; i++)
	{
		if (e[i] > (float) (pParam->energyThreshold / 500.0))
		{
			a = 0;

			for (int j = 0; j < stwt.mJ; j++)
				a |= F[i][j] << (stwt.mJ - j - 1);

			index[2 * k + 0] = i + 1; // position
			index[2 * k + 1] = a;// value
			k++;
		}
	}

	mIndexLen = k;

	if (F)
	{
		for (int j = 0; j < stwt.mNoOfWindows - 1; j++)
			free(F[j]);
		free(F);
	}

	free(e);
}

void WaveLash::CalculateVariance(Fw32f ***result, Stwt &stwt)
{
	int NumCoeff = 0;

	int k1 = 0; // counter for mean value
	int k2 = 0; // counter for variance

	Fw32f mean = 0.0;
	Fw32f temp = 0.0;

	for (int h = 0; h < stwt.mNoOfWindows; h++)
	{
		k1 = 0;
		k2 = 0;

		for (int i = 0; i < stwt.mJ + 1; i++)
		{
			mean = 0.0;
			temp = 0.0;

			// first two layer have the same size, e.g. 4096 coefficients
			// result with 5-levels transform in layer sizes:
			// 128, 128, 256, 512, 1024, 2048
			if (i <= 1)
				NumCoeff = (int)(stwt.mFwtLen / pow(2.0,(double)(stwt.mJ)));
			else
				NumCoeff = (int)(stwt.mFwtLen / pow(2.0,(double)(stwt.mJ - i + 1)));

			// mean value
			for (int j = 0; j < NumCoeff; j++)
			{
				mean += stwt.mSpectrogramm[h][k1];
				k1++;
			}
			mean /= (NumCoeff);

			// variance
			for (int j = 0; j < NumCoeff; j++)
			{
				temp += (stwt.mSpectrogramm[h][k2] - mean) * (stwt.mSpectrogramm[h][k2] - mean);
				k2++;
			}
			temp /= (NumCoeff);

			(*result)[h][i] = temp;

//			cout << NumCoeff << ", " << k2 << endl;
		}
//		exit(0);
	}
}
