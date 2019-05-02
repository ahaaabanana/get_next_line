/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:39:51 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/04/25 18:37:55 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*toplist;

	if (!lst)
		return (NULL);
	toplist = f(lst);
	newlist = toplist;
	while (lst->next)
	{
		if (!(newlist->next = f(lst->next)))
		{
			free(toplist);
			return (NULL);
		}
		lst = lst->next;
		newlist = newlist->next;
	}
	return (toplist);
}
