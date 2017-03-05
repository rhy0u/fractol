/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 11:53:19 by jcentaur          #+#    #+#             */
/*   Updated: 2017/03/03 10:45:40 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	redraw(t_info *i)
{
	ft_bzero(i->mlx.data, WIDTH * HEIGHT * 4);
	i->func[i->n](i);
	mlx_put_image_to_window(i->mlx.mlx, i->mlx.win, i->mlx.img, 0, 0);
}

int		ft_mouse(int button, int x, int y, t_info *i)
{
	t_cd	min;
	t_cd	ecart;

	min = i->min;
	ecart.x = i->max.x - i->min.x;
	ecart.y = i->max.y - i->min.y;
	if (button == 5 || button == 6)
	{
		i->zoom *= 1.1;
		i->min.x += (float)x / WIDTH * (ecart.x - ecart.x / 1.1);
		i->min.y += (float)y / HEIGHT * (ecart.y - ecart.y / 1.1);
		i->max.x -= (WIDTH - (float)x) / WIDTH * (ecart.x - ecart.x / 1.1);
		i->max.y -= (HEIGHT - (float)y) / HEIGHT * (ecart.y - ecart.y / 1.1);
	}
	else if (button == 4 || button == 7)
	{
		i->zoom /= 1.1;
		i->min.x -= (float)x / WIDTH * (-ecart.x + ecart.x * 1.1);
		i->min.y -= (float)y / HEIGHT * (-ecart.y + ecart.y * 1.1);
		i->max.x += ((WIDTH - (float)x) / WIDTH) * (-ecart.x + ecart.x * 1.1);
		i->max.y += ((HEIGHT - (float)y) / HEIGHT) * (-ecart.y + ecart.y * 1.1);
	}
	redraw(i);
	return (0);
}

int		ft_key(int key, t_info *i)
{
	if (key == 53)
		exit(0);
	else if (key == 15)
		ft_reset(i);
	else if (key == 8)
	{
		i->n++;
		i->n = i->n % 8;
		name(i->n);
	}
	else if (key == 49)
		i->julia = (i->julia) ? 0 : 1;
	else if (key == 4)
		help();
	redraw(i);
	return (0);
}
