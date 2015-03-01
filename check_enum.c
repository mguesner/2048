/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:41:59 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 14:55:26 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <libft.h>

void	check_enum(void)
{
	int	tmp;

	tmp = WIN_VALUE;
	if (tmp < 4)
	{
		ft_putendl_fd("bad win value", 2);
		exit(-1);
	}
	while (tmp)
	{
		if (tmp & 1 && tmp & 0b11111110)
		{
			ft_putendl_fd("bad win value", 2);
			exit(-1);
		}
		tmp = tmp >> 1;
	}
}
