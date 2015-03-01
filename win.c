/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:25:18 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 15:29:31 by mguesner         ###   ########.fr       */
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
	mvprintw(y, x, "YOU WIN!");
	mvprintw(y + 2, x + 2, "r : restart");
	mvprintw(y + 4, x + 4, "c : continue");
	while ((ch = getch()))
	{
		keypad(stdscr, FALSE);
		if (ch == 'c')
			e->win = 1;
		// else if (ch == 'r')
		// 	reset(e);
		else if (ch == 27)
		{
			endwin();
			curs_set(1);
			save(e, e->fd, e->i);
			exit(0);
		}
	}
	keypad(stdscr, TRUE);
	display(e);
}
