/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:41:59 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 16:08:19 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <libft.h>

void	check_enum(void)
{
	unsigned int	tmp;

	tmp = WIN_VALUE;
	if (tmp < 8)
	{
		ft_putendl_fd("bad win value", 2);
		exit(-1);
	}
	while (tmp)
	{
		if (tmp & 1 && tmp & 4294967294)
		{
			ft_putendl_fd("bad win value", 2);
			exit(-1);
		}
		tmp = tmp >> 1;
	}
}
