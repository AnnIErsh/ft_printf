/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 22:01:40 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 22:02:32 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *s, int c)
{
	if (*s)
	{
		if (*s == (char)c)
			return (char*)s;
		ft_putchar_fd(*s, 1);
		s++;
		return (ft_strchr(s, c));
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
