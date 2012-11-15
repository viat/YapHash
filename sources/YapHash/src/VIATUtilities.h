/**
 * @file		VIATUtilities.h
 * @date		Jun 15, 2011
 * @author  	Gary Grutzek
 * @brief		Utilities
 * @details		file writer for debugging and csv output
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


#ifndef _UTILITY_FUNCTIONS_H_
#define _UTILITY_FUNCTIONS_H_

#include <string>
#include <cmath>
//#include <boost/asio.hpp>
#include "Array2d_32f.h"
#include "Stft.h"
#include "melFB.h"

/**
 * write to csv file for debugging purposes
 * @param fileName csv file name to write to
 * @param data output data
 * @param len length of data
 * @return
 */
int debugToCSV(std::string fileName, float *data, int len);

/**
 * write to csv file
 * @param audioFileName
 * @param data
 * @param len
 * @return
 */
int writeToCSV(std::string audioFileName, int *data, int len);

/**
 * write hash data with position to csv file
 * @param audioFileName
 * @param data
 * @param len
 * @return
 */
int writeIndexToCSV(std::string audioFileName, unsigned long *data, int len);

/**
 * debugging: write 2d data to csv file
 * @param fileName
 * @param matrix
 * @param x
 * @param y
 * @return
 */
int debug2DToCSV(std::string fileName, Array2d_32f *matrix , int x, int y);

/**
 * debugging: write spectrogram to csv
 * @param fileName
 * @param stft
 * @return
 */
int debugStftToCSV(std::string fileName, Stft *stft);

/**
 *	returns length of fft aka next power of 2
 * @param windowSize
 * @return
 */
int getFFTLength(int windowSize);

/**
 * calcs num of windows for given smaple number and window size
 * @param wavLen number of samples
 * @param windowSize
 * @param stepSize
 * @return number of windows
 */
int getNoOfWindows(int wavLen, int windowSize, int stepSize);

/**
 * debugging: write mel filter bank to csv
 * @param fileName
 * @param fbank
 * @return
 */
int debugFbToCSV(std::string fileName, MelFb *fbank);



#endif
