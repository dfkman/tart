/*
* ledit.h
* The way in which tart opens/stores/saves images.
* Uses lodepng (thanks Mr. Lode!) for pngs
* This is done more for the sake of readability of the main() 
*/

#include "lodepng.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct{
unsigned char * data;
unsigned width;
unsigned height;
}

//Opens the image from the specified filename
//@returns the char* representation of the iamge for editing
unsigned char* loadimage (char * filename);

//Saves the specified image in memory 
void saveimage (char * filename, unsigned char * image);

//cleans up the loaded image
void cleanup (unsigned char * image);
