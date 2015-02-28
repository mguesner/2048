/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:50:32 by mguesner          #+#    #+#             */
/*   Updated: 2015/02/28 16:13:44 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <curses.h>

void	display(t_env e)
{
	int		i;
	int		j;
	char	tmp;
	int		tmp2;

	i = 0;
	while (i < e.size)
	{
		attron(COLOR_PAIR(1));
		if (!((i / e.mx) % e.square_y) && !((i % e.mx) % e.square_x)
			&& i / e.mx != 0 && i % e.mx != 0 && i / e.mx != 4 * e.square_y
			&& i % e.mx != 4 * e.square_x)
			tmp = '+';
		else if (!((i / e.mx) % e.square_y) && (i % e.mx) < 4 * e.square_x
			&& i / e.mx != 0 && i / e.mx != 4 * e.square_y)
			tmp = '-';
		else if (!((i % e.mx) % e.square_x) && (i / e.mx) < 4 * e.square_y
			&& i % e.mx != 0 && i % e.mx != 4 * e.square_x)
			tmp = '|';
		else
		{
			tmp2 = 0;
			if ((i / e.mx) / e.square_y < 4 && (i % e.mx) / e.square_x < 4)
				tmp2 = e.grid[(i / e.mx) / e.square_y][(i % e.mx) / e.square_x];
			j = 0;
			while (tmp2)
			{
				tmp2 = tmp2 >> 1;
				j++;
			}
			attron(COLOR_PAIR(j));
			tmp = ' ';
		}
		mvaddch(i / e.mx + 1, i % e.mx, tmp);
		i++;
	}
	i = 0;
	attron(COLOR_PAIR(1));
	mvprintw(0, 0, "player : %s, score : %d, hi-score : %d"
		, e.player, e.score, e.hi_score);
	while (i < 16)
	{
		if (e.grid[i / 4][i % 4] == 2)
			attron(COLOR_PAIR(2));
		else if (e.grid[i / 4][i % 4] == 4)
			attron(COLOR_PAIR(3));
		else if (e.grid[i / 4][i % 4] == 8)
			attron(COLOR_PAIR(4));
		else if (e.grid[i / 4][i % 4] == 16)
			attron(COLOR_PAIR(5));
		else if (e.grid[i / 4][i % 4] == 32)
			attron(COLOR_PAIR(6));
		else if (e.grid[i / 4][i % 4] == 64)
			attron(COLOR_PAIR(7));
		else if (e.grid[i / 4][i % 4] == 128)
			attron(COLOR_PAIR(8));
		else if (e.grid[i / 4][i % 4] == 256)
			attron(COLOR_PAIR(9));
		else if (e.grid[i / 4][i % 4] == 512)
			attron(COLOR_PAIR(10));
		else if (e.grid[i / 4][i % 4] == 1024)
			attron(COLOR_PAIR(11));
		else if (e.grid[i / 4][i % 4] == 2048)
			attron(COLOR_PAIR(12));
		else
			attron(COLOR_PAIR(1));
		if (e.grid[i / 4][i % 4])
			mvprintw((i / 4) * e.square_y + e.square_y / 2
				, (i % 4) * e.square_x + e.square_x / 2, "%d", e.grid[i / 4][i % 4]);
		i++;
	}
}
