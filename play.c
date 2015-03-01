/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:10:23 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 14:59:48 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <curses.h>

void	play(t_env *e)
{
	int		ch;
	int		test;

	display(e);
	while ((ch = getch()))
	{
		test = 0;
		if (ch == KEY_DOWN)
			test = update(e->grid, 3, e);
		else if (ch == KEY_UP)
			test = update(e->grid, 0, e);
		else if (ch == KEY_LEFT)
			test = update(e->grid, 1, e);
		else if (ch == KEY_RIGHT)
			test = update(e->grid, 2, e);
		else if (ch == 27)
			break ;
		getmaxyx(stdscr, e->my, e->mx);
		e->size = e->mx * e->my;
		e->square_x = e->mx / 4;
		e->square_y = e->my / 4;
		if (test)
			grid_generate(e->grid);
		display(e);
	}
}
