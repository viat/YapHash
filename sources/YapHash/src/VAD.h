/*
 *  VAD.h
 *  Voice Activity Detection
 *
 *  Created by Gary Grutzek on 12.10.10.
 *  Copyright 2010 Fachhochschule Koeln. All rights reserved.
 *
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
