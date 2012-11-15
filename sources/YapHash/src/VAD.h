/**
 * @file		VAD.h
 * @date		Oct 12, 2010
 * @author  	Gary Grutzek
 * @brief		Voice Activity Dectection
 * @details		Some voice activity dectection algorithms
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


#ifndef _VAD_H_
#define _VAD_H_

#include "fwSignal.h"

/**
 * calculate energy of each frame and writes energy vector to first arg
 * @param energy calculated energy in windows
 * @param data input audio data
 * @param dataLen number of audio samples
 * @param windowSize size of windows in samples
 * @param stepSize size of steps in samples
 */
void EnergyInWindows(float *energy,
                     float *data,
                     unsigned int dataLen,
                     int windowSize,
                     int stepSize);

/**
 * calc energy with fixed window size
 * @param data input audio data
 * @param dataLen number of audio samples
 * @param energy calculated energy in windows
 */
void Energy(double *data, unsigned int dataLen, float *energy);

/**
 * Voice activity detection
 * @param data input audio data
 * @param dataLen number of audio samples
 * @param threshold energy threshold of audio
 * @return index of first window to use for processing
 */
int Vad(double *data, unsigned int dataLen, int threshold);

/**
 * Voice activity detection, in place operation. writes result to
 * input buffer and returns new length
 * @param data input audio data
 * @param dataLen number of audio samples
 * @param threshold energy threshold of audio
 * @return zero if no error
 */
int cutVad_I(double *data, int *dataLen, int threshold);

/**
 * Voice activity detection based on autocorrelation, inplace operation
 * @param data input audio data
 * @param dataLen number of audio samples
 * @param threshold energy threshold of audio
 * @return zero if no error
 */
int cutACFVad_I(Fw32f *data, int *dataLen, int threshold);

/**
 * Voice activity detection based on autocorrelation
 * @param data input audio data
 * @param dataLen number of audio samples
 * @param threshold energy threshold of audio
 * @return index of first window to use for processing
 */
int AutocorrelationVad(Fw32f *data, int dataLen, int threshold);


#endif
