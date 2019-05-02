/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:37:30 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/25 17:26:58 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *f;
	t_list *x;

	if (!(alst && *alst && del))
		return ;
	f = *alst;
	while (f)
	{
		x = f;
		ft_lstdelone(&f, del);
		f = x->next;
	}
	*alst = NULL;
}
