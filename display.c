/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:50:32 by mguesner          #+#    #+#             */
/*   Updated: 2015/02/28 11:46:21 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <curses.h>

void	display(t_env e)
{
	int i;

    i = 0;
	while (i < e.size)
    {
    	char tmp;
    	if (!((i / e.mx) % e.square_y) && !((i % e.mx) % e.square_x) && i / e.mx != 0 && i % e.mx != 0 && i / e.mx != 4 * e.square_y && i % e.mx != 4 * e.square_x)
    		tmp = '+';
    	else if (!((i / e.mx) % e.square_y) && (i % e.mx) < 4 * e.square_x && i / e.mx != 0 && i / e.mx != 4 * e.square_y)
    		tmp = '-';
    	else if (!((i % e.mx) % e.square_x) && (i / e.mx) < 4 * e.square_y && i % e.mx != 0 && i % e.mx != 4 * e.square_x)
    		tmp = '|';
    	else
    		tmp = ' ';
    	mvaddch(i / e.mx + 1, i % e.mx, tmp);
    	i++;
    }
    i = 0;
    mvprintw(0, 0, "player : %s, score : %d, hi-score : %d", e.player, e.score, e.hi_score);
    while (i < 16)
    {
		if (e.grid[i / 4][i % 4])
			mvprintw((i / 4) * e.square_y + e.square_y / 2, (i % 4) * e.square_x + e.square_x / 2, "%d", e.grid[i / 4][i % 4]);
		i++;
    }
}
