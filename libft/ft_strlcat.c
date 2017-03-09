/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:14:03 by pluu              #+#    #+#             */
/*   Updated: 2017/01/18 16:39:17 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		n;
	size_t		dlen;
	char		*pd;
	const char	*ps;

	n = size;
	pd = dst;
	ps = src;
	while (*pd && n--)
		pd++;
	dlen = pd - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (*ps)
	{
		if (n != 1)
		{
			*pd++ = *ps;
			n--;
		}
		ps++;
	}
	*pd = '\0';
	return (dlen + ps - src);
}
