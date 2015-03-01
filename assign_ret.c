/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ret.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:12:21 by nguezell          #+#    #+#             */
/*   Updated: 2015/03/01 16:12:37 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_assign_ret(int *ret, int test)
{
	if (test == 1 && (*ret) == 0)
		(*ret) = 1;
	else if ((*ret) == 1 && test > 1)
		(*ret) = test;
	else
		(*ret) += (test > 1) ? test : 0;
}
