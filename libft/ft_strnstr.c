/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:54:29 by pluu              #+#    #+#             */
/*   Updated: 2017/01/11 20:24:35 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	cnt;

	if (!ft_strlen(little))
		return ((char*)big);
	cnt = 0;
	while (*big && len--)
	{
		if (*big == *little)
		{
			little++;
			if (*little == '\0')
				return ((char*)big - cnt);
			cnt++;
		}
		else if (cnt > 0)
		{
			len += cnt;
			little -= cnt;
			big -= cnt;
			cnt = 0;
		}
		big++;
	}
	return (0);
}
