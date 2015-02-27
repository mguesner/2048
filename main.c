#include <curses.h>

int main()
{
	initscr();
	raw();
	curs_set(0);
	noecho();
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
    	// printw("i = %d, mx = %d, my = %d, i / my = %d, i %% mx = %d", i, mx, my, i / my, i % mx);
    	if (mvaddch(i / mx, i % mx, tmp) == ERR)
    		break;
    	i++;
    	// if (getch() == 27)
    	// 	break;
    }
	refresh();
    getch();
    endwin();
    printf("%d %d\n", mx, my);
    curs_set(1);
}