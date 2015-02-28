/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:50:32 by mguesner          #+#    #+#             */
/*   Updated: 2015/02/28 11:54:53 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <fcntl.h>
#include "game.h"
int main()
{
	t_env e;
	int i = 0;
	while (i < 16)
	{
		e.grid[i / 4][i % 4] = 0;
		i++;
	}
	e.grid[2][3] = 2;
	initscr();
	raw();
	keypad(stdscr, TRUE);
    getmaxyx(stdscr, e.my, e.mx);
    e.size = e.mx * e.my;
    e.square_x = e.mx / 4;
    e.square_y = e.my / 4;
    grid_generate(e.grid);
    grid_generate(e.grid);
    e.score = 0;
    printw("pseudo : ");
	getnstr(e.player, 8);
	//int fd = open("scores.txt", O_RDWR | O_CREAT, 0644);
	//while (getline() >= 0)
	noecho();
    display(e);
	int ch;
	while ((ch = getch()) != ERR)
	{
		if (ch == KEY_DOWN)
			update(e.grid, 3);
		else if (ch == KEY_UP)
			update(e.grid, 0);
		else if (ch == KEY_LEFT)
			update(e.grid, 1);
		else if (ch == KEY_RIGHT)
			update(e.grid, 2);
		else if (ch == 27)
			break;
		getmaxyx(stdscr, e.my, e.mx);
    	e.size = e.mx * e.my;
    	e.square_x = e.mx / 4;
    	e.square_y = e.my / 4;
    	grid_generate(e.grid);
		display(e);
	}

    endwin();
    return (0);
}