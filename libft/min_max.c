/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 06:22:15 by ejuana            #+#    #+#             */
/*   Updated: 2019/09/25 06:25:12 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min(int a, int b)
{
	return ((a > b) ? (b) : (a));
}

int		ft_max(int a, int b)
{
	return ((a < b) ? (b) : (a));
}

float	ft_fmin(float a, float b)
{
	return ((a > b) ? (b) : (a));
}

float	ft_fmax(float a, float b)
{
	return ((a < b) ? (b) : (a));
}
