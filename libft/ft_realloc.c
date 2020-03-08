/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 06:05:25 by ejuana            #+#    #+#             */
/*   Updated: 2019/05/03 06:22:06 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*dptr;

	if (!size)
	{
		ft_memdel(&ptr);
		return (ptr);
	}
	if (!ptr)
		return (malloc(size));
	dptr = malloc(size);
	if (!dptr)
		return (NULL);
	dptr = ft_memcpy(dptr, ptr, size);
	ft_memdel(&ptr);
	return (dptr);
}
