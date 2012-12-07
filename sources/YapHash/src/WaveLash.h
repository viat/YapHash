/**
 * @file		WaveLash.h
 * @date		Nov 6, 2012
 * @author  	Julian Strobl
 * @brief		WaveLash - Wavelet Audio Hash
 * @details		An audio fingerprinting system for speech content
 * 				- Hash is based on wavelet coefficients
 * 				- The variances are calculated
 * 				- The sign of these variances are mapped to 0 and 1
 * 				- One bit for zero crossing rate of the low pass (approximation layer)
 * 				- The concatenated zeros and ones is the hash value
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

#ifndef WAVELASH_H_
#define WAVELASH_H_

#ifndef __APPLE__
#include <malloc.h>
#include <stdlib.h>
#endif

#include "fwBase.h"
#include "fwSignal.h"

#include "parseConfig.h"
#include "Array2d_32f.h"
#include "Audio.h"
#include "Stwt.h"
#include "melFB.h"
#include "VAD.h"
#include "VIATUtilities.h"

#include <iostream>

/**
 * Wavelet Audio Hash.
 */
class WaveLash
{
	public:
		/**
		 * default constructor.
		 * @param rAudio audio material.
		 * @param pParam parameter from configuration file.
		 */
		WaveLash(const Audio& rAudio, Parameter* pParam);
		/**
		 * destructor.
		 */
		~WaveLash();
		/// an array with tuple of (position, feature). is actually the where the resulting hash is stored.
		unsigned long* index;
		/**
		 * length of the resulting hash.
		 * @return length.
		 */
		unsigned int length() const
		{
			return mIndexLen;
		}
	private:
		///
		unsigned int mHashLen;
		///
		unsigned int mIndexLen;
		///
		unsigned long* mHash;
		///
		int mFactor;
		///
		int mStep;
		/**
		 *
		 * @param rAudio
		 * @param pParam
		 */
		void CalcHash(const Audio& rAudio, Parameter* pParam);
		/**
		 *
		 * @param result
		 * @param stwt
		 */
		void CalculateVariance(Fw32f ***result, Stwt &stwt);
		/**
		 *
		 * @param result
		 * @param stwt
		 */
		void CalculateZeroCrossingRate(Fw32f **result, Stwt &stwt);
};

#endif /* WAVELASH_H_ */
