/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:10:47 by pluu              #+#    #+#             */
/*   Updated: 2017/01/19 16:32:28 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*curr;

	if (!lst)
		return (NULL);
	if (!f)
		return (NULL);
	new_lst = NULL;
	new_lst = f(lst);
	lst = lst->next;
	curr = new_lst;
	while (lst)
	{
		curr->next = f(lst);
		curr = curr->next;
		lst = lst->next;
	}
	return (new_lst);
}
