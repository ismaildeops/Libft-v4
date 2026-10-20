/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaakoub <marvin@42.fr>                    +#+  +#+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:55:00 by ilaakoub          #+#    #+#             */
/*   Updated: 2026/10/19 17:55:00 by ilaakoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static size_t	ft_num_len(unsigned int n)
{
	size_t	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	size_t			len;
	int				negative;

	negative = (n < 0);
	if (negative)
		num = (unsigned int)(-(n + 1)) + 1; //HANDLING INT_MIN -2147483648 -> -2147483647 -> 2147483647
	else
		num = (unsigned int)n;
	len = ft_num_len(num) + negative;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > (size_t)negative)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
