/**
 * @file		Wave.h
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


#ifndef _WAVE_H
#define _WAVE_H

#include <inttypes.h>

/**
 *  wavefile header & payload
 */
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


/**
 * read wave file
 * @param path path to wave file
 * @param ptrWav struct where to put extracted meta data, header
 * @return zero if no error
 */
int ReadWav(const char *path, struct waveFile *ptrWav);

/**
 * write wave file
 * @param path path where to write
 * @param data linear pcm data, 16 bit
 * @param dataLength number of samples
 * @param fs samplerate
 * @param bitsPerSample bitdepth
 * @return zero if no error
 */
int WriteWav(const char *path, int16_t *data, uint32_t dataLength, int fs, int bitsPerSample);

#endif
