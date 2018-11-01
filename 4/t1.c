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
      //printf("circle of size %d\n", r);
      for (int x = 0; x < 2*r, x++) {
        //2r = number of rows/cols circle takes up
        for (int y = 0; y < 2*r, y++) {
          if (int(x*x + y*y) == r) {
            printf("#");
          } else {
            printf(" ");
          }
        }
        printf("/n");
      }
    }
  }
  
  return;
}