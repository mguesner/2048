/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:10:06 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 16:11:22 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	lose(t_env *e)
{
	int	x;
	int	y;
	int	ch;

	y = e->my / 2;
	x = e->mx / 2;
	clear();
	attron(COLOR_PAIR(1));
	mvprintw(y, x, "GAME OVER!");
	mvprintw(y + 2, x, "r : restart");
	mvprintw(y + 4, x, "c : continue");
	mvprintw(y + 6, x, "q : quit");
	while ((ch = getch()))
	{
		if (ch == 'c')
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
