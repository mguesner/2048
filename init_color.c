/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:29:17 by mguesner          #+#    #+#             */
/*   Updated: 2015/03/01 13:53:55 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include "game.h"  
#include <stdlib.h>

void	ft_init_color()
{
	start_color();
	init_color(WHITE, 1000, 1000, 1000);
	init_color(BLACK, 0, 0, 0);
	init_color(COLOR_2, 1000, 1000, 1000);
	init_color(COLOR_4, 1000, 800, 800);
	init_color(COLOR_8, 1000, 600, 600);
	init_color(COLOR_16, 1000, 400, 400);
	init_color(COLOR_32, 1000, 200, 200);
	init_color(COLOR_64, 1000, 0, 0);
	init_color(COLOR_128, 1000, 0, 200);
	init_color(COLOR_256, 1000, 0, 400);
	init_color(COLOR_512, 1000, 0, 600);
	init_color(COLOR_1024, 1000, 0, 800);
	init_color(COLOR_2048, 1000, 0, 1000);
	init_pair(1, WHITE, BLACK);
	init_pair(2, BLACK, COLOR_2);
	init_pair(3, BLACK, COLOR_4);
	init_pair(4, BLACK, COLOR_8);
	init_pair(5, BLACK, COLOR_16);
	init_pair(6, BLACK, COLOR_32);
	init_pair(7, BLACK, COLOR_64);
	init_pair(8, BLACK, COLOR_128);
	init_pair(9, BLACK, COLOR_256);
	init_pair(10, BLACK, COLOR_512);
	init_pair(11, BLACK, COLOR_1024);
	init_pair(12, BLACK, COLOR_2048);
}