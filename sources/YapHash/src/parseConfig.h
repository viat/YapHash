//
//  parseConfig.h
//  ViatFeatureExtractor
//
//  Created by Gary Grutzek on 16.05.11.
//  Copyright 2011 FH Koeln. All rights reserved.
//

#ifndef _PARSE_CFG_H_
#define _PARSE_CFG_H_

#define CONFIG_ERROR -1

#include <string>
#include <string.h>

typedef struct Parameter{
    
    int samplerate;			// in Hz, only tested with 8000 Hz
    int vadThreshold;
    int windowSize;			// in samples
    int stepSize;			// in samples
    int hiCut;				// f in Hz
    int loCut;				// f in Hz
    int energyThreshold;
    int declickerThreshold;
    int preEmphasizeFactor;
    unsigned int maxHashLen; // number of tupels
    int maxAudioLen;        // in seconds
    int minAudioLen;        // in seconds
    int mfccCoeffs;
    int melCoeffs;
    int debugLevel;
    
}Parameter;


int parseConfig(const char* filename, Parameter *pParam);

#endif
