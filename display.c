#include "game.h"
#include <curses.h>

void	display(t_env e)
{
	int i = 0;
	while (i < e.size)
    {
    	char tmp;
    	if (!((i / e.mx) % e.square_y) && !((i % e.mx) % e.square_x))
    		tmp = '+';
    	else if (!((i / e.mx) % e.square_y))
    		tmp = '-';
    	else if (!((i % e.mx) % e.square_x))
    		tmp = '|';
    	else
    		tmp = ' ';
    	if (mvaddch(i / e.mx, i % e.mx, tmp) == ERR)
    		break;
    	i++;
    }
    i = 0;
    while (i < 16)
    {
		if (e.grid[i / 4][i % 4])
			mvprintw((i / 4) * e.square_y + e.square_y / 2, (i % 4) * e.square_x + e.square_x / 2, "%d", e.grid[i / 4][i % 4]);
		i++;
    }
    refresh();
}
