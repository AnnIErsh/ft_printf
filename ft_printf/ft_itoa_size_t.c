/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_size_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:24:08 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:27:45 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_swap_size_t(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	ft_mem_count_size_t(size_t n, int count)
{
	if (n)
	{
		count++;
		return (ft_mem_count_size_t(n / 10, count));
	}
	return (count + 1);
}

static void	ft_reverse_size_t(char *str, size_t length)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		ft_swap_size_t((str + start), (str + end));
		start++;
		end--;
	}
}

static void	ft_devide_itoa_size_t(long int n, char *numbs, size_t i)
{
	if (n > 9)
	{
		*(numbs + i) = (n % 10) + '0';
		i++;
		ft_devide_itoa_size_t(n / 10, numbs, i);
	}
	else
		*(numbs + i) = (n % 10) + '0';
}

char		*ft_itoa_size_t(size_t n)
{
	char	*numbs;
	size_t	len;

	if (n == 0)
		return (ft_strdup("0"));
	numbs = ft_calloc(ft_mem_count_size_t(n, 0), 1);
	if (!numbs)
		return (NULL);
	if (n == 0)
		*numbs = '0';
	ft_devide_itoa_size_t(n, numbs, 0);
	len = ft_strlen(numbs);
	ft_reverse_size_t(numbs, len);
	*(numbs + len) = '\0';
	return (numbs);
}
