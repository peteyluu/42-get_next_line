/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 18:34:29 by pluu              #+#    #+#             */
/*   Updated: 2017/01/19 15:51:09 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	chr_cnt(char **as, char c)
{
	size_t	cnt;

	cnt = 0;
	while (**as == c && **as)
		(*as)++;
	while (**as != c && **as)
	{
		cnt++;
		(*as)++;
	}
	return (cnt);
}

static char		*populate_str(char **as, char c)
{
	size_t	w_len;
	char	*s;
	char	*ps;

	w_len = chr_cnt(as, c);
	if (!(s = ft_strnew(w_len)))
		return (NULL);
	ps = s;
	(*as) -= w_len;
	while (w_len--)
	{
		*ps = **as;
		(*as)++;
		ps++;
	}
	*ps = '\0';
	return (s);
}

static void		dealloc(char **arr, size_t len)
{
	while (len--)
	{
		free(*arr);
		arr++;
	}
	free(arr);
	arr = NULL;
}

static char		**populate_arr(char **arr, size_t len, char **as, char c)
{
	size_t	dup_len;
	char	**parr;

	dup_len = len;
	parr = arr;
	while (dup_len--)
	{
		if (!(*parr = populate_str(as, c)))
		{
			dealloc(arr, dup_len + 1);
			return (NULL);
		}
		parr++;
	}
	*parr = NULL;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	w_cnt;
	char	*ps;
	char	**arr;

	if (!s)
		return (NULL);
	if ((w_cnt = ft_wordcnt(s, c)) == 0)
	{
		if (!(arr = (char**)malloc(sizeof(char*) * 1)))
			return (NULL);
		*arr = NULL;
		return (arr);
	}
	if (!(arr = (char**)malloc(sizeof(char*) * (w_cnt + 1))))
		return (NULL);
	ps = (char*)s;
	if (!(arr = populate_arr(arr, w_cnt, &ps, c)))
		return (NULL);
	return (arr);
}
