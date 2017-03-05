/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:16:29 by jcentaur          #+#    #+#             */
/*   Updated: 2017/03/02 16:22:21 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_arrow(int key, t_info *i)
{
	t_cd	taille;

	taille.x = i->max.x - i->min.x;
	taille.y = i->max.y - i->min.y;
	if (key == 123)
	{
		i->min.x += taille.x / 100;
		i->max.x += taille.x / 100;
	}
	else if (key == 124)
	{
		i->min.x -= taille.x / 100;
		i->max.x -= taille.x / 100;
	}
	else if (key == 125)
	{
		i->min.y -= taille.y / 100;
		i->max.y += taille.y / 100;
	}
	else if (key == 126)
	{
		i->min.y += taille.y / 100;
		i->max.y += taille.y / 100;
	}
}

int		ft_autokey(int key, t_info *i)
{
	if (key == 37)
		i->rand = rand() / 500;
	else if (key == 34)
		i->iter += 5;
	else if (key == 31 && i->iter > 10)
		i->iter -= 5;
	else
		ft_arrow(key, i);
	redraw(i);
	return (0);
}

int		ft_automouse(int x, int y, t_info *i)
{
	t_cd	ecart;

	ecart.x = i->max.x - i->min.x;
	ecart.y = i->max.y - i->min.y;
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT || !i->julia)
		return (0);
	i->c.x = (double)x / WIDTH * 1.99 - 1;
	i->c.y = (double)y / HEIGHT;
	redraw(i);
	return (0);
}
