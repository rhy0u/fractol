/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:16:56 by jcentaur          #+#    #+#             */
/*   Updated: 2017/03/03 10:47:10 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	help(void)
{
	ft_putstrcol("Keyboard:\n\n", yellow);
	ft_putstrcol("Arrows\t\t\t\tto move the map\n", yellow);
	ft_putstrcol("L\t\t\t\tto randomize the color\n", yellow);
	ft_putstrcol("H\t\t\t\tto get help\n", yellow);
	ft_putstrcol("R\t\t\t\tto reset values\n", yellow);
	ft_putstrcol("I/O\t\t\t\tto up increase/decrease the maximum iteration\n",
		yellow);
	ft_putstrcol("Space\t\t\t\tto play with julia likes C's values \
with the mouse\n", yellow);
	ft_putstrcol("C\t\t\t\tto change the fractal \n", yellow);
	ft_putstrcol("\nMouse:\n\n", yellow);
	ft_putstrcol("Scroll up/down\t\t\tto zoom in/out\n", yellow);
}

void	usage(void)
{
	ft_putstrcol("Usage: ./fract_ol\t[fractal] [fractal]\n", red);
	ft_putstrcol("\t\t\t[julia]\n", green);
	ft_putstrcol("\t\t\t[julia4]\n", green);
	ft_putstrcol("\t\t\t[mandelbrot]\n", green);
	ft_putstrcol("\t\t\t[mandel3]\n", green);
	ft_putstrcol("\t\t\t[mandel5]\n", green);
	ft_putstrcol("\t\t\t[ship]\n", green);
	ft_putstrcol("\t\t\t[tricorn]\n", green);
	ft_putstrcol("\t\t\t[quinticorn]\n", green);
}

void	name(int n)
{
	if (n == 0)
		ft_putstrcol("julia\n\n", cyan);
	else if (n == 1)
		ft_putstrcol("mandelbrot\n\n", cyan);
	else if (n == 2)
		ft_putstrcol("mandel3\n\n", cyan);
	else if (n == 3)
		ft_putstrcol("ship\n\n", cyan);
	else if (n == 4)
		ft_putstrcol("tricorn\n\n", cyan);
	else if (n == 5)
		ft_putstrcol("mandel5\n\n", cyan);
	else if (n == 6)
		ft_putstrcol("quinticorn\n\n", cyan);
	else if (n == 7)
		ft_putstrcol("julia4\n\n", cyan);
}
