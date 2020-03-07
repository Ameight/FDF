/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:47:13 by ejuana            #+#    #+#             */
/*   Updated: 2019/04/22 17:47:19 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow_uint(int x, unsigned int a)
{
	int		tmp;

	if (a == 0)
		return (1);
	else if (a == 1)
		return (x);
	tmp = x;
	while (a - 1)
	{
		x *= tmp;
		a--;
	}
	return (x);
}
