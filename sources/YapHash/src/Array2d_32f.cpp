/**
 *  Array2d_32f.cpp
 *  VIAT Feature-Extraction Framework
 *
 *  2D Array
 *
 *  Created by Gary Grutzek on 03.05.11.
 *  Copyright 2011 FH Koeln. All rights reserved.
 *
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
