/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:50:42 by jcentaur          #+#    #+#             */
/*   Updated: 2017/03/01 19:16:16 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static	int	iter(t_cd z, t_cd c, int iter)
{
	int		inc;
	double	tmp;

	inc = 0;
	while (z.x * z.x + z.y * z.y < 4 && inc < iter)
	{
		tmp = (z.x * z.x - z.y * z.y) + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp;
		inc++;
	}
	return (inc);
}

void		mandel(t_info *i)
{
	t_coord		pos;
	t_cd		c;
	t_cd		z;
	int			inc;

	pos.x = 0;
	i->image.x = (i->max.x - i->min.x) * i->zoom;
	i->image.y = (i->max.y - i->min.y) * i->zoom;
	while (pos.x < i->image.x)
	{
		pos.y = 0;
		while (pos.y < i->image.y)
		{
			c.x = pos.x / i->zoom + i->min.x;
			c.y = pos.y / i->zoom + i->min.y;
			z.x = 0;
			z.y = 0;
			inc = iter(z, c, i->iter);
			if (inc != i->iter)
				ft_put_pixel_to_image(i, pos, inc * i->rand);
			pos.y++;
		}
		pos.x++;
	}
}
