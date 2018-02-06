#include "lodepng.h"
#include "ledit.h"
#include <stdlib.h>
#include <stdio.h>

//Opens the image from the specified filename
//@returns the char* representation of the iamge for editing
unsigned char* loadimage (char * filename){
	unsigned error;
	unsigned char* image;
	unsigned width,height;
	error = lodepng_decode32_file(&image,&width,&height, filename);
	if (error != 0){
		return NULL;
	}
	else{
		return image;
	}
}

//Saves the specified image in memory
void saveimage (char * filename, unsigned char * image);

//cleans up the loaded image
void cleanup (unsigned char * image);
