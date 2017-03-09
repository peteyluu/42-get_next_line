/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:54:23 by pluu              #+#    #+#             */
/*   Updated: 2017/01/14 18:25:43 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(int c)
{
	return ((c == ' ' || c == '\n' || c == '\t') ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	char const	*ps;
	char		*res;
	size_t		vars[2];

	if (!s)
		return (NULL);
	ps = s;
	vars[0] = 0;
	while (is_whitespace(*ps++))
		vars[0]++;
	vars[1] = ft_strlen(s);
	ps = s + (vars[1] - 1);
	while (is_whitespace(*ps--))
		vars[1]--;
	if (vars[0] < vars[1])
	{
		if (!(res = ft_strsub(s, vars[0], vars[1] - vars[0])))
			return (NULL);
	}
	else
	{
		if (!(res = ft_strnew(0)))
			return (NULL);
	}
	return (res);
}
