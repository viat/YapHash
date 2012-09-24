/**
 *  Audio.cpp
 *  VIAT Feature-Extraction Framework
 *
 *  Created by Gary Grutzek on 04.04.11.
 *  Copyright 2011 Fachhochschule Koeln. All rights reserved.
 *
 */


#ifndef _AUDIO_H_
#define _AUDIO_H_

#include "fwBase.h"
#include "fwSignal.h"
#include "Wave.h"

/**
 * In-place pre-emphasize audio
 */
void preEmphasize(Fw32f *samples, int len, Fw32f preemphasisFactor);

/*
 *   declicker to reduce spikes in audio data
 */
void deClicker(Fw32f *samples, int len, int threshold);


class Audio{
    
public:
    // Konstruktoren
    Audio(const char *filePath, int thresholdVAD, int thresholdDeclicker, int preEmphasizeFactor); // read wave file
    Audio(double *waveSamples, int waveLength); // get wavesamples of type double and convert to ipp32f
    
    // Destruktor
    ~Audio();
    
    // inline getters
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

