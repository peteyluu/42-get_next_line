/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:13:06 by pluu              #+#    #+#             */
/*   Updated: 2017/01/21 13:35:05 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	if (!alst)
		return ;
	if (!new)
		return ;
	while (*alst)
	{
		if ((*alst)->next == NULL)
		{
			(*alst)->next = new;
			break ;
		}
		alst = &((*alst)->next);
	}
}
