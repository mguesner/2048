#include <curses.h>
#include "game.h"
int main()
{
	t_env e;
	initscr();
	raw();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
    initscr();
    getmaxyx(stdscr, e.my, e.mx);
    e.size = e.mx * e.my;
    e.square_x = e.mx / 4;
    e.square_y = e.my / 4;
    display(e);
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
		display(e);
	}

    endwin();
    curs_set(1);
}