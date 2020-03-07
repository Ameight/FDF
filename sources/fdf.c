/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:48:26 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/07 21:48:27 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		pixel_img(t_mlx *win, t_point dot)
{
	int		point;

	if ((dot.y > 0) && (dot.y < LENGTH) && (dot.x > 0) && (dot.x < WIDE))
	{
		point = ((int)dot.y * win->lsize) + ((int)dot.x * win->bpp / 8);
		if (!win->opt.color)
		{
			win->data[point] = dot.hue.rgb.b;
			win->data[++point] = dot.hue.rgb.g;
			win->data[++point] = dot.hue.rgb.r;
			win->data[++point] = 0xFF;
		}
		else
		{
			win->data[point] = dot.color.rgb.b;
			win->data[++point] = dot.color.rgb.g;
			win->data[++point] = dot.color.rgb.r;
			win->data[++point] = 0xFF;
		}
	}
}