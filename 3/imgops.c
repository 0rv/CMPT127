/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  for (int j = 0; j < cols * rows; j++) {
    array[j] = 0;
  }
  return;
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  uint8_t* newarray = malloc( cols * rows * sizeof(uint8_t));
  
  for (int x = 0; x <  cols * rows; x++) {
    newarray[x] = array[x];
  }
  return newarray;
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
  uint8_t min = array[0];
  for (int x = 1; x < rows * cols; x++) {
    if (array[x] < min) {
      min = array[x];
    }
  }
  return min;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
  uint8_t max = array[0];
  for (int x = 1; x < rows * cols; x++) {
    if (array[x] > max) {
      max = array[x];
    }
  }
  return max;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  for (int x = 0; x < rows * cols; x++) {
    if (array[x] == pre_color) {
      array[x] = post_color;
    }
  }
  return;
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
  uint8_t temp = 0;
  int index1 = 0;
  int index2 = 0;
  
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < (cols)/2; x++) {
      index1 = (y*cols + x);
      index2 = (y+1)*cols - (x+1);
      
      temp = array[index1];
      array[index1] = array[index2];
      array[index2] = temp;
    }
  }
  
  return;
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
  uint8_t temp = 0;
  
  for (int x = 0;x < cols*rows/2;x++) {
    temp = array[x];
    array[x] = array[cols*rows - (x+1)];
    array[cols*rows - (x+1)] = temp;
  }
  flip_horizontal(array, cols, rows);
  
  return;
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
//int locate_color( uint8_t array[],
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
  for (int yy = 0; yy < rows; yy++) {
    for (int xx = 0; xx < cols; xx++) {
      if (array[yy*cols + xx] == color) {
        *x = xx;
        *y = yy;
        return 1;
      }
    }
  }
    return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
  for (int x = 0; x < rows * cols; x++) {
    array[x] = (255-array[x]);
  }
  return;
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  double temp = 0.0;
  
  for (int x = 0; x < rows * cols; x++) {
    if ((array[x] * scale_factor) > 255) {
      array[x] = 255;
    } else {
      temp = array[x] * scale_factor;
      array[x] = round(temp);
    }
  }
  
  return;
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
  {
    int imgmax = max(array, cols, rows);
    int imgmin = min(array, cols, rows);
    int diff = (imgmax - imgmin);

    for(int x = 0; x < cols*rows; x++){
      array[x] = round((255.0/diff) * (array[x] - imgmin));
    }
  }
    
    return;
}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original i mage.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  uint8_t* new = malloc(rows/2 * cols/2 * sizeof(uint8_t));
  if (new == NULL) {
    return NULL;
  }
  double temp = 0;
  int avg = 0;
  
  for (int y = 0; y < rows/2; y++) {
    for (int x = 0; x< cols/2; x++) {
      
      temp = get_pixel(array, cols, rows, x*2, y*2)     +
             get_pixel(array, cols, rows, x*2+1, y*2)   +
             get_pixel(array, cols, rows, x*2+1, y*2+1) +
             get_pixel(array, cols, rows, x*2, y*2+1);
                 
      avg = round(temp/4.0);//easier in 2 steps
      
      set_pixel(new, cols/2, rows/2, x, y, avg);
    }
  }
  
  return new;
}




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
  //turns X, Y values into array indexing values
  
  if (bottom > rows) {
    bottom = rows;
  }
  
  if (right > cols) {
    right = cols;
  }
  
  for (int y = top; y < bottom; y++) {
    for (int x = left; x < right; x++) {
      set_pixel(array, cols, rows, x, y, color);
    }
  }
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
  
  unsigned int long tot = 0;
  
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      
      if (y >= top & y <= bottom) {
        if (x >= left & x <= right) {
          tot += array[y*cols + x];
        }
      }
      
    }
  }
  
  return tot;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.


uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
  
  if ((top <= bottom) && (left <= right)  &&
     (bottom <= rows) && (right <= cols)  &&
     ( top != bottom) && (left != right)) //conditions for which we return NULL
  {
  
  uint8_t* new = malloc(rows*cols*sizeof(uint8_t) ); //allocate bois
  //will never be larger than original image, hence we alloc the same space
  uint8_t temp = 0;
  if (new == NULL) {
    return new;
  }
  
  for (int y = top; y < bottom; y++) {
    for (int x = left; x < right; x++) {
      
      temp = get_pixel(array, cols, rows, x, y);
      set_pixel(new, right-left, bottom-top, x-left, y-top, temp);
      
    }
  }
  
  return new;
  } else{
  return NULL;
}
}

/*












*/