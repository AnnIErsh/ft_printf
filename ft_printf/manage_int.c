/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:22:47 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 18:38:21 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	pos_dot(int *step, int len, char *str, int check_sign)
{
	if (step[1] < len)
		step[1] = len;
	if (step[0] - step[1] > 0)
	{
		if (!check_sign)
			print_space(step[0] - step[1], 0);
		else
			print_space(step[0] - step[1] - 1, 0);
	}
	if (step[1] >= len)
	{
		if (check_sign)
			ft_putchar_fd('-', 1);
		print_zero(step[1] - len);
		ft_putstr_fd(str, 1);
	}
}

static void	pos_no(int *step, int len, char *str, int check_sign)
{
	if (!check_sign)
		print_space_or_zero(step[0], len, step[2]);
	else if (step[2])
	{
		ft_putchar_fd('-', 1);
		print_space_or_zero(step[0], len + 1, step[2]);
	}
	else
	{
		print_space_or_zero(step[0], len + 1, 0);
		ft_putchar_fd('-', 1);
	}
	ft_putstr_fd(str, 1);
}

static void	neg_dot(int *step, int len, char *str, int check_sign)
{
	step[0] *= -1;
	if (step[1] < len)
		step[1] = len;
	if (step[1] >= len)
	{
		if (check_sign)
			ft_putchar_fd('-', 1);
		print_zero(step[1] - len);
		ft_putstr_fd(str, 1);
	}
	if (step[0] - step[1] > 0)
	{
		if (!check_sign)
			print_space(step[0] - step[1], 0);
		else
			print_space(step[0] - step[1] - 1, 0);
	}
}

static void	neg_no(int *step, int len, char *str, int check_sign)
{
	step[0] *= -1;
	if (!check_sign)
	{
		ft_putstr_fd(str, 1);
		print_space_or_zero(step[0], len, 0);
	}
	else
	{
		ft_putchar_fd('-', 1);
		ft_putstr_fd(str, 1);
		print_space_or_zero(step[0], len + 1, 0);
	}
}

void		manage_int(va_list **content, int *step, int *aster)
{
	int		check_int;
	int		sign;
	char	*str;

	add_values_with_asters(aster, step, &content);
	check_int = va_arg(**content, int);
    sign = (check_int < 0) ? 1 : 0;
	sign ? check_int *= -1 : sign;
	str = ft_itoa(check_int);
	if (step[1] == -1 && check_int == 0 && aster[3] != -1)
	{
		(step[0] < 0) ? step[0] *= -1 : step[0];
		print_space(step[0], 0);
	}
	else if (step[0] >= 0)
	{
		step[1] > 0 ? pos_dot(step, (int)ft_strlen(str), str, sign) : step[1];
		step[1] <= 0 ? pos_no(step, (int)ft_strlen(str), str, sign) : step[1];
	}
	else if (step[0] < 0)
	{
		step[1] > 0 ? neg_dot(step, (int)ft_strlen(str), str, sign) : step[1];
		step[1] <= 0 ? neg_no(step, (int)ft_strlen(str), str, sign) : step[1];
	}
	free(str);
}
