/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:58:40 by nguezell          #+#    #+#             */
/*   Updated: 2015/03/01 16:15:38 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		downthis(int grid[4][4], int original[4][4], int j, int i)
{
	int	value;
	int	tmp;

	value = grid[j][i];
	tmp = j;
	j++;
	while (j <= 3)
	{
		if (grid[j][i] == value && original[j][i] == 0 && (grid[j][i] *= 2)
			&& !(grid[tmp][i] = 0)
			&& (original[j][i] = 1))
			return (grid[j][i]);
		else if (grid[j][i] && !(grid[tmp][i] = 0)
			&& (grid[j - 1][i] = value))
			return (j - 1 - tmp);
		else if (j == 3)
		{
			grid[tmp][i] = 0;
			grid[j][i] = value;
			return (1);
		}
		j++;
	}
	return (0);
}

int				down(int grid[4][4], int original[4][4])
{
	int i;
	int j;
	int ret;
	int test;

	i = 0;
	ret = 0;
	while (i < 4)
	{
		j = 2;
		while (j >= 0)
		{
			if (grid[j][i])
			{
				if ((test = downthis(grid, original, j, i)))
					ft_assign_ret(&ret, test);
			}
			j--;
		}
		i++;
	}
	return (ret);
}
