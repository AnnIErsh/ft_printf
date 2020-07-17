/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:03:53 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:05:19 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	manage_char(va_list **content, int *step, int *aster)
{
	int	check_char;

	add_values_with_asters(aster, step, &content);
	check_char = va_arg(**content, int);
	if (step[0] > 0)
	{
		print_space_or_zero(step[0], 1, step[2]);
		ft_putchar_fd(check_char, 1);
	}
	else if (step[0] < 0)
	{
		ft_putchar_fd(check_char, 1);
		print_space(step[0] * -1, 1);
	}
	else
		ft_putchar_fd(check_char, 1);
}
