/**
 * @file		VIATUtilities.cpp
 * @date		Jun 15, 2011
 * @author  	Gary Grutzek
 * @brief		Utilities
 * @details		file writer for debugging and csv output
 *              Debug Audio output added
 *              knospe Jan 31, 2013
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

#include "VIATUtilities.h"


#include <fstream>
#include <iostream>

//boost::system::error_code pushToSocket(boost::asio::ip::tcp::socket &socket, unsigned long *data, int len)
//{
//	// send data
//   	boost::system::error_code error;
//   	socket.write_some(boost::asio::buffer(data, len), error);
//
//   	return error;
//}

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
int writeIndexToBin(std::string audioFileName, unsigned long *data, int len)
{
    char b;
    int size;
    size = sizeof(unsigned long);

    // create csv name from audiofile name
    std::string fileName = audioFileName;
    fileName.replace(fileName.length()-3, fileName.length(), "bin");
	// std::cout << "Write Data to: " << fileName << std::endl;
    
	std::ofstream binFile;
    binFile.open(fileName.c_str());
    
    // write data
       
    for (int i=0; i<2*len; i+=2) {
        //if (data[i] != 0)
        for (int j=0; j<4; j++)  // assume 32 Bit Hash, other lengths TBD
        {
            b=(data[i+1]>>(8*j)) & 255;
            binFile << b ;
        }
       
    }
    // binFile << std::endl;
    binFile.close();
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
        //          Position                Feature
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

int debugShortToCSV(std::string fileName, short *data, int len)
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

int debugStwtToCSV(std::string fileName, Stwt *stwt)
{

	std::ofstream csvFile;
    csvFile.open(fileName.c_str());

    // write data
    int i, j ;
    for (i = 0; i < stwt->mNoOfWindows; i++)
    {
    	for (j = 0; j < stwt->mFwtLen; j++)
    	{
            csvFile << stwt->mSpectrogramm[i][j] << ",";
        }
        csvFile << std::endl;
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
