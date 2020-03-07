/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:36:53 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/07 19:52:54 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

int		get_height(char *map_file);
int		get_width(char *map_file);
void	fill_matrix(int *z_line, char *line);
void	read_map(t_fdf *data, char *map_file);
#endif
