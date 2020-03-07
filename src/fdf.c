/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:42:17 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/07 20:25:25 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf		*data;
	int 		i;
	int 		j;

	if(argc == 2)
	{
		data = (t_fdf*)malloc(sizeof(t_fdf));
		read_map(data, argv[1]);
		i = 0;
		while (i < data->height)
		{
			j = 0;
			while (j < data->width)
			{
				ft_putnbr(data->z_matrix[i][j]);
				ft_putchar(' ');
				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}
}
