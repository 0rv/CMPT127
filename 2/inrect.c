#include <stdio.h>

int InRectangle(float pt[2], float rect[4]) {
  //rect[0] and rect[1] are one corner
  //
  //float coords[4] = {MIN(rect[0],rect[2]),MIN(rect[1],rect[3]),MAX(rect[0],rect[2]),MAX(rect[1],rect[3])};
  float coords[4] = {0.0, 0.0, 0.0, 0.0};
  
  if (rect[0] > rect[2]) {
    coords[0] = rect[2];
    coords[2] = rect[0];
  }else{
    coords[0] = rect[0];
    coords[2] = rect[2];
  }
  if (rect[1] > rect[3]) {
    coords[1] = rect[3];
    coords[3] = rect[1];
  }else{
    coords[1] = rect[1];
    coords[3] = rect[3];
  }
  printf("(%f, %f) - (%f, %f), (%f, %f)\n", pt[0],pt[1], coords[0],coords[1],coords[2],coords[3]);
  if (pt[0] <= coords[0]) {
    
    printf("flag 1\n");
    return 0;
  }
  if (pt[0] >= coords[2]) {
    printf("flag 2\n");
    return 0;
  }
  if (pt[1] <= coords[1]) {
    printf("flag 3\n");
    return 0;
  }
  if (pt[1] >= coords[3]) {
    printf("flag 4\n");
    return 0;
  }
  //align the coordinates so we always have higher point on one end (point is ALWAYS bottom left - top right)
  //printf("%f %f %f\n",pt[0],pt[1],pt[2]);
  
  return 1;
}