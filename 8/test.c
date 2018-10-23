#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "point_array.h"
#include "t1.h"

void point_print( point_t* p )
{
  if( p == NULL )
    {
      puts( "(NULL)" );
      return;
    }
  
  printf( "(%.1f, %.1f %.1f) ",
	  p->x, p->y, p->z );
}

void printarr(point_array_t* arr) {
  printf(" %zu\n", arr->len);
  printf(" > ");
  for (int x = 0; x < arr->len; x++) {
    printf("%.0f %.0f %.0f | ", arr->points[x].x, arr->points[x].y, arr->points[x].z);
  }
  printf("\n");
}

void printar( point_array_t* pa )
{
  if( pa == NULL )
    {
      puts( "(NULL)" );
      return;
    }

  printf( "len:%d\n", 
	  (int)pa->len );

  for( int i=0; i<pa->len; i++ )
    {
      printf( " [%d]-", i );
      
      point_print( pa->points+i );
      printf( "\n" );
    }
  printf( "\n" );

}
//= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
int main() {
  
  point_array_t arr;
  point_array_init(&arr);
  
  point_t p;
      
  for (int x = 0; x < 10; x++) {
    p.x = x;
    p.y = x*10;
    p.z = x*2;
    printf("add %d %d %d\n", x, x*10, x*2);
    point_array_append(&arr, &p);
  }

  
  
  printarr(&arr);
  
  point_array_reset(&arr);
  point_array_remove(&arr, 5);
  
  printarr(&arr);
  
  /*
  for (int x = 0; x < 10; x++) {
    point_array_remove(&arr,9-x);
    printarr(&arr);
  }
  */
  
  return 0;
}
//= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =





