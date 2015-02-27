#include <curses.h>

int main()
{
	initscr();
	raw();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	int mx=0, my=0;
	int i = 0;
    initscr();
    getmaxyx(stdscr, my, mx);
    int square_x = mx / 4;
    int square_y = my / 4;
    while (i < mx * my)
    {
    	char tmp;
    	if (!((i / mx) % square_y) && !((i % mx) % square_x))
    		tmp = '+';
    	else if (!((i / mx) % square_y))
    		tmp = '-';
    	else if (!((i % mx) % square_x))
    		tmp = '|';
    	else
    		tmp = ' ';
    	if (mvaddch(i / mx, i % mx, tmp) == ERR)
    		break;
    	i++;
    }
	refresh();
	int ch;
	while ((ch = getch()))
	{
		if (ch == KEY_DOWN)
			;
		else if (ch == KEY_UP)
			;
		else if (ch == KEY_LEFT)
			;
		else if (ch == KEY_RIGHT)
			;
		else if (ch == 27)
			break;
	}

    endwin();
    curs_set(1);
}