/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);

  short col = 30;

  void dp(){
    short centerR = LONG_EDGE_PIXELS / 2; //center coordinate for the rows
    short centerC = SHORT_EDGE_PIXELS / 2; //center coordinate for the columns

    for (int c = 30; c >= 0; c--){
      for (int j = 0; j <= c; j++){
	r = 30 - c;
	dp(centerC + j, centerR + r, COLOR_WHITE);
	dp(centerC + j, centerR - r, COLOR_BLACK);
	dp(centerC - j, centerR + r, COLOR_RED);
	dp(centerC - j, centerR - r, COLOR_YELLOW);
      }
    }
  }

  void hourGlass(focusRow, focusCol){
    row1 = 1 * col + 0;
    row2 = 1 * col + 0;

    for (row = 10; row <= 10; row++){
      col1 = row;
      col2 = row;
      minCol = min(col1, col2);
      maxCol = max(col1, col2);
      
      for (col = minCol; maxCol; col++){
	hourGlass(col + focusCol, row + focusRow);
      }
    }
  }
  short startc = 30;

  short startr = 30;

  for (col = 0; col < 30){
    short row = col;
    short leftEdge = -col;
    short rightEdge = col;

    for (short c = leftEdge, c <= rightEdge; c++){
      drawPixel(startc + c, startr+row, COLOR_PINK);
    //drawPixel(startc + rightEdge, startr+row, COLOR_PINK);
    }
    col += 1;
  }

  //drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);

  //fillRectangle(30,30, 60, 60, COLOR_ORANGE);
  
}
