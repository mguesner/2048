/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:55:13 by nguezell          #+#    #+#             */
/*   Updated: 2015/03/01 13:02:39 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

void	grid_generate(int grid[4][4], t_env *e)
{
	(void) e;
	int i = 0;
	int empty = 0;
	while (i < 4)
	{
		int j = 0;
		while (j < 4)
		{
			if (grid[i][j] == 0)
			empty++;
				j++;
		}
		i++;
	}
	if (empty == 0)
	{
	  //ft_putstr("FAIL OMG QUIT THAT SHIT\n")
		exit(0);
	  return;   //ERROR OMG
	}
	int position = (empty == 1) ? 0 : rand() % empty;
	int test = rand() % 100;
	int value = test > 95 ? 4 : 2;
	empty = 0;
	i = 0;
	while (i < 4)
	{
		int j = 0;
		while (j < 4)
		{
			if (grid[i][j] == 0 && empty == position)
			{
				grid[i][j] = value;
				return;
			}
			if (grid[i][j] == 0)
				empty++;
			j++;
		}
		i++;
	}
}
