#include "lodepng.h"
#include "ledit.h"
#include <stdlib.h>
#include <stdio.h>

//Opens the image from the specified filename
//@returns the Image struct representation of the image for editing
Image loadimage (char * filename){
	unsigned error;
	unsigned char* image;
	unsigned width,height;
	error = lodepng_decode32_file(&image,&width,&height, filename);
	Image ret = {image, width, height};
	return ret;
	
}

//Saves the specified image in memory
void saveimage (char * filename, Image img){
	lodepng_encode32_file(filename,img.data,img.width,img.height);
}

//cleans up the loaded image
void cleanup (Image img){
	free(img.data);
}

int main(){
	Image sample = loadimage("appl.png");
	saveimage ("sampleappl.png", sample);
	cleanup(sample);
}
