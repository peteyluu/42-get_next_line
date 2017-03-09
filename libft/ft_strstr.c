/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:19:20 by pluu              #+#    #+#             */
/*   Updated: 2017/01/11 20:25:35 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	cnt;

	if (!ft_strlen(little))
		return ((char*)big);
	cnt = 0;
	while (*big)
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
			little -= cnt;
			big -= cnt;
			cnt = 0;
		}
		big++;
	}
	return (0);
}
