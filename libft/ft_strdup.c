/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:33:44 by pluu              #+#    #+#             */
/*   Updated: 2017/01/09 16:43:29 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *str;
	char *tmp;

	str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + 1));
	if (!str)
		return (0);
	tmp = str;
	while (*s1)
		*tmp++ = *s1++;
	*tmp = '\0';
	return (str);
}
