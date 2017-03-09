/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:11:48 by pluu              #+#    #+#             */
/*   Updated: 2017/01/19 16:20:25 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numlen(int n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char		*populate_str(char *s, int n, int isneg)
{
	char *ps;

	ps = s;
	if (isneg)
		*ps++ = '-';
	while (n)
	{
		if (isneg == 1)
			*ps = ((n % 10) * -1) + 48;
		else
			*ps = (n % 10) + 48;
		ps++;
		n /= 10;
	}
	*ps = '\0';
	return (s);
}

char			*ft_itoa(int n)
{
	int		isneg;
	int		len;
	char	*s;

	if (n == 0)
	{
		if (!(s = ft_strnew(1)))
			return (NULL);
		*s = '0';
		*(s + 1) = '\0';
		return (s);
	}
	isneg = 0;
	if (n < 0)
		isneg = 1;
	len = numlen(n);
	if (!(s = ft_strnew(len + isneg)))
		return (NULL);
	return (ft_strrev(populate_str(s, n, isneg)));
}
