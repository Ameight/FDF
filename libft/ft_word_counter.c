/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:33:33 by ejuana            #+#    #+#             */
/*   Updated: 2019/04/22 17:18:11 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_word_counter(char const *s, char c)
{
	int		count;
	char	*tmp;

	tmp = (char *)s;
	count = 0;
	while (*tmp)
	{
		while (*tmp && *tmp == c)
			tmp++;
		if (*tmp)
			count++;
		while (*tmp && *tmp != c)
			tmp++;
	}
	return (count);
}
