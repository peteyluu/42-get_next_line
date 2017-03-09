/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 14:53:45 by pluu              #+#    #+#             */
/*   Updated: 2017/01/21 14:54:18 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_issort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int base;
	int r1;
	int r2;

	i = 0;
	base = 0;
	while (i < length - 1)
	{
		r1 = (f(tab[i], tab[i + 1]));
		r2 = (f(tab[i + 1], tab[i]));
		if (base == 0)
		{
			if (r1 < 0)
				base = -1;
			else
				base = 1;
		}
		if ((base < 0 && r2 < 0) || (base > 0 && r2 > 0))
			return (0);
		i++;
	}
	return (1);
}
