/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:43:26 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 20:55:52 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	pos_if_dot_hex(int *step, int len, unsigned int hex, int letter)
{
	if (step[1] < len)
		step[1] = len;
	if (step[0] - step[1] > 0)
		print_space(step[0] - step[1], 0);
	if (step[1] >= len)
	{
		print_zero(step[1] - len);
		ft_putnbr_fd_hex(hex, 1, letter);
	}
}

static void	pos_if_no_dot_hex(int *step, int len, unsigned int hex, int letter)
{
	print_space_or_zero(step[0], len, step[2]);
	ft_putnbr_fd_hex(hex, 1, letter);
}

static void	neg_if_dot_hex(int *step, int len, unsigned int hex, int letter)
{
	step[0] *= -1;
	if (step[1] < len)
		step[1] = len;
	if (step[1] >= len)
	{
		print_zero(step[1] - len);
		ft_putnbr_fd_hex(hex, 1, letter);
	}
	if (step[0] - step[1] > 0)
		print_space(step[0] - step[1], 0);
}

static void	neg_if_no_dot_hex(int *step, int len, size_t hex, int letter)
{
	step[0] *= -1;
	ft_putnbr_fd_hex(hex, 1, letter);
	print_space_or_zero(step[0], len, 0);
}

void		manage_hex(va_list **content, int *step, int *aster, int letter)
{
	unsigned int	hex;
	int		len;

	add_values_with_asters(aster, step, &content);
	hex = va_arg(**content, unsigned int);
	len = ft_devide_hex_pos(hex, letter, 0) + 1;
	if (step[1] == -1 && hex == 0 && aster[3] != -1)
	{
		if (step[0] < 0)
			step[0] *= -1;
		print_space(step[0], 0);
	}
	else if (step[0] >= 0)
	{
		step[1] > 0 ? pos_if_dot_hex(step, len, hex, letter) : step[1];
		step[1] <= 0 ? pos_if_no_dot_hex(step, len, hex, letter) : step[1];
	}
	else if (step[0] < 0)
	{
		step[1] > 0 ? neg_if_dot_hex(step, len, hex, letter) : step[1];
		step[1] <= 0 ? neg_if_no_dot_hex(step, len, hex, letter) : step[1];
	}
}
