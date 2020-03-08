/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezeham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:47:58 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/07 21:48:02 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		brezeham(t_mlx *win, t_line l)
{
	float	x;
	float	y;
	int		end;

	x = (l.dir) ? (l.d0.x) : (l.d0.y);
	y = (l.dir) ? (l.d0.y) : (l.d0.x);
	end = (l.dir) ? (l.d1.x) : (l.d1.y);
	--x;
	if (l.dir)
		while (++x <= end)
		{
			pixel_img(win, set_dot_c(x, y, l.d0.hue.hex_color));
			y += l.k;
		}
	else
		while (++x <= end)
		{
			pixel_img(win, set_dot_c(y, x, l.d0.hue.hex_color));
			y += l.k;
		}
}
