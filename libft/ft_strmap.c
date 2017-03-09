/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:43:28 by pluu              #+#    #+#             */
/*   Updated: 2017/01/19 15:36:41 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char const	*ps;
	char		*res;
	char		*pres;

	if (!s)
		return (NULL);
	if (!f)
		return (NULL);
	if (!(res = ft_strnew(ft_strlen(s))))
		return (NULL);
	ps = s;
	pres = res;
	while (*ps)
		*pres++ = f(*ps++);
	*pres = '\0';
	return (res);
}
