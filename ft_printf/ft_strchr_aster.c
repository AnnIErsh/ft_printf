/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_aster.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:59:53 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 22:00:53 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr_aster(const char *s, int c)
{
	if (*s)
	{
		if (*s == '%')
			return (NULL);
		if (*s == (char)c)
			return (char*)s;
		s++;
		return (ft_strchr_aster(s, c));
	}
	if ((char)c == '\0' || (char)c == '%')
		return ((char *)s);
	return (NULL);
}
