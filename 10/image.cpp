#include "image.hpp"
#include "draw.h"
#include "png.h"


        
/* Constructs an image of 0x0 pixels. */
Image::Image()
  :cols(0),rows(0),pixels(0)
{
  
}

/* Frees all memory allocated for img */
Image::~Image() {
  
}

/* Changes the size of an image, allocating memory as necessary, and
   setting all pixels to fillcolor. Returns 0 on success, or a non-zero error code.*/ 
int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ) {
  if (pixels) {
    delete [] pixels;

    pixels = new uint8_t[height*width];
    
    for (int x = 0; x < width; x++) {
      for (int j = 0; j < height; j++) {
        pixels[j*width + x] = fillcolor;
      }
    }
    this->cols = width;
    this->rows = height;
  }
  return 0;
}

/* Sets the color of the pixel at (x,y) to color. Returns 0 on success, else a non-zero 
   error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ) {
  if (x > cols || y > rows) {
    return 1;
  }
  pixels[y*cols + x] = color;
  return 0;
}

/* Gets the color of the pixel at (x,y) and stores at the address pointed to 
   by colorp. Returns 0 on success, else a non-zero error code. */
int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ) { 
  if (x > cols || y > rows) {
    return 1;
  }
  colorp =  &pixels[y*cols + x];
  return 0;
}