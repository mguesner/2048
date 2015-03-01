/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:53:14 by nguezell          #+#    #+#             */
/*   Updated: 2015/03/01 15:01:43 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		update(int grid[4][4], int action, t_env *e)
{
	int	ret;
	int	original[4][4];
	int	index;

	ft_bzero(original, 16 * sizeof(int));
	index = e->history.index;
	ft_memcpy(&(e->history.grids[index][0]), &(grid[0]), sizeof(int) * 16);
	if (action == 0)
		ret = upper(grid, original);
	else if (action == 1)
		ret = left(grid, original);
	else if (action == 2)
		ret = right(grid, original);
	else
		ret = down(grid, original);
	if (ret)
	{
		e->score += (ret <= 1) ? 0 : ret;
		e->history.score[index] = e->score;
		e->history.index += 1;
		e->history.index %= 20;
	}
	return (ret);
}
