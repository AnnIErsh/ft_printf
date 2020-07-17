/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:57:54 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:01:39 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	pos_if_dot_u(int *step, int check_len, char *check_str)
{
	if (step[1] < check_len)
		step[1] = check_len;
	if (step[0] - step[1] > 0)
		print_space(step[0] - step[1], 0);
	if (step[1] >= check_len)
	{
		print_zero(step[1] - check_len);
		ft_putstr_fd(check_str, 1);
	}
}

static void	pos_if_no_dot_u(int *step, int check_len, char *check_str)
{
	print_space_or_zero(step[0], check_len, step[2]);
	ft_putstr_fd(check_str, 1);
}

static void	neg_if_dot_u(int *step, int check_len, char *check_str)
{
	step[0] *= -1;
	if (step[1] < check_len)
		step[1] = check_len;
	if (step[1] >= check_len)
	{
		print_zero(step[1] - check_len);
		ft_putstr_fd(check_str, 1);
	}
	if (step[0] - step[1] > 0)
		print_space(step[0] - step[1], 0);
}

static void	neg_if_no_dot_u(int *step, int check_len, char *check_str)
{
	step[0] *= -1;
	ft_putstr_fd(check_str, 1);
	print_space_or_zero(step[0], check_len, 0);
}

void		manage_unsigned(va_list **content, int *step, int *aster)
{
	unsigned int	check_int;
	char	*check_str;
	int		check_len;

	add_values_with_asters(aster, step, &content);
	check_int = va_arg(**content, unsigned int);
	check_str = ft_itoa_size_t(check_int);
	check_len = (int)ft_strlen(check_str);
	if (step[1] == -1 && check_int == 0 && aster[3] != -1)
	{
		if (step[0] < 0)
			step[0] *= -1;
		print_space(step[0], 0);
	}
	else if (step[0] >= 0)
	{
		step[1] > 0 ? pos_if_dot_u(step, check_len, check_str) : step[1];
		step[1] <= 0 ? pos_if_no_dot_u(step, check_len, check_str) : step[1];
	}
	else if (step[0] < 0)
	{
		step[1] > 0 ? neg_if_dot_u(step, check_len, check_str) : step[1];
		step[1] <= 0 ? neg_if_no_dot_u(step, check_len, check_str) : step[1];
	}
	free(check_str);
}
