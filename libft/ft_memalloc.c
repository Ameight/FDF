/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:48:22 by ejuana            #+#    #+#             */
/*   Updated: 2019/04/22 18:46:28 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *tab;

	if (!(size + 1))
		return (NULL);
	if ((tab = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(tab, size);
	return (tab);
}
