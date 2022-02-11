#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c){
  //make point left to right;
  if (x0 > x1){
    int holder = x0;
    x0 = x1;
    x1 = holder;

    holder = y0;
    y0 = y1;
    y1 = holder;
  }

  int a = 2 * (y1 - y0);
  int b = 2 * -1 * (x1 - x0);

  int x = x0;
  int y = y0;

  //octants 1 and 5
  if (y1 - y0 <= x1 - x0 && y1 - y0 > 0){
    int d = a + 0.5 * b;
    while (x <= x1){
      plot(s, c, x, y);

      if (d > 0){
        y = y + 1;
        d = d + b;
      }

      x = x + 1;
      d = d + a;
    }
  } else if (y1 - y0 > x1 - x0 && y1 - y0 > 0){ //octants 2 and 6
    int d = 0.5 * a + b;
    while (y <= y1){
      plot(s, c, x, y);

      if (d < 0){
        x = x + 1;
        d = d + a;
      }

      y = y + 1;
      d = d + b;
    }
  } else if (y1 - y0 <= x1 - x0 && y1 - y0 < 0){ //octants 4 and 8
    int d = a - 0.5 * b;
    while (x <= x1){
      plot(s, c, x, y);

      if (d < 0){
        y = y - 1;
        d = d - b;
      }

      x = x + 1;
      d = d + a;
    }
  }
}
