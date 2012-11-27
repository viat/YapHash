/**
 * @file		parseConfig.h
 * @date		May 16, 2011
 * @author  	Gary Grutzek
 * @brief		Config file parser
 * @details		Config file parser
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
    int J;					// J-Level wavelet transform
    std::string nm;			// Name of wavelet, e.g. db4
    int factor;				// Bit-length: 2^(factor - 1) * J
}Parameter;

/**
 * Parses the configuration file.
 * @param configfile path and filename to configuration file
 * @param pParam Parameter struct
 * @return TRUE if parsing configuration file succeeded. FALSE if options missing or syntax error.
 */
int parseConfig(const char* filename, Parameter *pParam);

#endif
