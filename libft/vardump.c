/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_dump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:31:59 by ejuana            #+#    #+#             */
/*   Updated: 2019/10/23 00:04:38 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*vardump(char *str, int a)
{
	str = ft_strjoin(str, ":");
	str = ft_strjoin(str, ft_itoa(a));
	str = ft_strjoin(str, "\n");
	return (str);
}
