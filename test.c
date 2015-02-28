#include <curses.h>
#include <time.h>
#include <stdlib.h>

void    grid_generate(int grid[4][4])
{
  int i = 0;
  int empty = 0;
  while (i < 4)
    {
      int j = 0;
      while (j < 4)
        {
	  if (grid[i][j] == 0)
	    empty++;
	  j++;
        }
      i++;
    }
  if (empty == 0)
    {
      //ft_putstr("FAIL OMG QUIT THAT SHIT\n")
      return;   //ERROR OMG
    }
  int position = rand() % empty;
  int test = rand() % 100;
  int value = test > 75 ? 4 : 2;
  empty = 0;
  i = 0;
  while (i < 4)
    {
      int j = 0;
      while (j < 4)
        {
	  if (grid[i][j] == 0)
	    empty++;
	  if (grid[i][j] == 0 && empty == position)
            {
	      grid[i][j] = value;
	      return;
            }
	  j++;
        }
      i++;
    }
}

void    puttab(int grid[4][4])
{
  int i = 0;
  while (i < 4)
    {
      int j = 0;
      while (j < 4)
	printf("%d", grid[i][j++]);
      printf("\n");
      i++;
    }
  printf("\n");

}

void    upthis(int grid[4][4], int j, int i)
{
  int value = grid[j][i];
  int tmp = j;
  j--;
  while (j >= 0)
    {
      if (grid[j][i] == value)
        {
	  grid[j][i] *= 2;
	  grid[tmp][i] = 0;
	  return;
        }
      else if (grid[j][i])
        {
	  grid[tmp][i] = 0;
	  grid[j + 1][i] = value;  
	  return;
        }
      else if (!j)
        {
	  grid[tmp][i] = 0;
	  grid[j][i] = value;
	  return;
        }
      j--;
    }
}


void    upper(int grid[4][4])
{
  int i = 0;
  while (i < 4)
    {
      int j = 1;
      while (j <= 3)
        {
	  if (grid[j][i])
	    upthis(grid, j, i);
	  j++;
        }
      i++;
    }
}

void    left(int grid[4][4])
{
  (void)grid;
}

void    right(int grid[4][4])
{
  (void)grid;
}

void    down(int grid[4][4])
{
  (void)grid;
}


void    update(int grid[4][4], int action)
{
  if (action == 0)
    upper(grid);
  else if (action == 1)
    left(grid);
  else if (action == 2)
    right(grid);
  else
    down(grid);
}

int main()
{
  // initscr();
  // raw();
  // curs_set(0);
  // noecho();
  // int mx=0, my=0;
  // int i = 0;
  //    initscr();
  //    getmaxyx(stdscr, my, mx);
  //    int square_x = mx / 4;
  //    int square_y = my / 4;
  int action = 0;
  int grid[4][4] ={{0}};
  srand(time(NULL));
  grid_generate(grid);
  grid_generate(grid);
  grid_generate(grid);
  grid_generate(grid);
  grid_generate(grid);
  puttab(grid);
  update(grid, action);
  puttab(grid);
  //    while (i < mx * my)
  //    {
  //    char tmp;
  //    if (!((i / mx) % square_y) && !((i % mx) % square_x))
  //    tmp = '+';
  //    else if (!((i / mx) % square_y))
  //    tmp = '-';
  //    else if (!((i % mx) % square_x))
  //    tmp = '|';
  //    else
  //    tmp = ' ';
  //    // printw("i = %d, mx = %d, my = %d, i / my = %d, i %% mx = %d", i, mx, my, i / my, i % mx);
  //    if (mvaddch(i / mx, i % mx, tmp) == ERR)
  //    break;
  //    i++;
  //    // if (getch() == 27)
  //    // break;
  //    }
  // refresh();
  //    getch();
  //    endwin();
  //    printf("%d %d\n", mx, my);
  //    curs_set(1);
}
