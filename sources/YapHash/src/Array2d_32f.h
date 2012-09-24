/**
 *  Array2d_32f.h
 *  VIAT Feature-Extraction Framework
 *
 *  2D Array
 *
 *  Created by Gary Grutzek on 03.05.11.
 *  Copyright 2011 FH Koeln. All rights reserved.
 *
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
