/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 11:06:53 by jcentaur          #+#    #+#             */
/*   Updated: 2017/03/03 10:16:05 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		fractale(t_info *i, char *s)
{
	if (!ft_strcmp(s, "julia"))
		i->n = 0;
	else if (!ft_strcmp(s, "mandelbrot"))
		i->n = 1;
	else if (!ft_strcmp(s, "mandel3"))
		i->n = 2;
	else if (!ft_strcmp(s, "ship"))
		i->n = 3;
	else if (!ft_strcmp(s, "tricorn"))
		i->n = 4;
	else if (!ft_strcmp(s, "mandel5"))
		i->n = 5;
	else if (!ft_strcmp(s, "quinticorn"))
		i->n = 6;
	else if (!ft_strcmp(s, "julia4"))
		i->n = 7;
	else
		i->n = -1;
	return (i->n);
}
