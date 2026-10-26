/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaakoub <marvin@42.fr>                    +#+  +#+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:33:30 by ilaakoub          #+#    #+#             */
/*   Updated: 2026/10/22 13:33:30 by ilaakoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memmove_copy(const unsigned char *s, unsigned char *d,
		size_t n)
{
	size_t	i;

	i = 0;
	if (s < d)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (n == 0)
		return (dest);
	if (dest == NULL || src == NULL)
		return (NULL);
	s = src;
	d = dest;
	ft_memmove_copy(s, d, n);
	return (dest);
}
