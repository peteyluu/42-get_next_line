/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:23:41 by pluu              #+#    #+#             */
/*   Updated: 2017/01/17 20:49:26 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = NULL;
	if (!(list = (t_list*)malloc(sizeof(*list))))
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content_size = content_size;
		if (!(list->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(list->content, content, content_size);
	}
	list->next = NULL;
	return (list);
}
