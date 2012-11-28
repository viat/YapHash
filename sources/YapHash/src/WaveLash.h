/**
 * @file	WaveLash.h
 * @date	Nov 6, 2012
 * @author  Julian Strobl
 * @brief	
 */

#ifndef WAVELASH_H_
#define WAVELASH_H_

#ifndef __APPLE__
#include <malloc.h>
#include <stdlib.h>
#endif

#include "fwBase.h"
#include "fwSignal.h"
#include "wavelet2s.h"

#include "parseConfig.h"
#include "Array2d_32f.h"
#include "Audio.h"
#include "Stwt.h"
#include "melFB.h"
#include "VAD.h"
#include "VIATUtilities.h"

#include <iostream>

/**
 * Wavelet Hash.
 */
class WaveLash
{
	public:
		/**
		 *
		 * @param rAudio
		 * @param pParam
		 */
		WaveLash(const Audio& rAudio, Parameter* pParam);
		/**
		 *
		 */
		~WaveLash();
		///
		unsigned long* index;
		/**
		 *
		 * @return
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
};

#endif /* WAVELASH_H_ */
