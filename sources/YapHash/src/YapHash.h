/**
 * @file		YapHash.h
 * @date		Feb 11, 2012
 * @author  	Gary Grutzek
 * @brief		YapHash - Yet Another Perceptual Hash
 * @details		An audio fingerprinting system for speech content
 * 				- Hash is based on spectral and cepstral coefficients
 * 				- The differences (derivatives) in time and frequency direction are calculated
 * 				- the sign of this differences are mapped to 0 and 1
 * 				- the concatenated zeros and ones is the hash value
 *
 * @copyright  	Copyright (c) 2012 Gary Grutzek<br>
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

#ifndef ViatFeatureExtractor_yapHash_h
#define ViatFeatureExtractor_yapHash_h

#include "fwBase.h"
#include "fwSignal.h"
#include "parseConfig.h"
#include "Array2d_32f.h"
#include "Audio.h"
#include "Stft.h"
#include "melFB.h"
#include "VAD.h"

#include "VIATUtilities.h"



class YapHash {
    
public:
    YapHash(const Audio& wave, const MelFb& melFb, Parameter *pParam);
    ~YapHash();
    
    int length() const {return indexLen;}
    //    int* index() const {return index;}
    unsigned long *index;
    
private:
    int hashLen;
    unsigned long *hash;
    int indexLen;
    
    /**
     * calculates Hash from given audio samples
     * @param wave the audio object, containing mainly the samples
     * @param melFb the mel style filter bank object
     * @param pParam the parameter struct
     */
    void calcHash(const Audio& wave, MelFb melFb, Parameter *pParam);
    
    /**
     * binary to decimal value conversion
     * @param vector binary data
     * @param len length of vector
     * @return decimal value
     */
    Fw64u bin2Dec(Fw32f *vector, int len);
};

#endif
