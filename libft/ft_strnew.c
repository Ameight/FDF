/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:39:51 by ejuana            #+#    #+#             */
/*   Updated: 2019/04/14 15:06:14 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;

	if (!(size + 1))
		return (NULL);
	if ((tab = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ft_bzero(tab, size + 1);
	return (tab);
}
