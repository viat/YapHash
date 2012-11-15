/**
 * @file		melFB.h
 * @date		Mar 30, 2011
 * @author  	Gary Grutzek
 * @brief		Mel filter bank
 * @details		Mel filter bank,
 * 	   			logarithmic filterbank, mel-style but without linear spacing,
 * 	   			log spacing from lowest to highest freq
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

#ifndef _MEL_FB_H_
#define _MEL_FB_H_

#include "Stft.h"

class MelFb{
    
public:
    
	/**
	 * Constructor
	 * @param fftSize size of the FFT, actually next power of 2 is used
	 * @param numFilterBanks number of bands for the mel filter bank
	 * @param locut lowest frequency of filter bank
	 * @param hicut hightest frequency of filterbank
	 */
	MelFb(int fftSize, int numFilterBanks, int locut, int hicut);
    
	/**
	 * Destructor
	 */
	~MelFb();
    
	/**
	 * Calculates Mel filter bank with parameters given in constructor.
	 * Only needs to be calculated once.
	 */
	void calcMelFB();
    
	/**
	 * multiplies a given spectrogramm with mel filter bank
	 * @param output the spectrogram multiplied with the mel filter bank
	 * @param stft input object, the spectrogram and its length
	 */
	void applyMelFB(Fw32f **output, const Stft& stft);
    
	// TODO: getter methoden
	Fw32f **fbank;
    
	int fbSize;
	int numFilterBanks;
	int loCut;
	int hiCut;
    
private:
	Fw32f *fLo;
	Fw32f *fHi;
    
	/**
	 * helper tool to calculate linear value from "logarithmic" mel value
	 * @param lin linear input
	 * @return mel value
	 */
	Fw32f linToMel(Fw32f lin);
	/**
	 * helper tool to calculate "logarithmic" mel value from linear value
	 * @param mel input
	 * @return linear value
	 */
	Fw32f melToLin(Fw32f mel);
    
};


#endif
