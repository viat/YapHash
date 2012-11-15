/**
 * @file		STFT.h
 * @date		Mar 30, 2011
 * @author  	Gary Grutzek
 * @brief		STFT Object
 * @details		Calculates short time Fourier transfrom + windowing stuff
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

#ifndef _STFT_H_
#define _STFT_H_

#include "fwBase.h"
#include "fwSignal.h"
#include "Audio.h"
//#include <complex.h>
#include <fftw3.h>

class Stft{
    
public:
    
    /**
     * Convenience constructor
     * @param audio the audio object
     * @param windowSize the size of the frames/windows in samples
     * @param feedRate the step size of the frames in samples
     */
	Stft(const Audio& audio, int windowSize, int feedRate);
    
	/**
	 * calc stft from audio file
	 * @param audio the audio object
	 * @param windowSize the size of the frames/windows in samples
	 * @param feedRate the step size of the frames in samples
	 * @return error
	 */
    int calcStft(const Audio &audio, int windowSize, int feedRate);
    
    // destructor
    ~Stft();
    
    Fw32f **spectrogramm;  // Short time fourier transformation
    int fftLen;
    int NoOfWindows;
    
private:
    
};

/**
 * Applies a Hamming window of given length, inplace operation!
 * @param data input overwritten by output data
 * @param length of window
 */
void WinHamming_I(double* data, int length);

/**
 * combine some functions for convenience and speedup
 * @param inAudio audio samples as 32 bit float	to be multriplied with hamming window
 * @param windowedAudio windowed audio samples
 * @param fftLen length of fft (next power of 2)
 * @param windowSize size of window
 */
void CopyWithHamming(float *inAudio, double* windowedAudio, int fftLen, int windowSize);

/**
 * combine some functions for convenience and speedup
 * @param inAudio
 * @param windowedAudio
 * @param hamming
 * @param fftLen
 * @param windowSize
 */
void CopyConvertAndMultiply(float *inAudio, double* windowedAudio, double* hamming, int fftLen, int windowSize);

/**
 * calculate power spectrum from spectrum
 * @param power_spectrum
 * @param spectrum
 * @param N size of full spectrum
 */
void PowerSpectrum(Fw32f* power_spectrum, fftw_complex* spectrum, int N);


#endif
