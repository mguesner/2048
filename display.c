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
}