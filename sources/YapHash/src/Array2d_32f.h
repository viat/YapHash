/**
 * @file		Array2d_32f.h
 * @date		May 03, 2011
 * @author  	Gary Grutzek
 * @brief		2D Array
 * @details		2D Array class
 *
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


#ifndef _ARRAY_32f_H_
#define _ARRAY_32f_H_

#include "fwBase.h"

class Array2d_32f{
    
public:
    
    // Konstruktor
    Array2d_32f(int x, int y);
    // Destruktor
    ~Array2d_32f();
    // the data
    //Ipp32f **data;
    Fw32f **data;
    int cols;
    int rows;
};

// TODO: make private + gettter/ setter

#endif
