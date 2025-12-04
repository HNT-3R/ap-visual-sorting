#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>


#define ARR_LENGTH 20
#define MAX_NUM 10

int main (void) {
  initscr();
  cbreak();
  noecho();

  int arr[ARR_LENGTH];


  srand(time(NULL));
  for (int i = 0; i < ARR_LENGTH; i++) {
    arr[i] = floor(rand() % MAX_NUM);
    char str[20];
    sprintf(str, "%d", arr[i]);
    mvaddstr(1, (i*2), str);
  }

  mvaddstr(10, 30, "press any key to quit");
  
  
  
  
  refresh();
  getch();
  endwin();
  return 0;
}