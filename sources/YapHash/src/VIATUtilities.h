//
//  debugUtilities.h
//  ViatFeatureExtractor
//
//  Created by Gary Grutzek on 15.06.11.
//  Copyright 2011 Fachhochschule Koeln. All rights reserved.
//

#ifndef _UTILITY_FUNCTIONS_H_
#define _UTILITY_FUNCTIONS_H_

#include <string>
#include <cmath>
//#include <boost/asio.hpp>
#include "Array2d_32f.h"
#include "Stft.h"
#include "melFB.h"

//boost::system::error_code pushToSocket(boost::asio::ip::tcp::socket &socket, unsigned long *data, int len);

int debugToCSV(std::string fileName, float *data, int len);

int writeToCSV(std::string audioFileName, int *data, int len);

int writeIndexToCSV(std::string audioFileName, unsigned long *data, int len);

int debug2DToCSV(std::string fileName, Array2d_32f *matrix , int x, int y);

int debugStftToCSV(std::string fileName, Stft *stft);

int getFFTLength(int windowSize);

int getNoOfWindows(int wavLen, int windowSize, int stepSize);

int debugFbToCSV(std::string fileName, MelFb *fbank);


#endif
