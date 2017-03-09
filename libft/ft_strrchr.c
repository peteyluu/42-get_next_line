/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:28:57 by pluu              #+#    #+#             */
/*   Updated: 2017/01/13 14:15:15 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ps;
	const char	*pres;

	ps = s;
	pres = 0;
	while (*ps)
	{
		if (*ps == c)
			pres = ps;
		ps++;
	}
	if (*ps == c)
		pres = ps;
	return ((pres) ? (char*)pres : 0);
}
