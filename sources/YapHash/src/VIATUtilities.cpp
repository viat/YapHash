//
//  debugUtilities.cpp
//  ViatFeatureExtractor
//
//  Created by Gary Grutzek on 15.06.11.
//  Copyright 2011 Fachhochschule Koeln. All rights reserved.
//

#include "VIATUtilities.h"


#include <fstream>
#include <iostream>

boost::system::error_code pushToSocket(boost::asio::ip::tcp::socket &socket, unsigned long *data, int len)
{
	// send data
   	boost::system::error_code error;
   	socket.write_some(boost::asio::buffer(data, len), error);

   	return error;
}

int getNoOfWindows(int wavLen, int windowSize, int stepSize)
{
    return (wavLen - (windowSize - stepSize))/stepSize;	
}
 
int getFFTLength(int windowSize)
{
    int fftOrder = ceilf(logf(windowSize)/logf(2.0f));
    return (1 << fftOrder); // 2^fftOrder
}

// write data array to file 
int writeIndexToCSV(std::string audioFileName, unsigned long *data, int len)
{
    // create csv name from audiofile name
    std::string fileName = audioFileName;
    fileName.replace(fileName.length()-3, fileName.length(), "csv");
	// std::cout << "Write Data to: " << fileName << std::endl;
    
	std::ofstream csvFile;
    csvFile.open(fileName.c_str());
    
    // write data
    csvFile << "#3" << std::endl; // VIAT ID for Peak pattern
    
    for (int i=0; i<2*len; i+=2) {
        //if (data[i] != 0)
        csvFile << data[i] << "," << data[i+1] << std::endl;
    }
    csvFile.close();
    
    return 0;
}


// write data array to file 
int writeToCSV(std::string audioFileName, int *data, int len)
{
    // create csv name from audiofile name
    std::string fileName = audioFileName;
    std::cout << fileName << std::endl;
    fileName.replace(fileName.length()-3, fileName.length(), "csv");
	// std::cout << "Write Data to: " << fileName << std::endl;
    
	std::ofstream csvFile;
    csvFile.open(fileName.c_str());
    
    // write data
    csvFile << "#3" << std::endl; // VIAT ID for Peak pattern
    
    for (int i=0; i<len; i+=2)
    {
       // if (data[i] != 0)
            //		Position		Feature
            csvFile << data[i] << "," << data[i+1] << std::endl;
    }
    csvFile.close();
    
    return 0;
}

int debugToCSV(std::string fileName, float *data, int len)
{
    
	std::ofstream csvFile;
    csvFile.open(fileName.c_str());
    
    // write data    
    int i;
    for (i=0; i<len-1; i++)
    {
        csvFile << data[i] << "," << std::endl;
    }
    csvFile << data[i+1] << ";" << std::endl;
    csvFile.close();
    
    return 0;    
}
int debug2DToCSV(std::string fileName, Array2d_32f *matrix , int x, int y)
{
    
	std::ofstream csvFile;
    csvFile.open(fileName.c_str());
    
    // write data    
    int i, j ;
    for (j=0;j<y; j++)
    {
      for (i=0; i<x; i++)
      {
        csvFile << matrix->data[i][j] << ","; 
      }
        csvFile << std::endl;
     // csvFile << matrix.data[i+1][j] << ";" << std::endl;
    }   
    csvFile.close();
    
    return 0;    
}

int debugStftToCSV(std::string fileName, Stft *stft)
{
    
	std::ofstream csvFile;
    csvFile.open(fileName.c_str());
    
    // write data    
    int i, j ;
    for (j=0;j<stft->fftLen/2+1; j++)
    {
        for (i=0; i<stft->NoOfWindows; i++)
        {
            csvFile << stft->spectrogramm[i][j] << ","; 
        }
        csvFile << std::endl;
        // csvFile << matrix.data[i+1][j] << ";" << std::endl;
    }   
    csvFile.close();
    
    return 0;    
}

int debugFbToCSV(std::string fileName, MelFb *bank)
{
    
	std::ofstream csvFile;
    csvFile.open(fileName.c_str());
    
    // write data    
    int band, k ;
    for (band=0;band<bank->numFilterBanks; band++)
    {
        for (k=0; k<bank->fbSize; k++)
        {
            csvFile << bank->fbank[band][k] << ","; 
        }
        csvFile << std::endl;
        // csvFile << matrix.data[i+1][j] << ";" << std::endl;
    }   
    csvFile.close();
    
    return 0;    
}
