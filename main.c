/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:50:32 by mguesner          #+#    #+#             */
/*   Updated: 2015/02/28 14:18:19 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
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
    grid_generate(e.grid, &e);
    grid_generate(e.grid, &e);
    e.score = 0;
    printw("pseudo : ");
	getnstr(e.player, 8);
	int fd = open("scores.txt", O_RDWR | O_CREAT, 0644);
	char line[17];
	i = 0;
	while (read(fd, line, 17) > 0)
	{
		if (!ft_memcmp(line, e.player, ft_strlen(e.player)))
		{
			e.hi_score = ft_atoi(line + 8);
			break;
		}
		i++;
	}
	noecho();
    display(e);
	int ch;
	while ((ch = getch()))
	{
		int test = 0;
		if (ch == KEY_DOWN)
			test = update(e.grid, 3);
		else if (ch == KEY_UP)
			test = update(e.grid, 0);
		else if (ch == KEY_LEFT)
			test = update(e.grid, 1);
		else if (ch == KEY_RIGHT)
			test = update(e.grid, 2);
		else if (ch == 27)
			break;
		getmaxyx(stdscr, e.my, e.mx);
    	e.size = e.mx * e.my;
    	e.square_x = e.mx / 4;
    	e.square_y = e.my / 4;
    	if (test)
    		grid_generate(e.grid, &e);
		display(e);
	}
	if (e.hi_score)
		lseek(fd, i * 17, SEEK_SET);
	e.score = 58745689;
	char buff[17];
	ft_memset(buff, ' ', 16);
	ft_strcpy(buff, e.player);
	ft_strcpy(buff + 8, ft_itoa(e.score));
	buff[16] = '\n';
	write(fd, buff, 17);
	close (fd);
    endwin();
    return (0);
}
