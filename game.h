/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:50:32 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 15:31:46 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <curses.h>
# include <time.h>
# include <stdlib.h>
# include <libft.h>

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
	WIN_VALUE = 128
};

typedef struct				s_history
{
	int						grids[20][4][4];
	int						score[20];
	int						index;
	int						stored;
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
	int						win;
	int						fd;
	int						i;
	t_history				history;
}							t_env;

void						display(t_env *e);
int							update(int grid[4][4], int action, t_env *e);
void						grid_generate(int grid[4][4]);
void						ft_init_color();
void						ft_win(t_env *e);
void						play(t_env *e);
void						init(t_env *e);
void						save(t_env *e, int fd, int i);
int							update(int grid[4][4], int action, t_env *e);
void						ft_assign_ret(int *ret, int test);
int							left(int grid[4][4], int original[4][4]);
int							upper(int grid[4][4], int original[4][4]);
int							down(int grid[4][4], int original[4][4]);
int							right(int grid[4][4], int original[4][4]);
void						check_enum(void);

#endif
