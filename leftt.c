/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:58:56 by nguezell          #+#    #+#             */
/*   Updated: 2015/03/01 13:58:42 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

int	leftthis(int grid[4][4], int original[4][4], int j, int i)
{
	int value = grid[j][i];
	int tmp = i;
	i--;
	while (i >= 0)
	{
		if (grid[j][i] == value && original[j][i] == 0 && (grid[j][i] *= 2)
			&& !(grid[j][tmp] = 0)
			&& (original[j][i] = 1))
			return (grid[j][i]);
		else if (grid[j][i] && !(grid[j][tmp] = 0)
			&& (grid[j][i + 1] = value))
			return (tmp - (i + 1 ));
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
	int j = 0;
	int ret = 0;
	int test;
	while (j < 4)
	{
		int i = 1;
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
