YapHash - Yet Another Perceptual Hash
======================================

YapHash is a perceptual fingerprint for audio identification purposes. 
YapHash is part of the [VIAT Project](http://viat.fh-koeln.de/) and therefore developed for detecting telephone-spam. 
Although it's been optimized for speech content, it could also be used for music.  

Standard cryptographic hash functions have the property that minimal alterations of input data 
significantly change the resulting hash value. 
Robust audio hashes in contrast produce identical or nearby hash values for similar input data. 
In particular, the audio hashes should be invariant to (certain) content degradations and hence permit 
a perceptual audio comparison and an efficient identification of a specific recording. 
Different recordings with similar content, e.g. identical words or phrases, or from the same speaker are not identified.

The YapHash fingerprint is based on the spectrogram and Mel-frequency-cepstrum-coefficients (MFCC). 
The sign of the differences in between the frequency bands form a compact yet robust audio hash.

![hash](http://dl.dropbox.com/u/341328/VIATHASH.jpg)

###Usage

YapHash is currently a command line tool and expects at least two arguments; 
First is the configuration file e.g. _viat.cfg_, second is the input wave file. 
To specify the output path a third argument can be passed optionally. 

Example:

    YapHash viat.cfg SPIT_01_ABEIER.wav -f /path/to/output/file.csv

For testing purposes, an additional tool for matching audio hashes has been provided. The maximum number n of matches for two of the aboves hashes is computed. An n-match means that n vectors including their relative time offsets coincide.

Example:

    Match outfile1.csv outfile2.csv
