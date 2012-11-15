/**
 * @file		Array2d_32f.cpp
 * @date		May 03, 2011
 * @author  	Gary Grutzek
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

#include "Array2d_32f.h"
#include <iostream>

//#define free(x) printf("freeing "#x" %p at %s: %d\n", x, __FILE__, __LINE__); \
//fflush(stdin);\
//free(p);

Array2d_32f::Array2d_32f(int x, int y)
{
    // multidimensional array
    data = new Fw32f *[x]; // alloc some pointers ...
    for (int i = 0; i < x ; i++) 
        data[i] = new Fw32f[y]; // ... and alloc an array for each pointer   
    // the destructor should know the number of columns
    cols = x;
    rows = y;
}


Array2d_32f::~Array2d_32f()
{
    if (data != NULL) 
	{
		for (int j = 0; j < cols ; j++) 
			delete [] data[j] ; 
		delete [] data; 
	}
   //   std::cout << "array destroyed" << std::endl;
}
