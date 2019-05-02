/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:07:10 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/15 18:07:40 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*strnew;
	size_t	i;

	i = 0;
	strnew = (char*)malloc(sizeof(*strnew) * size + 1);
	if (strnew)
	{
		while (i < size + 1)
			strnew[i++] = '\0';
	}
	return (strnew);
}
