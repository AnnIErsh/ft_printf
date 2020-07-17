/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_values_with_asters.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:11:13 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:12:02 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_values_with_asters(int *aster, int *step, va_list ***content)
{
	if (aster[0] == 1)
	{
		step[0] = va_arg(***content, int);
		(aster[2] == 1) && (step[0] > 0) ? step[0] *= -1 : aster[2];
	}
	if (aster[1] == 1)
	{
		step[1] = va_arg(***content, int);
		step[1] == -1 ? aster[3] = -1 : step[1];
		step[1] == 0 ? step[1] = -1 : step[1];
	}
}
