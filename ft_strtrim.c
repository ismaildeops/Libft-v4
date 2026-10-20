/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaakoub <marvin@42.fr>                    +#+  +#+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:55:00 by ilaakoub          #+#    #+#             */
/*   Updated: 2026/10/19 17:55:00 by ilaakoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int is_char(char const *set, char c)
{
    int i = 0;
    while (set[i])
    {
        if (set[i] == c)
            return 1;
        i++;
    }
    return 0;
}

char *ft_strtrim(char const *s1, char const *set)
{
    int start = 0;
    int end = 0;
    char *str;
    int i = 0;
    while(s1[end])
        end++;
    end--;
    while (s1[start] && is_char(set,s1[start]))
        start++;

    while (end >= 0 && is_char(set,s1[end]))
        end--;
    str = malloc(sizeof(char) * (end - start) + 1);
    if(!str)
        return NULL;
    while (i <= end - start)
    {
        str[i] = s1[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}