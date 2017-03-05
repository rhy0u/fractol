/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 08:58:11 by jcentaur          #+#    #+#             */
/*   Updated: 2017/03/03 11:03:29 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# define KPM (1L<<0)
# define MNM (1L<<6)
# define KP 2
# define MN 6
# define HEIGHT 500
# define WIDTH 500
# define X1 -2
# define X2 2
# define Y1 -2
# define Y2 2
# define NBTHREADS 1

typedef	struct		s_cd
{
	double			x;
	double			y;
}					t_cd;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_mlx
{
	void			*img;
	void			*mlx;
	void			*win;
	char			*data;
}					t_mlx;

typedef struct		s_info
{
	t_mlx			mlx;
	double			zoom;
	t_cd			image;
	t_cd			min;
	t_cd			max;
	t_cd			c;
	int				sizeline;
	int				endian;
	int				bpp;
	int				iter;
	int				n;
	int				julia;
	int				rand;
	void			(*func[8])(struct s_info *i);
}					t_info;

void				ft_put_pixel_to_image(t_info *i, t_coord pos, int color);
void				mandel(t_info *i);
void				julia(t_info *i);
void				julia4(t_info *i);
void				tricorn(t_info *i);
void				mandel3(t_info *i);
void				mandel5(t_info *i);
void				quinticorn(t_info *i);
int					fractale(t_info *i, char *s);
int					ft_key(int key, t_info *i);
int					ft_mouse(int button, int x, int y, t_info *i);
int					ft_autokey(int key, t_info *i);
int					ft_automouse(int x, int y, t_info *i);
void				ship(t_info *i);
void				ft_move(int x, int y, t_info *i);
void				ft_reset(t_info *i);
void				redraw(t_info *i);
void				usage();
void				help();
void				name(int n);

#endif
