/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:06:12 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:10:00 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_pointer_pos(va_list ***content)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_fd_hex(va_arg(***content, intptr_t), 1, 87);
}

static void	print_without_zero(va_list ***content, int diff)
{
	ft_putstr_fd("0x", 1);
	while (diff)
	{
		ft_putchar_fd('0', 1);
		diff--;
	}
	ft_putnbr_fd_hex(va_arg(***content, intptr_t), 1, 87);
}

static void	print_func(int *step, va_list ***content, int diff)
{
	print_space(step[0], diff);
	print_pointer_pos(&(*content));
}

void		manage_pointer(va_list **content, int *step, int *aster)
{
	int		diff;
	va_list	copy;

	add_values_with_asters(aster, step, &content);
	if (step[0] > 0)
	{
		va_copy(copy, **content);
		diff = ft_devide_hex_pos(va_arg(copy, intptr_t), 87, 0) + 1 + 2;
		va_end(copy);
		if (step[2] == 1)
			print_without_zero(&content, step[0] - diff);
		else
			print_func(step, &content, diff);
	}
	else if (step[0] < 0)
	{
		step[0] *= -1;
		ft_putstr_fd("0x", 1);
		diff = ft_putnbr_fd_hex(va_arg(**content, intptr_t), 1, 87);
		diff += 2;
		print_space(step[0], diff);
	}
	else
		print_pointer_pos(&content);
}
