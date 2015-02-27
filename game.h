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
}							t_env;

void	display(t_env e);

#endif