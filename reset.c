/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:39:23 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 15:52:52 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	reset(t_env *e)
{
	save(e, e->fd, e->i);
	e->hi_score = e->score;
	e->score = 0;
	ft_bzero(e->grid, 16 * sizeof(int));
	grid_generate(e->grid);
	grid_generate(e->grid);
	ft_bzero(&(e->history), sizeof(t_history));
}
