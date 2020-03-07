/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   S_lines.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:48:45 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/07 21:48:48 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		create_proj(t_mlx *win, t_point **tab, t_point (*f)(t_mlx, t_point))
{
	int		i;
	int		j;
	t_point	a;
	t_point	b;

	i = -1;
	while (++i < win->map.y - 1)
	{
		j = -1;
		while (++j < win->map.x - 1)
		{
			a = f(*win, tab[i][j]);
			b = f(*win, tab[i][j + 1]);
			brezeham(win, line(a, b));
			b = f(*win, tab[i + 1][j]);
			brezeham(win, line(a, b));
		}
		brezeham(win, line(f(*win, tab[i][j]), f(*win, tab[i + 1][j])));
	}
	j = -1;
	while (++j < win->map.x - 1)
	{
		brezeham(win, line(f(*win, tab[i][j]), f(*win, tab[i][j + 1])));
	}
}

void		draw_map(t_mlx *win, t_point **map)
{
	const void	*projection = NULL;

	if (win->opt.axis == 0)
		projection = (draw_dots_isometric);
	else if (win->opt.axis == -1)
		projection = draw_dots_parallel;
	create_proj(win, map, projection);
}
