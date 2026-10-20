/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaakoub <marvin@42.fr>                    +#+  +#+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:55:00 by ilaakoub          #+#    #+#             */
/*   Updated: 2026/10/19 17:55:00 by ilaakoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int is_char(char str_char, char c)
{
    return(str_char == c);
}
static int count_words(char const *str, char c)
{
    int i = 0;
    int count = 0;
    if (!is_char(str[0], c))
    {
        count++;
    }
    while (str[i])
    {
        if (is_char(str[i], c))
        {
            if (!is_char(str[i+1], c) && str[i + 1] !=  '\0')
            {
                count++;
            }
        }
        i++;
    }
    return count;
}
char **ft_split(char const *s, char c)
{
    char **words;
    int start;
    int end;
    int k;
    int j = 0;
    words = malloc(sizeof(char *) * (count_words(s,c) + 1));
    if(!words)
        return NULL;
    
    int i = 0;
    while (s[i])
    {
        while(is_char(s[i],c))
			i++;
		start = i;
		while(!is_char(s[i],c) && s[i])
		{
			i++;
		}
		end = i;
		words[j] = malloc(sizeof(char) * (end - start) + 1);
		if (!words[j])
			return (NULL);
		k = 0;
		while(k < end - start)
		{
			words[j][k] = s[start + k];
			k++;
		}
		words[j][end - start] = '\0';
		j++;
	}
	words[j] = NULL;
	return words; 
}
int main()
{ 
    char **str;
    char const s[] = "Helloalllalllalll";
    str = ft_split(s, 'a');
    int i = 0;
	while(str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	return 0;
}
