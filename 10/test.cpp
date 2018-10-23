#include <stdlib.h>
#include <iostream>
#include "png.h"
#include "draw.h"
#include "image.hpp"
#include <iostream>

int main(int argc, char** argv) {
  
  if (argc != 2) {
    exit(1);
  }
  Image img;
  printf("yes\n");
  img.resize(50, 50, 255);
  uint8_t blank = 0;
  img.get_pixel(25, 25, *blank);
  
  
  
  
  
  return 0;
}