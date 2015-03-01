/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:50:32 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 16:29:17 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include "game.h"

int main(void)
{
	t_env	e;
	char	line[17];

	check_enum();
	ft_bzero(&e, sizeof(t_env));
	init(&e);
	if (e.square_x < 3 || e.square_y < 3)
		end(&e);
	noecho();
	e.fd = open("scores.txt", O_RDWR | O_CREAT, 0644);
	e.i = 0;
	while (read(e.fd, line, 17) > 0)
	{
		if (!ft_memcmp(line, e.player, ft_strlen(e.player)))
		{
			e.hi_score = ft_atoi(line + 8);
			break ;
		}
		(e.i)++;
	}
	play(&e);
	save(&e, e.fd, e.i);
	endwin();
	curs_set(1);
	return (0);
}
