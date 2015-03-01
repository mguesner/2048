/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:10:23 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 15:28:33 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <curses.h>

void	back(int grid[4][4], t_env *e)
{
	int	i;

	if (!(e->history.stored))
		return ;
	i = (e->history.index) ? e->history.index - 1 : 19;
	ft_memcpy(&(grid[0]), &(e->history.grids[i][0]), sizeof(int) * 16);
	e->history.stored -= 1;
	e->history.index = i;
	e->score = e->history.score[i];
}

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
		else if (ch == 'b')
			back(e->grid, e);
		getmaxyx(stdscr, e->my, e->mx);
		e->size = e->mx * e->my;
		e->square_x = e->mx / 4;
		e->square_y = e->my / 4;
		if (test)
			grid_generate(e->grid);
		display(e);
	}
}
