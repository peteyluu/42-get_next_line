/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:51:01 by pluu              #+#    #+#             */
/*   Updated: 2017/01/19 11:27:35 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcnt(char const *s, char c)
{
	size_t	wc;
	int		state;
	int		in;

	wc = 0;
	state = 0;
	in = 0;
	while (*s)
	{
		if (*s == c)
		{
			state = 1;
			in = 1;
		}
		else if (in == 0)
			state = 1;
		if (state == 1 && (in == 0 || ((*(s + 1) != c) && (*(s + 1) != '\0'))))
		{
			wc++;
			state = 0;
			in = 1;
		}
		s++;
	}
	return (wc);
}
