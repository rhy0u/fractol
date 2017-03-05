/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 21:51:33 by jcentaur          #+#    #+#             */
/*   Updated: 2017/03/02 14:35:11 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_put_pixel_to_image(t_info *i, t_coord pos, int color)
{
	int		tmp;

	if (pos.x >= WIDTH || pos.y >= HEIGHT
			|| pos.x < 0 || pos.y < 0)
		return ;
	if (i->endian == 0)
	{
		tmp = (i->sizeline * (pos.y)) + ((pos.x) * (i->bpp / 8));
		i->mlx.data[tmp] = mlx_get_color_value(i->mlx.img, color);
		i->mlx.data[tmp + 1] = mlx_get_color_value(i->mlx.img, color >> 8);
		i->mlx.data[tmp + 2] = mlx_get_color_value(i->mlx.img, color >> 16);
	}
	else
	{
		tmp = (i->sizeline * (pos.y)) + ((pos.x) * (i->bpp / 8));
		i->mlx.data[tmp + 2] = mlx_get_color_value(i->mlx.img, color >> 16);
		i->mlx.data[tmp + 1] = mlx_get_color_value(i->mlx.img, color >> 8);
		i->mlx.data[tmp] = mlx_get_color_value(i->mlx.img, color);
	}
}
