/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:47:18 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/07 21:47:24 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

/*
** ************************************************************************** **
** Include
** ************************************************************************** **
*/

# include "../libft/libft.h"
# include "keys.h"
# include "/usr/local/include/mlx.h"
# include <math.h>

/*
** ************************************************************************** **
** Define
** ************************************************************************** **
*/

# define LEN 100
# define PI 3.14159265359
# define WIDE 1600
# define LENGTH 1440

# define AQUA 0x00ffff
# define BLACK 0x000000
# define BLUE 0x0000ff
# define FUCHSIA 0xff00ff
# define GRAY 0x808080
# define GREEN 0x008000
# define LIME 0x00ff00
# define MAROON 0x800000
# define NAVY 0x000080
# define OLIVE 0x808000
# define PURPLE 0x800080
# define RED 0xff0000
# define SILVER 0xc0c0c0
# define TEAL 0x008080
# define WHITE 0xffffff
# define YELLOW 0xffff00

/*
** ************************************************************************** **
** Definition and typedef
** ************************************************************************** **
*/

typedef char*		t_string;

typedef struct		s_argb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_argb;

typedef union		u_color
{
	int				hex_color;
	t_argb			rgb;
}					t_color;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	t_color			hue;
	t_color			color;
}					t_point;

typedef struct		s_opt
{
	short			color;
	short			axis;
	t_color			hue;
}					t_opt;

enum				e_o{Y, X};

typedef struct		s_mlx
{
	void			*mp;
	void			*wp;
	int				w;
	int				l;
	int				mid[2];
	t_point			map;
	unsigned int	scale;
	t_opt			opt;
	t_point			**list;
	int				bpp;
	int				lsize;
	int				endian;
	char			*data;
	void			*img;
}					t_mlx;

typedef struct		s_line
{
	t_point			d0;
	t_point			d1;
	short			dir;
	float			k;
	short			show;
}					t_line;

/*
** ************************************************************************** **
** Function
** ************************************************************************** **
*/

/*
**					main.c
*/

t_mlx				*window(int w, int l);

/*
**					fdf.c
*/

void				pixel_img(t_mlx *win, t_point dot);

/*
**					draw_lines.c
*/

void				brezeham(t_mlx *win, t_line l);

/*
**					struct.c
*/

t_point				set_dot(float x, float y);

t_point				set_dot_c(float x, float y, int hue);

t_point				set_xyz(float x, float y, char *z_color, int color);

void				swap_glist(t_point *a, t_point *b);

t_line				line(t_point a, t_point b);

/*
**					lines.c
*/

void				draw_map(t_mlx *win, t_point **map);

/*
**					projection.c
*/

t_point				draw_dots_isometric(t_mlx win, t_point dot);

t_point				draw_dots_parallel(t_mlx win, t_point dot);

/*
**					events.c
*/

int					escape_handle(int key);

void				projection(int key, t_mlx *win);

/*
**					handler.c
*/

void				reader(int fd);

#endif
