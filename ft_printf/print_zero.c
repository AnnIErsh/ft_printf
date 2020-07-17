/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:19:44 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:20:25 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_zero(int edge)
{
	int i;

	i = 0;
	while (i < edge)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
}