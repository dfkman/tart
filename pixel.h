#include <stdint.h>

//Pixel.h
//defines the Pixel struct, and assoc. fn's
//Pixel is an abstraction of
//LodePNG's raw pixel data

typedef struct{
        uint32_t red;
        uint32_t green;
        uint32_t blue;
        uint32_t alpha;
        int x;
        int y;
} Pixel;

//Saves the current pixel to the image in memory
void savetopic(Pixel px, Image img);

//Creates a new Pixel instance
Pixel newpixel(Image img, int x, int y);
