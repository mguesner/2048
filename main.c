/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:50:32 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 13:26:43 by mguesner         ###   ########.fr       */
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
	int		i;
	int		fd;
	char	line[17];

	init(&e);
	fd = open("scores.txt", O_RDWR | O_CREAT, 0644);
	i = 0;
	while (read(fd, line, 17) > 0)
	{
		if (!ft_memcmp(line, e.player, ft_strlen(e.player)))
		{
			e.hi_score = ft_atoi(line + 8);
			break ;
		}
		i++;
	}
	play(&e);
	save(&e, fd, i);
	endwin();
	curs_set(1);
	return (0);
}
