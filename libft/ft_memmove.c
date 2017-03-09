/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:02:35 by pluu              #+#    #+#             */
/*   Updated: 2017/01/09 15:19:55 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pdst;
	const char	*psrc;

	pdst = dst;
	psrc = src;
	if (psrc < pdst)
	{
		pdst += len;
		psrc += len;
		while (len--)
			*(--pdst) = *(--psrc);
	}
	else
		while (len--)
			*pdst++ = *psrc++;
	return (dst);
}
