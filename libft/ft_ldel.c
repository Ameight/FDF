/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 21:56:33 by ejuana            #+#    #+#             */
/*   Updated: 2019/05/09 02:29:48 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_ldel(t_list *prev, t_list *curr)
{
	prev->next = curr->next;
	curr->next = NULL;
	free(curr->content);
	free(curr);
	curr = NULL;
	return (prev);
}
