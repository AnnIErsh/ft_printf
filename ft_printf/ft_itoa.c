/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:29:00 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:33:18 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	ft_mem_count(int n, int count)
{
	if (n)
	{
		count++;
		return (ft_mem_count(n / 10, count));
	}
	return (count + 1);
}

static void	ft_reverse(char *str, size_t length)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		ft_swap((str + start), (str + end));
		start++;
		end--;
	}
}

static void	ft_devide_itoa(long int n, char *numbs, size_t i)
{
	if (n > 9)
	{
		*(numbs + i) = (n % 10) + '0';
		i++;
		ft_devide_itoa(n / 10, numbs, i);
	}
	else
		*(numbs + i) = (n % 10) + '0';
}

char		*ft_itoa(int n)
{
	char	*numbs;
	int		sign;
	size_t	len;

    sign = (n < 0) ? 1 : 0;
	if (n == -2147483648)
		return (ft_strdup("2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	numbs = ft_calloc(ft_mem_count(n, 0) + sign, 1);
	if (!numbs)
		return (NULL);
	if (n == 0)
		*numbs = '0';
	sign == 1 ? n *= -1 : n;
	ft_devide_itoa(n, numbs, 0);
	len = ft_strlen(numbs);
	if (sign == 1)
	{
		*(numbs + len) = '-';
		len += 1;
	}
	ft_reverse(numbs, len);
	*(numbs + len) = '\0';
	return (numbs);
}
