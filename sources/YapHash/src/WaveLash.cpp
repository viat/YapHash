/**
 * @file	WaveLash.cpp
 * @date	Nov 6, 2012
 * @author  Julian Strobl
 * @brief	
 *              changed CalculateVariance, added debug knospe 2013
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

#include "WaveLash.h"

using namespace std;

WaveLash::WaveLash(const Audio& rAudio, Parameter* pParam) :
		index(0), mIndexLen(0), mFactor(pParam->factor), mStep((int)pow(2.0,(double)(pParam->factor - 1)))
{
	this->CalcHash(rAudio, pParam);
}

WaveLash::~WaveLash()
{
	if (index)
		free(index);
}

void WaveLash::CalcHash(const Audio& rAudio, Parameter* pParam)
{
	int HashBitLength = 0;

	// calc stwt
	Stwt stwt = Stwt(rAudio, pParam->windowSize, pParam->stepSize, pParam->J, pParam->nm, pParam->member, pParam->debugLevel);

	if (pParam->debugLevel > 2)
	{
		debugStwtToCSV("debugStwt.csv", &stwt);
		cout << "<INFO> wrote STWT coefficients to file debugStwt.csv" << endl;
	}

    
	HashBitLength = mStep * (stwt.mJ + 1);

    if (pParam->debugLevel > 2)
	{
				cout << "<INFO> HashBitLength=" << HashBitLength << endl;
	}
    
	// get energy of windows
	float *e = (float *) calloc(stwt.mNoOfWindows, sizeof(float));

	EnergyInWindows(e, rAudio.samples(), rAudio.length(), pParam->windowSize, pParam->stepSize);

	// VARIANCE
	Fw32f** variance = new Fw32f *[stwt.mNoOfWindows];
	for (int i = 0; i < stwt.mNoOfWindows; i++)
		variance[i] = new Fw32f[HashBitLength];

	CalculateVariance(&variance, stwt);

	if (pParam->debugLevel > 2)
	{
		std::ofstream csvFile;
	    csvFile.open("debugVariance.csv");
        for (int i = 0; i < stwt.mNoOfWindows; i++)
        {
        	for (int j = 0; j < HashBitLength; j++)
        	{
        		csvFile << variance[i][j] << ",";
	        }
        	csvFile << std::endl;
	    }
        csvFile.close();
		cout << "<INFO> Wrote variance of STWT coefficients to file debugVariance.csv" << endl;
	}

	// ZEROCROSSINGRATE
	Fw32f* zeroCrossingRate = new Fw32f[stwt.mNoOfWindows];

	CalculateZeroCrossingRate(&zeroCrossingRate, stwt, pParam->debugLevel);

	if (pParam->debugLevel > 2)
	{
		std::ofstream csvFile;
	    csvFile.open("debugZeroCrossingRate.csv");
        for (int i = 0; i < stwt.mNoOfWindows; i++)
        {
       		csvFile << zeroCrossingRate[i] << ",";
	    }
        csvFile << std::endl;
        csvFile.close();
		cout << "<INFO> Wrote zero crossing rate to file debugZeroCrossingRate.csv" << endl;
	}

	bool** F = (bool**) calloc(stwt.mNoOfWindows - 1, sizeof(bool*));
	for (int i = 0; i < stwt.mNoOfWindows - 1; i++)
		F[i] = (bool*) calloc(HashBitLength, sizeof(bool));

	for (int i = 0; i < stwt.mNoOfWindows - 1; i++)
	{
		// variance
		for (int j = 0; j < HashBitLength - 1; j++)
		{
			if ((variance[i][j] - variance[i][j + 1] - (variance[i + 1][j] - variance[i + 1][j + 1])) > 0)
				F[i][j] = 1;
			else
				F[i][j] = 0;
		}

		// zerocrossingrate
		F[i][HashBitLength - 1] = zeroCrossingRate[i];
	}

	if (pParam->debugLevel > 2)
	{
		std::ofstream csvFile;
	    csvFile.open("debugF.csv");
        for (int i = 0; i < stwt.mNoOfWindows - 1; i++)
        {
        	for (int j = 0; j < HashBitLength; j++)
        	{
        		csvFile << F[i][j] << ",";
	        }
        	csvFile << std::endl;
	    }
        csvFile.close();
		cout << "<INFO> wrote binary hash matrix to file debugF.csv" << endl;
	}

	if (variance)
	{
		for (int j = 0; j < stwt.mNoOfWindows; j++)
			delete[] variance[j];
		delete[] variance;
	}

	if (zeroCrossingRate)
	{
		delete[] zeroCrossingRate;
	}

	index = (unsigned long*) calloc(2 * (stwt.mNoOfWindows - 1), sizeof(unsigned long)); // index: [position, hash]
	if (!index)
	{
		cerr << "<ERROR> Memory allocation for 'index' failed!" << endl;
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

			for (int j = 0; j < HashBitLength; j++)
				a |= (unsigned long)F[i][j] << (HashBitLength - j - 1);

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

	int c = 0;
	int k = 0; // counter for variance
    int km = 0; // counter for mean

    Fw32f meantotal = 0.0;
	Fw32f mean = 0.0;
	Fw32f temp = 0.0;

	// mean value
	// mean = 0.0;
	for (int z = 0; z < stwt.mNoOfWindows; z++)
	{
		for (int j = 0; j < stwt.mFwtLen; j++)
		{
			meantotal += stwt.mSpectrogramm[z][j];
		}
	}
	meantotal /= (stwt.mNoOfWindows * stwt.mFwtLen);
    
    // cout << "meantotal= "<< meantotal << endl;

	for (int h = 0; h < stwt.mNoOfWindows; h++)
	{
		c = 0;
		k = 0;
        km = 0;

		for (int i = 0; i <  mStep * (stwt.mJ + 1); i++)
		{
			// first two layer have the same size, e.g. 4096 coefficients
			// result with 5-levels transform in layer sizes:
			// 128, 128, 256, 512, 1024, 2048
            
            if (i < (int)pow(2.0,(double)(mFactor)))
			{
				NumCoeff = (int)(stwt.mFwtLen / pow(2.0,(double)(stwt.mJ)) / mStep);
			}
			else
			{
				if (!(i % mStep))
					c++;
                
				NumCoeff = (int)(stwt.mFwtLen / pow(2.0,(double)(stwt.mJ - c)) / mStep);
			}
            
			// mean
			temp = 0.0;
			for (int j = 0; j < NumCoeff; j++)
			{
				temp += stwt.mSpectrogramm[h][k];
				km++;
			}
			mean = temp / (NumCoeff);
            
			

			// variance
			temp = 0.0;
			for (int j = 0; j < NumCoeff; j++)
			{
				temp += (stwt.mSpectrogramm[h][k] - mean) * (stwt.mSpectrogramm[h][k] - mean);
				k++;
			}
			temp /= (NumCoeff);
 //           cout << "v= " << temp << endl;

			(*result)[h][i] = temp;

	//		cout << i << ", " << NumCoeff << ", " << k << endl;
		}
 //       exit(0);
	}
}

void WaveLash::CalculateZeroCrossingRate(Fw32f **result, Stwt &stwt, int debugLevel)
{
	int a1 = 0;
	int a2 = 0;
	int NumLowPassCoeff = stwt.mFwtLen/(int)pow(2.0,(double)stwt.mJ);
    if (debugLevel > 2)
	{
      cout << "<INFO> NumLowPassCoeff=" << NumLowPassCoeff << endl;
    }
	Fw32f zcr_mean = 0.0;
	Fw32f temp = 0.0;

	// mean value
	zcr_mean = 0.0;
	for (int z = 0; z < stwt.mNoOfWindows; z++)
	{
		for (int j = 1; j < NumLowPassCoeff; j++)
		{
			if (stwt.mSpectrogramm[z][j] >= 0)
				a1 = 1;
			else
				a1 = 0;

			if (stwt.mSpectrogramm[z][j - 1] >= 0)
				a2 = 1;
			else
				a2 = 0;

			zcr_mean += abs(a1 - a2);
		}
       
	}
	
    
    zcr_mean /= (stwt.mNoOfWindows);
    if (debugLevel > 2)
    {
        cout << "<INFO> Average No of STWT Zero Crossings=" << zcr_mean << endl;
    }
    
	// zero crossing rate
	for (int z = 0; z < stwt.mNoOfWindows; z++)
	{
		temp = 0.0;
	//	for (int j = 1; j < stwt.mFwtLen/NumLowPassCoeff ; j++) // pow(2.0,(double)stwt.mJ + 3) ??? modified knospe
        for (int j = 1; j < NumLowPassCoeff ; j++) 
		{
			if (stwt.mSpectrogramm[z][j] >= 0)
				a1 = 1;
			else
				a1 = 0;

			if (stwt.mSpectrogramm[z][j - 1] >= 0)
				a2 = 1;
			else
				a2 = 0;

			temp += abs(a1 - a2);

//			cout << j << ", " << temp << ", " << zcr_mean << endl;
		}
//		exit(0);
        

		if ((temp - zcr_mean) > 0)
			(*result)[z] = 1;
		else
			(*result)[z] = 0;
	}
}
