/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:20:56 by ejuana            #+#    #+#             */
/*   Updated: 2019/04/19 18:20:56 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iswhitespace(int c)
{
	char	ch;

	ch = (char)c;
	if (ch == ' ' || ch == '\n' || ch == '\t')
		return (1);
	return (0);
}
