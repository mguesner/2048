/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:58:56 by nguezell          #+#    #+#             */
/*   Updated: 2015/03/01 14:15:46 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	leftthis(int grid[4][4], int original[4][4], int j, int i)
{
	int	value;
	int	tmp;

	value = grid[j][i];
	tmp = i;
	i--;
	while (i >= 0)
	{
		if (grid[j][i] == value && original[j][i] == 0 && (grid[j][i] *= 2)
			&& !(grid[j][tmp] = 0)
			&& (original[j][i] = 1))
			return (grid[j][i]);
		else if (grid[j][i] && !(grid[j][tmp] = 0)
			&& (grid[j][i + 1] = value))
			return (tmp - (i + 1));
		else if (!i)
		{
			grid[j][tmp] = 0;
			grid[j][i] = value;
			return (1);
		}
		i--;
	}
	return (0);
}

int	left(int grid[4][4], int original[4][4])
{
	int	j;
	int	ret;
	int	test;
	int	i;

	j = 0;
	ret = 0;
	while (j < 4)
	{
		i = 1;
		while (i <= 3)
		{
			if (grid[j][i])
			{
				if ((test = leftthis(grid, original, j, i)))
					ft_assign_ret(&ret, test);
			}
			i++;
		}
		j++;
	}
	return (ret);
}
