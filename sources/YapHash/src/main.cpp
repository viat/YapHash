/* 
 main.c 
 YapHash - Yet Another Perceptual Hash
 An audio fingerprinting system for speech content
 
 Copyright (c) 2012 Gary Grutzek
 Cologne University of Applied Sciences
 
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>

#ifndef __APPLE__
#include <malloc.h>
#include <stdlib.h>
#endif

#include "Audio.h"
#include "melFB.h"  		// Mel-Filterbank
#include "YapHash.h"
#include "parseConfig.h"	// parse config file
#include "VIATUtilities.h"	// some helper functions



#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

// TODO: debug level as parameter?
// Debug Level > 0 = timestamp
//             > 2 = write to .csv
#define DEBUG_LEVEL 1


using namespace std;  

int main(int argc, const char * argv[]) {
	//  ippStaticInit();
    
	// check for input arguments
	if (argc < 3) {
		fprintf(
				stderr,
				"usage: %s <config file> <input wave file> <output csv filename (optional)>\n",
				argv[0]);
		return -1;
	}
    
    try {
		Parameter param = { 0 };
		if(parseConfig(argv[1], &param)){
            cout << "Config Error" << endl;
            return -1;
        }
        
        // new audio object
        Audio *audio = new Audio(argv[2], param.vadThreshold, param.declickerThreshold, param.preEmphasizeFactor);
        
        // create mel Filterbank
        MelFb *melBank = new MelFb(param.windowSize, param.melCoeffs+1, param.loCut, param.hiCut);

#if DEBUG_LEVEL > 0
        Fw64u timeStamp1;
        timeStamp1  = fwGetCpuClocks();
#endif
        
        // calculate the hashvalues
        YapHash *pHash = new YapHash(*audio, *melBank, &param);
                
#if DEBUG_LEVEL > 0
        Fw64u timeStamp2 = fwGetCpuClocks();// get timestamp
        cout << (timeStamp2 - timeStamp1)/(2.4*1E9) << endl;
#endif
        
        
        // write to file
        int len = MIN(pHash->length(), param.maxHashLen); // a maximum of 100 hashvalues should be sufficient
        
		if (argc > 3) {
				writeIndexToCSV(argv[3], pHash->index, len); // write to csv with given name
                cout << "Wrote Hash vecors to file " << argv[3] << endl;
		} else // write to csv with audio filename + .csv
			writeIndexToCSV(argv[2], pHash->index, len);
            
		// free memory
		free(pHash);
        
	} catch (const char* err) {
		cout << "Exception: " << err << endl;
		return -1;
	}
    
    
	return 0;
}


