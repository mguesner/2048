/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:25:18 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 16:24:21 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include "game.h"

void	ft_win(t_env *e)
{
	int	x;
	int	y;
	int	ch;

	y = e->my / 2;
	x = e->mx / 2;
	clear();
	attron(COLOR_PAIR(1));
	while ((ch = getch()))
	{
		mvprintw(y, x, "YOU WIN!");
		mvprintw(y + 2, x, "r : restart");
		mvprintw(y + 4, x, "c : continue");
		mvprintw(y + 6, x, "q : quit");
		if (ch == 'c' && (e->win = 1))
			break ;
		else if (ch == 'r')
		{
			reset(e);
			break ;
		}
		else if (ch == 'q')
			end(e);
	}
	display(e);
}
