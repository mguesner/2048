/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:58:48 by nguezell          #+#    #+#             */
/*   Updated: 2015/03/01 14:05:27 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	rightthis(int grid[4][4], int original[4][4], int j, int i)
{
	int	value;
	int	tmp;

	value = grid[j][i];
	tmp = i;
	i++;
	while (i <= 3)
	{
		if (grid[j][i] == value && original[j][i] == 0 && (grid[j][i] *= 2)
			&& !(grid[j][tmp] = 0)
			&& (original[j][i] = 1))
			return (grid[j][i]);
		else if (grid[j][i] && !(grid[j][tmp] = 0)
			&& (grid[j][i - 1] = value))
			return (i - 1 - tmp);
		else if (i == 3)
		{
			grid[j][tmp] = 0;
			grid[j][i] = value;
			return (1);
		}
		i++;
	}
	return (0);
}

int	right(int grid[4][4], int original[4][4])
{
	int	j;
	int	i;
	int	ret;
	int	test;

	j = 0;
	ret = 0;
	while (j < 4)
	{
		i = 2;
		while (i >= 0)
		{
			if (grid[j][i])
			{
				if ((test = rightthis(grid, original, j, i)))
					ft_assign_ret(&ret, test);
			}
			i--;
		}
		j++;
	}
	return (ret);
}
