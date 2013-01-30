YapHash - Yet Another Perceptual Hash
======================================

YapHash is a perceptual fingerprint for audio identification purposes. 
YapHash is part of the [VIAT Project](http://viat.fh-koeln.de/) and therefore developed for detecting telephone-spam. 
Although it's been optimized for speech content, it could also be used for other audio data.  

Standard cryptographic hash functions have the property that minimal alterations of input data 
significantly change the resulting hash value. 
Robust audio hashes in contrast produce identical or nearby hash values for similar input data. 
In particular, the audio hashes should be invariant to (certain) content degradations and hence permit 
a perceptual audio comparison and an efficient identification of a specific recording. 
Different recordings with similar content, e.g. identical words or phrases, or from the same speaker are not identified.

The YapHash fingerprint is based on the spectrogram and Mel-frequency-cepstrum-coefficients (MFCC).  The sign of the differences in between the frequency bands and the MFCCs forms a compact yet robust audio hash. The standard YapHash fingerprint consists of 100 vectors of length 32 bit and our analysis shows that a couple of matching vectors (with a matching relative time offset) are sufficient to identify equal or similar audio data. More information can be found in the following paper:

Grutzek, G., Strobl, J., Mainka, B., Kurth, F., Pörschmann, C., Knospe, H. (2012). A Perceptual Hash for the Identification of Telephone Speech, 10. ITG Symposium Speech Communication, Braunschweig 2012, In: ITG Fachbericht 236: Sprachkommunikation, VDE Verlag.

###WaveLash - Wavelet Audio Hashing

WaveLash is an experimental add-on to YapHash. Instead of using FFT and MFCCs, a J-level Wavelet transform with a specific wavelet is performed.
A major part of the hash is created by calculating the differences of the variances and one bit by calculating the zero crossing rate.
The bit length of the hash values is configurable.

To use WaveLash, uncomment the line #define WAVELASH_ in main.cpp and compile the source code.

###Installation 
Get the project files:
git clone https://github.com/viat/YapHash
(resp. git pull)


##Linux Installation 
(tested on 2.6.32-5-amd64 x86_64 Debian GNU/Linux 6.0)

cd fftw-3.3.2
CFLAG="-fPIC"
export CFLAG
configure --enable-shared
make
sudo make install

cd ../gsl-1.9
./configure
make
sudo make install

cd ../sources/Match
make

cd ../YapHash
make

cd ../..

The executables in the main project directory are YapHash and Match.

##Mac Installation 
(tested on OS X 10.8.2)

cd fftw-3.3.2
configure --enable-shared
make
sudo make install

cd ../gsl-1.9
./configure
make
sudo make install

cd ../sources/Match
make
cd ../..

Use Xcode and the attached project to build YapHash.

cd ../..

You find the YapHash executable in a directory specified by Xcode.


###Usage
Set the Library Path (necessary only for Linux):
LD_LIBRARY_PATH=/usr/local/lib:./FW_1.3.1_Lin64/lib
export LD_LIBRARY_PATH

YapHash is a command line tool and expects at least two arguments; 
First is the configuration file e.g. _hash.cfg_, second is the input wave file. 
To specify the output file of the fingerprint, a third argument can be passed optionally. 

Example:

    ./YapHash hash.cfg SPIT_01_ABeier.wav out01.csv
    
For testing purposes, an additional tool for matching audio hashes has been provided. The maximum number n of matches for two of the above fingerprint files is computed. An n-match means that n vectors including their relative time offsets coincide.

Example:

    ./Match outfile1.csv outfile2.csv
