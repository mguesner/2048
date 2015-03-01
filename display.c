/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:50:32 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 15:55:32 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <curses.h>

static void		display2(t_env *e, int x, int y)
{
	int		tmp;
	int		j;

	attron(COLOR_PAIR(1));
	if (!(y % e->square_y) && !(x % e->square_x) && y != 0
		&& x != 0 && y != 4 * e->square_y && x != 4 * e->square_x)
		tmp = '+';
	else if (!(y % e->square_y) && x < 4 * e->square_x && y != 0
		&& y != 4 * e->square_y)
		tmp = '-';
	else if (!(x % e->square_x) && y < 4 * e->square_y
		&& x != 0 && x != 4 * e->square_x)
		tmp = '|';
	else
	{
		tmp = 0;
		if (y / e->square_y < 4 && x / e->square_x < 4)
			tmp = e->grid[y / e->square_y][x / e->square_x];
		j = 0;
		while (tmp && ++j)
			tmp = tmp >> 1;
		attron(COLOR_PAIR(j));
		tmp = ' ';
	}
	mvaddch(y + 1, x, tmp);
}

static int		display3(t_env *e, int i)
{
	int		win;
	int		tmp;
	int		j;

	tmp = e->grid[i / 4][i % 4];
	if (tmp == WIN_VALUE)
		win = 1;
	j = 0;
	while (tmp && ++j)
		tmp = tmp >> 1;
	attron(COLOR_PAIR(j));
	if (e->grid[i / 4][i % 4])
		mvprintw((i / 4) * e->square_y + e->square_y / 2
			, (i % 4) * e->square_x + e->square_x / 2
			, "%d", e->grid[i / 4][i % 4]);
	return (win);
}

void			display(t_env *e)
{
	int		i;
	int		win;
	int		x;
	int		y;

	i = 0;
	while (i < e->size)
	{
		x = i % e->mx;
		y = i / e->mx;
		display2(e, x, y);
		i++;
	}
	i = 0;
	attron(COLOR_PAIR(1));
	mvprintw(0, 0, "player : %s, score : %d, hi-score : %d"
		, e->player, e->score, e->hi_score > e->score ? e->hi_score : e->score);
	win = 0;
	while (i < 16)
	{
		win = display3(e, i);
		i++;
	}
	if (win == 1 && !e->win)
		ft_win(e);
}
