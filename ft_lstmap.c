/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaakoub <marvin@42.fr>                    +#+  +#+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 22:08:00 by ilaakoub        #+#    #+#             */
/*   Updated: 2026/10/19 22:08:00 by ilaakoub       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    if(!lst)
        return NULL;
    void    *new_content;
    t_list *new_node;
    t_list *new_lst;
    new_lst = NULL;
    while (lst != NULL)
    {
        new_content = f(lst->content);
        new_node = ft_lstnew(new_content);
        if (!new_node)
        {
            del(new_content);
            ft_lstclear(&new_lst,del);
            return NULL;
        }
        ft_lstadd_back(&new_lst, new_node);
        lst = lst->next;    
    }
    return (new_lst);
}
