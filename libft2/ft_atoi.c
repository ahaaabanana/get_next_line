/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:41:10 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/05/01 15:59:50 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	spaces(const char *str, int i)
{
	return ((str[i] != '\0' &&
		(str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == '	'
			|| str[i] == '\n')));
}

int			ft_atoi(const char *str)
{
	int						i;
	unsigned long long		nb;
	int						s;
	int						count;

	i = 0;
	nb = 0;
	s = 1;
	count = 0;
	while (spaces(str, i))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i++] - '0';
		count++;
	}
	if ((nb > 9223372036854775807 || count >= 20))
		return ((s == 1) ? -1 : 0);
	return (nb * s);
}
