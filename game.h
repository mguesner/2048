/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:50:32 by mguesner          #+#    #+#             */
/*   Updated: 2015/02/28 17:37:01 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define BLACK				20
# define WHITE				21
# define COLOR_2			22
# define COLOR_4			23
# define COLOR_8			24
# define COLOR_16			25
# define COLOR_32			26
# define COLOR_64			27
# define COLOR_128			28
# define COLOR_256			29
# define COLOR_512			30
# define COLOR_1024			31
# define COLOR_2048			32

enum						e_const
{
	WIN_VALUE = 2048
};

typedef struct				s_history
{
	int						grids[20][4][4];
	int						score[20];
	int						index;
	int						back;
}							t_history;

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
	t_history				history;
}							t_env;



void						display(t_env e);
int							update(int grid[4][4], int action, t_env *e);
void						grid_generate(int grid[4][4], t_env *e);
void						ft_init_color();

#endif
