/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:27:00 by pluu              #+#    #+#             */
/*   Updated: 2017/01/13 14:13:11 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ps;

	ps = s;
	while (n--)
	{
		if (*ps == (unsigned char)c)
			return ((void*)ps);
		ps++;
	}
	return (0);
}
