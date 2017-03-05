/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:56:26 by jcentaur          #+#    #+#             */
/*   Updated: 2017/03/03 10:23:20 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_reset(t_info *i)
{
	i->c.x = .285;
	i->c.y = .01;
	i->min.x = X1;
	i->max.x = X2;
	i->min.y = Y1;
	i->max.y = Y2;
	i->julia = 0;
	i->iter = 50;
	i->zoom = WIDTH / (X2 - X1);
	i->rand = 40000;
}

void	ft_create(t_info *i)
{
	ft_reset(i);
	i->func[0] = julia;
	i->func[1] = mandel;
	i->func[2] = mandel3;
	i->func[3] = ship;
	i->func[4] = tricorn;
	i->func[5] = mandel5;
	i->func[6] = quinticorn;
	i->func[7] = julia4;
	i->mlx.img = mlx_new_image(i->mlx.mlx, WIDTH, HEIGHT);
	i->mlx.data = mlx_get_data_addr(i->mlx.img, &i->bpp, &i->sizeline,
			&i->endian);
}

void	instance(t_info *i)
{
	ft_create(i);
	i->func[i->n](i);
	i->mlx.win = mlx_new_window(i->mlx.mlx, WIDTH, HEIGHT, "fractol");
	mlx_put_image_to_window(i->mlx.mlx, i->mlx.win, i->mlx.img, 0, 0);
	mlx_mouse_hook(i->mlx.win, ft_mouse, i);
	mlx_key_hook(i->mlx.win, ft_key, i);
	mlx_hook(i->mlx.win, MN, MNM, ft_automouse, i);
	mlx_hook(i->mlx.win, KP, KPM, ft_autokey, i);
}

int		main(int ac, char **av)
{
	t_info		info[2];

	srand(time(NULL));
	if (ac == 2 || ac == 3)
	{
		info[0].mlx.mlx = mlx_init();
		if (ac == 3)
		{
			info[1].mlx.mlx = info[0].mlx.mlx;
			if (fractale(&info[1], av[2]) != -1)
				instance(&info[1]);
		}
		if (fractale(&info[0], av[1]) != -1)
			instance(&info[0]);
		if (info[0].n == -1 || info[1].n == -1)
			usage();
		if ((info[0].n == -1 && ac == 2)
			|| ((info[0].n == -1 && info[1].n == -1 && ac == 3)))
			return (0);
		help();
		mlx_loop(info[0].mlx.mlx);
	}
	else
		usage();
	return (0);
}
