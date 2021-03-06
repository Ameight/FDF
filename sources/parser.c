/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:49:27 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/07 21:49:29 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_map(int lines, t_point **map)
{
	int		i;

	i = 0;
	while (i < lines)
		free(map[i++]);
	free(map);
}

t_point		**allocate_memory_for_map(t_point point)
{
	int		i;
	t_point	**map;

	i = 0;
	if ((map = (t_point **)malloc((point.y) * sizeof(t_point *)))
			== NULL)
		error_notice("Malloc error");
	while (i < point.y)
	{
		if ((map[i] = (t_point *)malloc((point.x)
				* sizeof(t_point))) == NULL)
		{
			free_map(i, map);
			error_notice("Lines malloc error");
		}
		i++;
	}
	return (map);
}
#include "stdio.h"
t_point		**fill_map(t_mlx win, t_point **map, char **stock)
{
	int		i;
	int		j;
	char	**line;

	i = -1;
	while (++i < win.map.y)
	{
		if (win.map.x != ft_word_counter(stock[i], ' '))
			error_notice("wrong coordinate number");
		j = -1;
		line = ft_strsplit(stock[i], ' ');
		while (++j < win.map.x)
			map[i][j] = set_xyz(j, i, line[j], win.opt.hue.hex_color);
		free_str(line);
	}
	return (map);
}

t_point		**validator(char *buf, t_mlx *win)
{
	char	**stock;
	t_point	**map;

	win->map.y = ft_word_counter(buf, '\n');
	stock = ft_strsplit(buf, '\n');
	win->map.x = ft_word_counter(stock[0], ' ');
	map = allocate_memory_for_map(win->map);
	map = fill_map(*win, map, stock);
	free_str(stock);
	return (map);
}

void		reader(int fd)
{
	char	buf[BUFF_SIZE];
	t_point	**map;
	t_mlx	*win;

	read(fd, buf, BUFF_SIZE);
	win = window(WIDE, LENGTH);
	map = validator(buf, win);
	win->list = map;
	draw_map(win, map);
	mlx_put_image_to_window(win->mp, win->wp, win->img, 0, 0);
	mlx_loop(win->mp);
}
