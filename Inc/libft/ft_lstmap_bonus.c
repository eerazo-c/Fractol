/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:40:59 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/01/31 18:41:21 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*node;
	void	*ptrf;

	node = 0;
	while (lst)
	{
		ptrf = f(lst->content);
		newnode = ft_lstnew(ptrf);
		if (!newnode)
		{
			free(ptrf);
			ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&node, newnode);
		lst = lst->next;
	}
	return (node);
}
