//
//  @file main.cpp
//  @date June 16, 2012 
//  @brief Match - Compares two Fingerprints
//  @author Heiko Knospe
//  @copyright Copyright (c) 2012 Heiko Knospe <br>
/*  Cologne University of Applied Sciences


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
#include <errno.h>

#ifndef __APPLE__
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#endif

#include <fstream>
#include <iostream>


#define MAXFILELENGTH 1000
#define MAXTIME 500
#define DEBUG

int main (int argc, const char * argv[])
{
    FILE        *hash1 = NULL;
    FILE        *hash2 = NULL;
    unsigned int linenum1 = 0;
    unsigned int linenum2 = 0;
    int          time1[MAXFILELENGTH];
    unsigned long int     feature1[MAXFILELENGTH];
    int          time2[MAXFILELENGTH];
    unsigned long int     feature2[MAXFILELENGTH];
    char         line[256], string1[256], string2[256];
    int          tdiff, i, j, maxmatch,matchpos;
    int          cnt[2*MAXTIME+1];
    
    // check for input arguments
	if (argc < 2) {
		fprintf(
				stderr,
				"usage: %s <hash 1 csv file> <hash 2 csv file> \n",
				argv[0]);
		fprintf(stderr,
				"file interface: <hash 1> <hash 2> \n");
		
		return -1;
	}
    
    // open hash files
    
  
    if (!(hash1 = fopen(argv[1], "r"))) {
        fprintf(stderr, "<ERROR> %s: %s\n", argv[1], strerror(errno));
        return -1;
    }
    
    #ifdef DEBUG
        std::cout << "Hash 1 opened \n";
    #endif
    
    if (!(hash2 = fopen(argv[2], "r"))) {
        fprintf(stderr, "<ERROR> %s: %s\n", argv[2], strerror(errno));
        return -1;
    }
     #ifdef DEBUG
        std::cout << "Hash 2 opened \n";
     #endif
    
    // get hash 1 file
    while (fgets(line, 256, hash1) != NULL) {
     
        
        // skip comments and empty lines
        if (line[0] == '#' || line[0] == '\n' || (line[0] == '\r' && line[1] == '\n'))
            continue;
        
        
        linenum1++;
        
        // scan for option
        if (sscanf(line, "%[^','],%[^',']", string1, string2) != 2) {
            fprintf(stderr, "<ERROR> Syntax error in hash1 file, line %u\n", linenum1);
            return -1;
        }
        
        time1[linenum1] = atoi(string1);
        feature1[linenum1]=strtol(string2,NULL,0);

    }
    
    // close file
    fclose(hash1);
     #ifdef DEBUG
     std::cout << "Read " << linenum1 << " vectors of Hash 1. \n";
     #endif
    
    // get hash 2 file
    while (fgets(line, 256, hash2) != NULL) {
        
               
        // skip comments and empty lines
        if (line[0] == '#' || line[0] == '\n' || (line[0] == '\r' && line[1] == '\n'))
            continue;
        
        linenum2++;

        // scan for option
        if (sscanf(line, "%[^','],%[^',']", string1, string2) != 2) {
            fprintf(stderr, "<ERROR> Syntax error in hash1 file, line %u\n", linenum2);
            return -1;
        }
        
        time2[linenum2] = atoi(string1);
        feature2[linenum2]=strtol(string2,NULL,0);
        
    }
    
    // close configuration file
    fclose(hash2);

    #ifdef DEBUG
    std::cout << "Read " << linenum2 << " vectors of Hash 2. \n";
    #endif
    
    // prepare matching
        
    for(i=0; i<= 2*MAXTIME; i++) {
        cnt[i]=0;
    }
    
    // compare files
    
    for(i=1; i <= linenum1; i++) {
    
        for(j=1; j <= linenum2; j++) {
            
            if (feature1[i]==feature2[j]) {
                tdiff=time2[j]-time1[i]+MAXTIME;
                
                if (tdiff < 2*MAXTIME && tdiff >= 0) {
                    cnt[tdiff]++;       
                }
                else {
                    fprintf(stderr, "<ERROR> in time positions \n");
                    return -1;
                }
                            
            }
        }
    
    }
    
    // print results
    
    maxmatch = 0;
    matchpos = 0;
    for(i=-MAXTIME;i<=MAXTIME;i++) {
        if (cnt[i+MAXTIME] > 0) {
            #ifdef DEBUG
               std::cout << "Time Shift " << i << " matches= " << cnt[i+MAXTIME] << "\n";
            #endif  
            if (cnt[i+MAXTIME] > maxmatch) {
                maxmatch=cnt[i+MAXTIME];
                matchpos=i;
            }
                
        }
    }
    if (maxmatch > 0) {        
       std::cout << "*** \nTime Shift " << matchpos << " has maximum matches= " << cnt[matchpos+MAXTIME] << "\n";
    }
    else {
        std::cout << "*** \nSorry, no matches.\n";
    }
    return maxmatch;
}
