/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:57:09 by nguezell          #+#    #+#             */
/*   Updated: 2015/03/01 16:10:00 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	upthis(int grid[4][4], int original[4][4], int j, int i)
{
	int	value;
	int	tmp;

	value = grid[j][i];
	tmp = j;
	j--;
	while (j >= 0)
	{
		if (grid[j][i] == value && original[j][i] == 0 && (grid[j][i] *= 2)
			&& !(grid[tmp][i] = 0)
			&& (original[j][i] = 1))
			return (grid[j][i]);
		else if (grid[j][i] && !(grid[tmp][i] = 0)
			&& (grid[j + 1][i] = value))
			return (tmp - (j + 1));
		else if (!j)
		{
			grid[tmp][i] = 0;
			grid[j][i] = value;
			return (1);
		}
		j--;
	}
	return (0);
}

int			upper(int grid[4][4], int original[4][4])
{
	int	i;
	int	ret;
	int	j;
	int	test;

	i = 0;
	ret = 0;
	while (i < 4)
	{
		j = 1;
		while (j <= 3)
		{
			if (grid[j][i])
			{
				if ((test = upthis(grid, original, j, i)))
					ft_assign_ret(&ret, test);
			}
			j++;
		}
		i++;
	}
	return (ret);
}
