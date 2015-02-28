/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:50:32 by mguesner          #+#    #+#             */
/*   Updated: 2015/02/28 14:00:41 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <curses.h>

void	display(t_env e)
{
	int i;

    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_BLACK, COLOR_RED);
    i = 0;
	while (i < e.size)
    {
        attron(COLOR_PAIR(2));
    	char tmp;
    	if (!((i / e.mx) % e.square_y) && !((i % e.mx) % e.square_x) && i / e.mx != 0 && i % e.mx != 0 && i / e.mx != 4 * e.square_y
            && i % e.mx != 4 * e.square_x)
    		tmp = '+';
    	else if (!((i / e.mx) % e.square_y) && (i % e.mx) < 4 * e.square_x && i / e.mx != 0 && i / e.mx != 4 * e.square_y)
    		tmp = '-';
    	else if (!((i % e.mx) % e.square_x) && (i / e.mx) < 4 * e.square_y && i % e.mx != 0 && i % e.mx != 4 * e.square_x)
    		tmp = '|';
    	else
        {
            if ((i / e.mx) / e.square_y < 4 && (i % e.mx) / e.square_x < 4 && e.grid[(i / e.mx) / e.square_y][(i % e.mx) / e.square_x] == 2)
                attron(COLOR_PAIR(1));
            else if ((i / e.mx) / e.square_y < 4 && (i % e.mx) / e.square_x < 4 && e.grid[(i / e.mx) / e.square_y][(i % e.mx) / e.square_x] == 4)
                attron(COLOR_PAIR(3));
            else if ((i / e.mx) / e.square_y < 4 && (i % e.mx) / e.square_x < 4 && e.grid[(i / e.mx) / e.square_y][(i % e.mx) / e.square_x] == 8)
                attron(COLOR_PAIR(4));
    		tmp = ' ';
        }
    	mvaddch(i / e.mx + 1, i % e.mx, tmp);
    	i++;
    }
    i = 0;
    attron(COLOR_PAIR(2));
    mvprintw(0, 0, "player : %s, score : %d, hi-score : %d", e.player, e.score, e.hi_score);
    while (i < 16)
    {
        if (e.grid[i / 4][i % 4] == 2)
            attron(COLOR_PAIR(1));
        else if (e.grid[i / 4][i % 4] == 4)
            attron(COLOR_PAIR(3));
        else if (e.grid[i / 4][i % 4] == 8)
            attron(COLOR_PAIR(4));
        else
            attron(COLOR_PAIR(2));
		if (e.grid[i / 4][i % 4])
			mvprintw((i / 4) * e.square_y + e.square_y / 2, (i % 4) * e.square_x + e.square_x / 2, "%d", e.grid[i / 4][i % 4]);
		i++;
    }
}
