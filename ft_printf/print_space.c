/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:20:51 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:21:38 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_space(int size, int diff)
{
	int	i;

	i = 0;
	if (size > diff)
	{
		while (i < size - diff)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
}
