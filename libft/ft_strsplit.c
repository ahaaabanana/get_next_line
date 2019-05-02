/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:09:39 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/05/02 11:22:37 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	arr_length(char const *s, char c)
{
	size_t	res;
	size_t	i;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			res++;
		}
		else
			i++;
	}
	return (res);
}

static char		*word_lenght(char *x, char **arri, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (*x != '\0' && *x == c)
		x++;
	while (*x != '\0' && *x != c)
	{
		res++;
		x++;
	}
	*arri = (char*)malloc(sizeof(**arri) * (res + 1));
	if (!arri)
		return (NULL);
	x = x - res;
	while (i < res)
	{
		(*arri)[i] = x[i];
		i++;
	}
	(*arri)[i] = '\0';
	return (x + res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	char	*x;
	size_t	arr_len;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	x = (char*)s;
	arr_len = arr_length(s, c);
	if (!(arr = (char**)malloc(sizeof(*arr) * arr_len + 1)))
		return (NULL);
	while (i < arr_len)
	{
		x = word_lenght(x, arr + i, c);
		if (!x)
		{
			while (*arr)
				free((*arr)++);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
