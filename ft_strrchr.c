/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaakoub <marvin@42.fr>                    +#+  +#+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:55:00 by ilaakoub          #+#    #+#             */
/*   Updated: 2026/10/19 17:55:00 by ilaakoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int s_len = 0;
	unsigned char ch;
	ch = (unsigned char)c;
    while (s[s_len])
        s_len++;
    while (s_len >= 0)
    {
        if ((unsigned char)s[s_len] == ch)    
            return (char *)&s[s_len];
        s_len--;
    }
    return NULL;
} 
