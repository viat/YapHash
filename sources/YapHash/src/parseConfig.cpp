/**
 * @file		parseConfig.cpp
 * @date		May 16, 2011
 * @author  	Gary Grutzek
 * @brief		Config file parser
 * @details		Config file parser
 *              allow mfccCoeff=0 for Haitsma Kalker Hash knospe 2013
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

#include "parseConfig.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fstream>
#include <iostream>


int parseConfig(const char *configfile, Parameter *pParam) {
    // test
    FILE        *conffile = NULL;
    unsigned int linenum = 0;
    char         line[256];
    char         optionname[256];
    char         optionvalue[256];
    
    // open configuration file
    if (!(conffile = fopen(configfile, "r"))) {
        fprintf(stderr, "parseConfig.cpp: <ERROR> %s: %s\n", configfile, strerror(errno));
        return CONFIG_ERROR;
    }
    
    // get configuration
    while (fgets(line, 256, conffile) != NULL) {
        
        linenum++;
        
        // skip comments and empty lines
        if (line[0] == '#' || line[0] == '\n' || (line[0] == '\r' && line[1] == '\n'))
            continue;
        
        // scan for option
        if (sscanf(line, "%s = %255[^\n]", optionname, optionvalue) != 2) {
            fprintf(stderr, "parseConfig.cpp: <ERROR> Syntax error in configuration file, line %u\n", linenum);
            return CONFIG_ERROR;
        }
        
        // parse option
        if (strcmp(optionname, "DEBUG_LEVEL") == 0)
			pParam->debugLevel = (unsigned int) atoi(optionvalue);
		
        else if (strcmp(optionname, "WINDOWSIZE") == 0)
			pParam->windowSize = (unsigned int) atoi(optionvalue);
        
		else if (strcmp(optionname, "STEPSIZE") == 0)
			pParam->stepSize = (unsigned int) atoi(optionvalue);
        
		else if (strcmp(optionname, "SAMPLERATE") == 0)
			pParam->samplerate = (unsigned int) atoi(optionvalue);
        
		else if (strcmp(optionname, "HICUT") == 0)
			pParam->hiCut = (unsigned int) atoi(optionvalue);
        
		else if (strcmp(optionname, "LOCUT") == 0)
			pParam->loCut = (unsigned int) atoi(optionvalue);
        
		else if (strcmp(optionname, "ENERGY_THRESHOLD") == 0)
			pParam->energyThreshold = (unsigned int) atoi(optionvalue);
        
		else if (strcmp(optionname, "VAD_THRESHOLD") == 0)
			pParam->vadThreshold = (unsigned int) atoi(optionvalue);
        
		else if (strcmp(optionname, "POSTPRO_THRESHOLD") == 0)
			pParam->energyThreshold = (unsigned int) atoi(optionvalue);
        
		else if (strcmp(optionname, "DECLICKER_THRESHOLD") == 0)
			pParam->declickerThreshold = (unsigned int) atoi(optionvalue);
        
		else if (strcmp(optionname, "PREEMPHASIZE_FACTOR") == 0)
			pParam->preEmphasizeFactor = (unsigned int) atoi(optionvalue);
        
		else if (strcmp(optionname, "MAX_HASH_LEN") == 0)
			pParam->maxHashLen = (unsigned int) atoi(optionvalue);
        
		else if (strcmp(optionname, "MAX_AUDIO_LEN") == 0)
			pParam->maxAudioLen = (unsigned int) atoi(optionvalue);
        
		else if (strcmp(optionname, "MIN_AUDIO_LEN") == 0)
			pParam->minAudioLen = (unsigned int) atoi(optionvalue);
        
		else if (strcmp(optionname, "NUMBER_OF_MEL_COEFF") == 0)
			pParam->melCoeffs = (unsigned int) atoi(optionvalue);
        
		else if (strcmp(optionname, "NUMBER_OF_MFCC") == 0)
			pParam->mfccCoeffs = (unsigned int) atoi(optionvalue);

		else if (strcmp(optionname, "NM") == 0)
			pParam->nm = std::string(optionvalue);

		else if (strcmp(optionname, "MEMBER") == 0)
			pParam->member = (size_t) atoi(optionvalue);

		else if (strcmp(optionname, "J") == 0)
			pParam->J = (unsigned int) atoi(optionvalue);

		else if (strcmp(optionname, "FACTOR") == 0)
			pParam->factor = (unsigned int) atoi(optionvalue);
    }
    
    // close configuration file
    fclose(conffile);
    
    if (!( pParam->windowSize && pParam->stepSize && pParam->declickerThreshold
          && pParam->energyThreshold && pParam->hiCut  && pParam->loCut && pParam->maxAudioLen 
          && pParam->maxHashLen && pParam->melCoeffs && pParam->minAudioLen 
          && pParam->samplerate && pParam->vadThreshold && pParam->member>0 && pParam->J && pParam->factor))
		return CONFIG_ERROR;

    // TODO: check for missing options
    
    // return
    return 0;
    
}
