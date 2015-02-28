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

void	puttab(int grid[4][4])
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

int	downthis(int grid[4][4], int j, int i)
{
	int value = grid[j][i];
	int tmp = j;
	j++;
	while (j <= 3)
	{
		if (grid[j][i] == value)
		{
			grid[j][i] *= 2;
			grid[tmp][i] = 0;
			return (1);
		}
		else if (grid[j][i])
		{
			grid[tmp][i] = 0;
			grid[j - 1][i] = value;
			return (j - 1 - tmp);
		}
		else if (j == 3)
		{
			grid[tmp][i] = 0;
			grid[j][i] = value;
			return (1);
		}
		j++;
	}
	return (0);
}

int	upthis(int grid[4][4], int j, int i)
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
			return (1);
		}
		else if (grid[j][i])
		{
			grid[tmp][i] = 0;
			grid[j + 1][i] = value;
			return (j + 1 - tmp);
		}
		else if (!j)
		{
			grid[tmp][i] = 0;
			grid[j][i] = value;
			return (1);
		}
		j--;
	}
	return (0);
}


int	upper(int grid[4][4])
{
	int i = 0;
	int ret = 0;
	int test;
	while (i < 4)
	{
		int j = 1;
		while (j <= 3)
		{
			if (grid[j][i])
			{
				if ((test = upthis(grid, j, i)))
					ret = test;
			}
			j++;
		}
		i++;
	}
	return (ret);
}


int	leftthis(int grid[4][4], int j, int i)
{
	int value = grid[j][i];
	int tmp = i;
	i--;
	while (i >= 0)
	{
		if (grid[j][i] == value)
		{
			grid[j][i] *= 2;
			grid[j][tmp] = 0;
			return (1);
		}
		else if (grid[j][i])
		{
			grid[j][tmp] = 0;
			grid[j][i + 1] = value;
			return (i + 1 - tmp);
		}
		else if (!i)
		{
			grid[j][tmp] = 0;
			grid[j][i] = value;
			return (1);
		}
		i--;
	}
	return (0);
}

int	left(int grid[4][4])
{
	int j = 0;
	int ret = 0;
	int test;
	while (j < 4)
	{
		int i = 1;
		while (i <= 3)
		{
			if (grid[j][i])
			{
				if ((test = leftthis(grid, j, i)))
					ret = test;
			}
			i++;
		}
		j++;
	}
	return (ret);
}

int	rightthis(int grid[4][4], int j, int i)
{
	int value = grid[j][i];
	int tmp = i;
	i++;
	while (i <= 3)
	{
		if (grid[j][i] == value)
		{
			grid[j][i] *= 2;
			grid[j][tmp] = 0;
			return (1);
		}
		else if (grid[j][i])
		{
			grid[j][tmp] = 0;
			grid[j][i - 1] = value;
			return (i - 1 - tmp);
		}
		else if (i == 3)
		{
			grid[j][tmp] = 0;
			grid[j][i] = value;
			return (1);
		}
		i++;
	}
	return (0);
}


int	right(int grid[4][4])
{
	int j = 0;
	int ret = 0;
	int test;
	while (j < 4)
	{
		int i = 2;
		while (i >= 0)
		{
			if (grid[j][i])
			{
				if ((test = rightthis(grid, j, i)))
					ret = test;
			}
			i--;
		}
		j++;
	}
	return (ret);
}

int	down(int grid[4][4])
{
	int i = 0;
	int ret = 0;
	int test;
	while (i < 4)
	{
		int j = 2;
		while (j >= 0)
		{
			if (grid[j][i])
			{
				if ((test = downthis(grid, j, i)))
					ret = test;
			}
			j--;
		}
		i++;
	}
	return (ret);
}


int		update(int grid[4][4], int action)
{
	int ret;
	if (action == 0)
		ret = upper(grid);
	else if (action == 1)
		ret = left(grid);
	else if (action == 2)
		ret = right(grid);
	else
		ret = down(grid);
	return (ret);
}

// int main()
// {
//   // initscr();
//   // raw();
//   // curs_set(0);
//   // noecho();
//   // int mx=0, my=0;
//   // int i = 0;
//   //    initscr();
//   //    getmaxyx(stdscr, my, mx);
//   //    int square_x = mx / 4;
//   //    int square_y = my / 4;
//   int action = 0;
//   int grid[4][4] ={{0}};
//   srand(time(NULL));
//   grid_generate(grid);
//   grid_generate(grid);
//   grid_generate(grid);
//   grid_generate(grid);
//   grid_generate(grid);
//   puttab(grid);
//   update(grid, action);
//   puttab(grid);
//   grid_generate(grid);
//   puttab(grid);
//   update(grid, 3);
//   puttab(grid);
//   update(grid, 1);
//   puttab(grid);
//   update(grid, 2);
//   puttab(grid);
//   //    while (i < mx * my)
//   //    {
//   //    char tmp;
//   //    if (!((i / mx) % square_y) && !((i % mx) % square_x))
//   //    tmp = '+';
//   //    else if (!((i / mx) % square_y))
//   //    tmp = '-';
//   //    else if (!((i % mx) % square_x))
//   //    tmp = '|';
//   //    else
//   //    tmp = ' ';
//   //    // printw("i = %d, mx = %d, my = %d, i / my = %d, i %% mx = %d", i, mx, my, i / my, i % mx);
//   //    if (mvaddch(i / mx, i % mx, tmp) == ERR)
//   //    break;
//   //    i++;
//   //    // if (getch() == 27)
//   //    // break;
//   //    }
//   // refresh();
//   //    getch();
//   //    endwin();
//   //    printf("%d %d\n", mx, my);
//   //    curs_set(1);
// }
