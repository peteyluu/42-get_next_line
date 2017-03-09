/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:32:43 by pluu              #+#    #+#             */
/*   Updated: 2017/01/14 13:55:46 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*pres;

	if (!s)
		return (NULL);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	pres = res;
	s += start;
	while (len-- && *s)
		*pres++ = *s++;
	*pres = '\0';
	return (*pres == '\0' ? res : NULL);
}
