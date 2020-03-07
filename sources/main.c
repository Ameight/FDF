/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:49:17 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/07 21:49:19 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close_window(void *ptr)
{
	exit(0);
	ptr = NULL;
	return (0);
}

int		key_event(int key, void *p_void)
{
	t_mlx	*win;

	win = (t_mlx *)p_void;
	if (key == kVK_ANSI_A || key == kVK_ANSI_D)
		projection(key, win);
	ft_bzero(win->data, win->l * win->w * sizeof(int));
	draw_map(win, win->list);
	mlx_put_image_to_window(win->mp, win->wp, win->img, 0, 0);
	return (0);
}

void	options(t_mlx *win)
{
	win->opt.axis = 1;
	win->opt.hue.hex_color = LIME;
	win->scale = 2;
}

t_mlx	*window(int w, int l)
{
	t_mlx	*win;

	if ((win = (t_mlx *)malloc(sizeof(t_mlx))) == NULL)
		error_notice("malloc win");
	options(win);
	win->w = w;
	win->l = l;
	win->mid[X] = w / 2;
	win->mid[Y] = l / 2;
	win->mp = mlx_init();
	win->wp = mlx_new_window(win->mp, w, l, "fdf");
	if ((win->img = mlx_new_image(win->mp, win->w, win->l)) == NULL)
		error_notice("mlx_new_image error");
	if ((win->data = mlx_get_data_addr(win->img,
			&(win->bpp), &(win->lsize), &(win->endian))) == NULL)
		error_notice("mlx_get_data_addr error");
	mlx_hook(win->wp, 17, 0, close_window, &win);
	mlx_hook(win->wp, 2, 0, key_event, win);
	mlx_key_hook(win->wp, escape_handle, (void *)0);
	return (win);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		symb[2];

	fd = 0;
	if (argc == 1)
		error_notice("no file");
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (read(fd, symb, 0) < 0)
			error_notice("Error file");
	}
	else
		error_notice("Too much arguments");
	if (fd == -1)
		error_notice("File opening error");
	reader(fd);
	return (0);
}
