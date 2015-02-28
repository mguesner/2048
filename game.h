/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:50:32 by mguesner          #+#    #+#             */
/*   Updated: 2015/02/28 11:54:17 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct				s_env
{
	int						mx;
	int						my;
	int						size;
	int						square_x;
	int						square_y;
	int						grid[4][4];
	char					player[9];
	int						score;
	int						hi_score;
}							t_env;

void	display(t_env e);
void	update(int grid[4][4], int action);
void    grid_generate(int grid[4][4]);

#endif