//
//  melFB.h
//   
//
//  Created by Gary Grutzek on 30.03.11.
//  Copyright 2011 Fachhochschule Koeln. All rights reserved.
//

#ifndef _MEL_FB_H_
#define _MEL_FB_H_

#include "Stft.h"

class MelFb{
	
public:
    
    // Konstruktor
    MelFb(int fftSize, int numFilterBanks, int locut, int hicut);
    // Destruktor
    ~MelFb();
    
    void calcMelFB();
    void applyMelFB(Fw32f **output, const Stft& stft);
	
    // TODO: getter methoden
	Fw32f **fbank;	
    
	int fbSize; 
	int numFilterBanks;
    int loCut;
    int hiCut;

private:
    Fw32f *fLo;
    Fw32f *fHi;
    
	Fw32f linToMel(Fw32f lin);
    Fw32f melToLin(Fw32f lin);

};


#endif

