#include <stdio.h>
#include <string.h>

void draw_circle( uint8_t img[], 
                  unsigned int cols,
                  unsigned int rows,
		              int x,
		              int y,
		              int r,
		              uint8_t color )
{        
  if (r == 0) {
    return;
  }//unique case
  
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      //TODO
    }
  }
  
  return;
}