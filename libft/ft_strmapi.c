/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 17:04:51 by pluu              #+#    #+#             */
/*   Updated: 2017/01/19 15:37:36 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char const		*ps;
	char			*pres;
	char			*res;

	if (!s)
		return (NULL);
	if (!f)
		return (NULL);
	if (!(res = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	ps = s;
	pres = res;
	while (*ps)
		*pres++ = f(i++, *ps++);
	*pres = '\0';
	return (res);
}
