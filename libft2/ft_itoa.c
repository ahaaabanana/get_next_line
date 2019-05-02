/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:36:29 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/15 17:36:35 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char		*x;
	int			size;
	long long	nb;

	size = 1;
	nb = n;
	if (n < 0)
		size++;
	while (n /= 10)
		size++;
	if (!(x = ft_strnew(size)))
		return (NULL);
	if (nb < 0)
	{
		x[0] = '-';
		nb = -nb;
	}
	if (!nb)
		x[--size] = nb % 10 + '0';
	while (nb)
	{
		x[--size] = nb % 10 + '0';
		nb /= 10;
	}
	return (x);
}
