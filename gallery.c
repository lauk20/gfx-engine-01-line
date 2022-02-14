#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//IF COMPILING ERROR: MUST USE "-lm" FLAG TO INCLUDE MATH LIBRARY
//EXAMPLE: "gcc -o gallery gallery.c draw.c display.c -lm" would compile

void draw_s(screen s, int x, int y, color c){
  // 3 top lines
  draw_line(x, y + 12, x, y + 4, s, c);
  draw_line(x - 8, y + 12, x - 8, y + 4, s, c);
  draw_line(x + 8, y + 12, x + 8, y + 4, s, c);

  // 3 bottom lines
  draw_line(x, y - 12, x, y - 4, s, c);
  draw_line(x - 8, y - 12, x - 8, y - 4, s, c);
  draw_line(x + 8, y - 12, x + 8, y - 4, s, c);

  // middle 2 diagonals
  draw_line(x, y + 4, x + 8, y - 4, s, c);
  draw_line(x - 8, y + 4, x, y - 4, s, c);

  // top 2 diagonals
  draw_line(x, y + 20, x - 8, y + 12, s, c);
  draw_line(x, y + 20, x + 8, y + 12, s, c);

  // bottom 2 diagonals
  draw_line(x, y - 20, x - 8, y - 12, s, c);
  draw_line(x, y - 20, x + 8, y - 12, s, c);

  draw_line(x - 8, y - 4, x - 4, y, s, c);
  draw_line(x + 8, y + 4, x + 4, y, s, c);
}

double distance(int x, int y){
  //printf("%f\n", sqrt((x - XRES/2) * (x - XRES/2) + (y - YRES/2) * (y - YRES/2)));
  return sqrt((x - XRES/2) * (x - XRES/2) + (y - YRES/2) * (y - YRES/2));
}

int main(){

  screen s;
  color c;

  c.red = 255;
  c.green = 255;
  c.blue = 255;

  int rfault = 0;
  int gfault = 0;
  int bfault = 255;

  clear_screen(s);

  int even = 0;
  for (int i = 0; i < XRES; i = i + 21){
    for (int v = 0; v < YRES; v = v + 46){
      if (even % 2 == 0){
        double dist = distance(i + 8, v + 20);
        c.red = rfault - floor(0.7 * dist);
        c.green = gfault - floor(0.7 * dist);
        c.blue = bfault - floor(0.7 * dist);
        draw_s(s, i + 8, v + 20, c);
      }
      even = even + 1;
      /*
      if (c.red > 0)
        c.red = c.red - 1;
      if (c.green > 0)
        c.green = c.green - 1;
      if (c.blue > 0)
        c.blue = c.blue - 1;
      */
    }
  }

  //draw_s(s, XRES/2, YRES/2, c);
  save_extension(s, "lines.png");
}
