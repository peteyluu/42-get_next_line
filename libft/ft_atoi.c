/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:41:52 by pluu              #+#    #+#             */
/*   Updated: 2017/01/19 18:07:59 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int	isneg;
	int	res;

	res = 0;
	isneg = 1;
	while (*str == '\t' || *str == '\v' || *str == '\f' ||
			*str == '\r' || *str == ' ' || *str == '\n')
		str++;
	if (*str == '-')
		isneg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * isneg);
}
