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

// energy with windowsize parameter
void EnergyInWindows(float *energy, 
                     float *data, 
                     unsigned int dataLen, 
                     int windowSize, 
                     int stepSize);

//void Windows(short *data, short windowSize, short stepSize);
void Energy(double *data, unsigned int dataLen, float *energy);

int Vad(double *data, unsigned int dataLen, int threshold);

int cutVad_I(double *data, int *dataLen, int threshold);

int cutACFVad_I(Fw32f *data, int *dataLen, int threshold);

int AutocorrelationVad(Fw32f *data, int dataLen, int threshold);


#endif
