/*
 *  Wave.h
 *  VIAT Feature-Extraction Framework
 *
 *	read and write wavefiles
 *
 *  Created by Gary Grutzek on 08.09.10.
 *  Copyright 2010 Fachhochschule Koeln. All rights reserved.
 */

#ifndef _WAVE_H
#define _WAVE_H

#include <inttypes.h>

// wavefile header & payload
struct waveFile {
	// header
	char chunkID[4];		// should be "RIFF"
	uint32_t fileLength;	// chunkSize = fileLength - 8
	char typeID[4];			// should be "WAVE"
	char subchunk1ID[4];	// should be "fmt "
	uint32_t subchunk1Size;
	uint16_t audioFormat;	// compression code: 0x0001 = uncompressed PCM Wave
	uint16_t noOfChannels;	
	uint32_t fs;			// samplerate
	uint32_t byteRate;
	uint16_t bytesPerSample;
	uint16_t bitsPerSample;	// quantization
	char subchunk2ID[4];	// "DATA"
	uint32_t subchunk2Size; // subchunk2Size
	// end of header
	
	int16_t *data;			// pointer to (16Bit-)data / payload
	uint32_t dataLength;	// length of data block = subchunk2Size/bytesPerSample
};

// read wave file
int ReadWav(const char *path, struct waveFile *ptrWav);

// write wave file
int WriteWav(const char *path, int16_t *data, uint32_t dataLength, int fs, int bitsPerSample);
#endif


