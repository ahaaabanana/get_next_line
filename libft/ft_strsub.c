/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whybread <whybread@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:12:53 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/05/07 18:49:46 by whybread         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	strsize;

	if (!s)
		return (NULL);
	i = 0;
	strsize = ft_strlen(s);
	substr = (char*)malloc(sizeof(*substr) * len + 1);
	if (substr)
	{
		while (i < len && (start + i) < strsize)
		{
			substr[i] = s[start + i];
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}
