/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_without.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:14:38 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 18:16:16 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	manage_without(va_list **content, int *step, int *aster)
{
	if (aster[0] == 1)
	{
		step[0] = va_arg(**content, int);
		(aster[2] == 1) && (step[0] > 0) ? step[0] *= -1 : aster[2];
	}
	if (aster[1] == 1)
	{
		step[1] = va_arg(**content, int);
		step[1] == -1 ? aster[3] = -1 : step[1];
		step[1] == 0 ? step[1] = -1 : step[1];
	}
	if (step[0] > 0)
	{
		print_space_or_zero(step[0], 1, step[2]);
		ft_putchar_fd('%', 1);
	}
	else if (step[0] < 0)
	{
		ft_putchar_fd('%', 1);
		print_space(step[0] * -1, 1);
	}
	else
		ft_putchar_fd('%', 1);
}
