/**
 * @file		Audio.h
 * @date		April 04, 2011
 * @author  	Gary Grutzek
 * @brief		Audio Preprocessor
 * @details		Audio file reader and Preprocessor
 *  				- reads wavefile
 *  				- declicker
 *  				- preemphasize high frequencies
 *  				- normalize
 *  				- voice activity detection
 
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
#ifndef _AUDIO_H_
#define _AUDIO_H_

#include "fwBase.h"
#include "fwSignal.h"
#include "Wave.h"
#include "parseConfig.h"


void preEmphasize(Fw32f *samples, int len, Fw32f preemphasisFactor);

class Audio{
    
public:
    /**
     * convenience constructor: read wave file
     * @param filePath path to audio file
     * @param thresholdVAD threshold for voice activity detection
     * @param thresholdDeclicker threshold for declicker
     * @param preEmphasizeFactor factor to preamphasize high frequencies
     */
    Audio(const char *filePath, int thresholdVAD, int thresholdDeclicker, int preEmphasizeFactor);
    
    /**
     *  convenience constructor: get wavesamples of type double and convert to ipp32f
     * @param waveSamples wavesamples of type double
     * @param waveLength number of audiosamples
     */
    Audio(double *waveSamples, int waveLength);
    
    /**
     * convenience constructor: get wavesamples of type shortand convert to ipp32f
     * @param waveSamples wavesamples of type short (LPCM 16Bit, 8kHz)
     * @param waveLength number of audiosamples
     * @param param parameter struct
     */
    Audio(short *waveSamples, int waveLength, Parameter *param);// int samplerate, int thresholdVAD, int thresholdDeclicker, int preEmphasizeFactor);
    
    /**
     * Destruktord
     */
    ~Audio();
    
    double sampleRate() const {return fs;}
    int length() const {return len;}
    Fw32f* samples() const {return samples32f;}
    
private:
    Fw32f *samples32f; // pointer to samples
    int len; // number of samples
    //int ID;
    int fs;
};

#endif
