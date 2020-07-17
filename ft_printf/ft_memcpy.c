/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:36:40 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:38:05 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*copy;
	size_t			i;
	size_t			j;

	copy = (unsigned char*)src;
	i = n;
	j = 0;
	while (i)
	{
		if (dst == copy)
			return (dst);
		copy++;
		i--;
	}
	while (n)
	{
		*(unsigned char*)dst++ = *(unsigned char*)src++;
		n--;
		j++;
	}
	return (dst - j);
}
