/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:18:29 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 14:09:32 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <curses.h>
#include <time.h>
#include <stdlib.h>

void	init(t_env *e)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		e->grid[i / 4][i % 4] = 0;
		i++;
	}
	e->grid[2][3] = 2;
	srand(time(NULL));
	initscr();
	raw();
	keypad(stdscr, TRUE);
	start_color();
	ft_init_color();
	getmaxyx(stdscr, e->my, e->mx);
	e->size = e->mx * e->my;
	e->square_x = e->mx / 4;
	e->square_y = e->my / 4;
	e->win = 0;
	e->score = 0;
	printw("pseudo : ");
	getnstr(e->player, 8);
	curs_set(0);
	grid_generate(e->grid, e);
}
