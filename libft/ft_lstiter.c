/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:52:33 by ejuana            #+#    #+#             */
/*   Updated: 2019/04/23 20:21:23 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *tmp;
	t_list *target;

	if (!lst && !f)
		return ;
	target = lst;
	while (target)
	{
		tmp = target->next;
		f(target);
		target = tmp;
	}
}
