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
    
    int vadThreshold;
    int windowSize;
    int stepSize;
    int hiCut;
    int loCut;
    int energyThreshold;
    int ipLength;
    char ipAddress[17];
    int port;
    int declickerThreshold;
    int preEmphasizeFactor;
    int maxHashLen;
    int mfccCoeffs;
    int melCoeffs;
}Parameter;


int parseConfig(const char* filename, Parameter *pParam);

#endif
