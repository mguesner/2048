/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:55:13 by nguezell          #+#    #+#             */
/*   Updated: 2015/03/01 14:58:53 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	pop_new(int grid[4][4], int position, int value)
{
	int empty;
	int i;
	int j;

	empty = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (grid[i][j] == 0 && empty == position)
			{
				grid[i][j] = value;
				return ;
			}
			if (grid[i][j] == 0)
				empty++;
			j++;
		}
		i++;
	}
}

void	grid_generate(int grid[4][4])
{
	int	i;
	int	empty;
	int j;
	int position;

	i = 0;
	empty = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (grid[i][j] == 0)
				empty++;
			j++;
		}
		i++;
	}
	if (empty == 0)
		return ;
	position = (empty == 1) ? 0 : rand() % empty;
	i = rand() % 100;
	j = i > 95 ? 4 : 2;
	pop_new(grid, position, j);
}
