/**
 * @file		Wave.cpp
 * @date		Sep 08, 2010
 * @author  	Gary Grutzek
 * @brief		Wave file reader and writer
 * @details		supports only well-formated mono PCM Wave files no tagging,
 * 				just plain 44-Byte header!
 *
 *				08.09.10. start from scratch
 *   			29.07.11  support for a few subchunks before 'data' subchunk
 *   			01.08.11  fix: reads subchunk1size correctly
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

#include "Wave.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ReadWav(const char *path, struct waveFile *ptrWav)
{
	FILE *fid; 
	fid = fopen(path,"r");
	
	if (fid == NULL)
	{
		printf("couldn't open file!\n");
		return EXIT_FAILURE;
	}
	else
	{
		fread(ptrWav->chunkID, 1, 4, fid);		// read 4 chars  // -> same as *(ptrWav).chunkID
		fread(&ptrWav->fileLength, 4, 1, fid);	// read 1 uint32_t
		fread(ptrWav->typeID, 1, 4, fid);		// read 4 chars
		
		// read Subchunk 1 -> Format
		fread(ptrWav->subchunk1ID, 1, 4, fid);	// read 4 chars
		fread(&ptrWav->subchunk1Size, 1, 4, fid); // read 4 Bytes
        fread(&ptrWav->audioFormat, 1, ptrWav->subchunk1Size, fid); // read next Bytes til subchunk 2
        // goto subchunk 2
        //fseek(fid, ptrWav->subchunk1Size, SEEK_CUR);
        
		if (ptrWav->audioFormat != 1){
			printf("no PCM file!\n");
			return EXIT_FAILURE; // no PCM
		}
		if (ptrWav->noOfChannels != 1){
			printf("only mono supported!\n");
			return EXIT_FAILURE; // no mono
		}		
		//read subchunk 2 -> data
		fread(ptrWav->subchunk2ID, 1, 4, fid);
		fread(&ptrWav->subchunk2Size, 4, 1, fid);
		if (ptrWav->subchunk2Size > ptrWav->fileLength) {
			
            printf("unknown file error!\n");
			return EXIT_FAILURE;
		}	
        
        // check if this subchunk is equal to "data" (or the next 2)
        if (strncmp(ptrWav->subchunk2ID,"data",4)) 
        {
			//if not equal skip one subchunk and try again
            fseek(fid, ptrWav->subchunk2Size, SEEK_CUR);
            fread(ptrWav->subchunk2ID, 1, 4, fid);
            fread(&ptrWav->subchunk2Size, 4, 1, fid);
            
            if (strncmp(ptrWav->subchunk2ID,"data",4)){
                //if not equal skip one subchunk and try again
                fseek(fid, ptrWav->subchunk2Size, SEEK_CUR);
                fread(ptrWav->subchunk2ID, 1, 4, fid);
                fread(&ptrWav->subchunk2Size, 4, 1, fid);
                if (strncmp(ptrWav->subchunk2ID,"data",4)){
                    printf("can't find DATA subchunk!\n");
                    return EXIT_FAILURE;
                }	
            }	
		}
		ptrWav->dataLength = ptrWav->subchunk2Size / ptrWav->bytesPerSample;
		// get data
		ptrWav->data = (int16_t *)malloc(ptrWav->dataLength * sizeof(int16_t)); // memory allocation for data array
		fread(ptrWav->data, ptrWav->bytesPerSample, ptrWav->dataLength, fid); // read dataLength bytes
		
        //debug prints
        /*	printf("%s\n", ptrWav->chunkID);
         printf("%d\n", ptrWav->fileLength);
         printf("%s\n", ptrWav->typeID);
         printf("%s\n", ptrWav->subchunk1ID);
         printf("%d\n", ptrWav->subchunk1Size);*/
		//printf("%d\n", ptrWav->audioFormat);
		//printf("%d\n", ptrWav->noOfChannels);
		//printf("fs: %d\n", ptrWav->fs);
		//printf("%d\n", ptrWav->byteRate);
		//printf("%d\n", ptrWav->bytesPerSample);		// block align
		//printf("q: %d\n", ptrWav->bitsPerSample);
        /*	printf("%s\n",ptrWav->subchunk2ID);
         printf("%d\n", ptrWav->subchunk2Size);
         printf("%d\n", ptrWav->dataLength);
         printf("%d\n", ptrWav->data[0]);
         printf("%d\n", ptrWav->data[1]);
         printf("%d\n", ptrWav->data[2]);
         printf("%d\n", ptrWav->data[3]);
         printf("%d\n", ptrWav->data[ptrWav->dataLength/2-4]);
         printf("%d\n", ptrWav->data[ptrWav->dataLength/2-3]);
         printf("%d\n", ptrWav->data[ptrWav->dataLength/2-22]);
         printf("%d\n", ptrWav->data[ptrWav->dataLength/2-21]); // last value: pointer is 16bit aligned while datalength is no of bytes!
         */
		fclose(fid);
	}
	return EXIT_SUCCESS;
}

// write wave file
int WriteWav(const char *path, int16_t *data, uint32_t dataLength, int fs, int bitsPerSample)
{
	struct waveFile wav;
	struct waveFile *ptrWav; // pointer to struct
	ptrWav = &wav;			 // useless ??
    
	// collect header info
	wav.chunkID[0] = 'R';
	wav.chunkID[1] = 'I';
	wav.chunkID[2] = 'F';
	wav.chunkID[3] = 'F';
	wav.fileLength = dataLength * (int)(bitsPerSample/8) + 36; //44 byte header + data - 8
	wav.typeID[0] = 'W';
	wav.typeID[1] = 'A';
	wav.typeID[2] = 'V';
	wav.typeID[3] = 'E';
	wav.subchunk1ID[0] = 'f'; 
	wav.subchunk1ID[1] = 'm'; 
	wav.subchunk1ID[2] = 't'; 
	wav.subchunk1ID[3] = ' ';
	wav.subchunk1Size = 16;
	wav.audioFormat = 1;
	wav.noOfChannels = 1;
	wav.fs = fs;
	wav.bitsPerSample = bitsPerSample;
	wav.bytesPerSample = (int)(bitsPerSample/8);
	wav.byteRate = fs * wav.noOfChannels * wav.bytesPerSample;
	wav.subchunk2ID[0] = 'd';
	wav.subchunk2ID[1] = 'a';
	wav.subchunk2ID[2] = 't';
	wav.subchunk2ID[3] = 'a';
	wav.subchunk2Size = dataLength * wav.bytesPerSample;
	
	// write to file
	FILE *fid; 
	fid = fopen(path,"w");
	
	if (fid == NULL)
	{
		printf("couldn't create file!\n");
		return EXIT_FAILURE;
	}	
	else 
	{
		// write simple 44 byte header to file
		fwrite(ptrWav->chunkID, 1, 44, fid); 
		// write data to file
		fwrite(data, wav.bytesPerSample, dataLength , fid);
	}
	fclose(fid);
	return EXIT_SUCCESS;
}

