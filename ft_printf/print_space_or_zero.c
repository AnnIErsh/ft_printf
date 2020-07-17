/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space_or_zero.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:18:14 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:19:12 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_space_or_zero(int size, int diff, int zero)
{
	int	i;

	i = 0;
	if (size > diff)
	{
		while (i < size - diff)
		{
			if (zero == 1)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
}
