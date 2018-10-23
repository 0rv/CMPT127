#include "point_array.h"

/*
typedef struct point
{
  double x, y, z;
} point_t;

typedef struct 
{
  // number of points in the array
  size_t len;
  
  // pointer to an array of point_t structs
  // There is space for 'allocated' structs, but 
  // 'len' structs have been used so far.
  point_t* points;
  
  // to be discussed in class
  size_t reserved; 
  
} point_array_t;
*/

/* ALL THESE FUNCTIONS REQUIRE A VALID POINT_ARRAY_T POINTER AS THEIR
   FIRST PARAMETER. THEY SHOULD FAIL ON ASSERTION IF THIS POINTER IS
   NULL */

/* TASK 1 */

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ) {
  if (pa == NULL) {
    return;
  }
  pa->len = 0;
  return;
}

/* TASK 2 */

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa ) {
  if (pa == NULL | pa->len == 0) {
    return; //no error; no error code; void pointers, man
  }
  free(pa->points);
  pa->len = 0;
  return;
}

/* TASK 3 */

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ) {
  if (p == NULL | pa == NULL) {
    return 1;
  }
  point_t point;
  
  point.x = p->x;
  point.y = p->y;
  point.z = p->z;
  
  if (pa->len == 0) {
    pa->points = malloc(sizeof(point_t));
    pa->points[0] = point;
    pa->len = 1;
    return 0;
  } //END BASE CASE
  
  pa->len++;
  
  pa->points = realloc(pa->points, sizeof(point_t)*(pa->len));
  
  pa->points[pa->len - 1] = point;

  return 0;
}

/* TASK 4 */

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ) {
  if (pa == NULL | i >= pa->len | pa->len == 0) {
    return 1;
  }
  pa->points[i] = pa->points[pa->len - 1];
  pa->len--;

  
  return 0;
}


