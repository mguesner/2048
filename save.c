/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:23:29 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 14:40:41 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include "game.h"

void	save(t_env *e, int fd, int i)
{
	char	buff[17];

	if (e->hi_score)
		lseek(fd, i * 17, SEEK_SET);
	ft_memset(buff, ' ', 16);
	ft_strcpy(buff, e->player);
	ft_strcpy(buff + 8, ft_itoa(e->score));
	buff[16] = '\n';
	write(fd, buff, 17);
	close (fd);
}
