/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:43:37 by mguesner          #+#    #+#             */
/*   Updated: 2014/02/02 08:35:52 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isblank(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
			|| c == '\f')
		return (1);
	return (0);
}
