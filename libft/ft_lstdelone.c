/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 20:16:43 by pluu              #+#    #+#             */
/*   Updated: 2017/01/19 16:36:19 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (!alst)
		return ;
	if (!*alst)
		return ;
	if (!del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void**)alst);
}
