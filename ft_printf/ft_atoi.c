/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:41:06 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:42:54 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_iswhitespace(int c)
{
	if (c == '\t' || c == '\n' || c == ' '
					|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int	res;
	int	sum;
	int	sign;

	res = 0;
	sum = 0;
	sign = 1;
	while (ft_iswhitespace(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		*str == '-' ? sign = -1 : sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum + res % 10) * 10;
		res = (*str - '0');
		str++;
	}
	res = (sum + res) * sign;
	return (res);
}
