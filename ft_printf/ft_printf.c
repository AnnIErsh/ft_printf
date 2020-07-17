/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 22:14:36 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/08 22:27:42 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	init_array(int array[], int aster[])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		*(array + i) = 0;
		*(aster + i) = 0;
		i++;
	}
}

static void	get_width_with_zero_and_minus(char **p_str, int step[], int aster[])
{
	while (**p_str == '0' || **p_str == '-' || **p_str == ' ')
	{
		**p_str == '0' ? step[2] = 1 : **p_str;
		**p_str == '-' ? step[3] = 1 : **p_str;
		step[3] == 1 ? aster[2] = 1 : step[3];
		*p_str = *p_str + 1;
	}
	if ((aster[0] = check_aster_before_dot(*p_str)))
		*p_str = *p_str + 1;
	while (**p_str == '0' || **p_str == '-' || **p_str == ' ')
	{
		**p_str == '0' ? step[2] = 1 : **p_str;
		**p_str == '-' ? step[3] = 1 : **p_str;
		*p_str = *p_str + 1;
	}
	step[0] = check_value(p_str);
	step[3] == 1 ? step[0] *= -1 : step[3];
}

static void	manage_dot(char **p_str, int step[], int aster[])
{
	if (**p_str == '.')
	{
		*p_str = *p_str + 1;
		while (**p_str == '-' || **p_str == '0')
			*p_str = *p_str + 1;
		step[1] = check_value(p_str);
		if ((aster[1] = check_aster(*p_str)))
			*p_str = *p_str + 1;
		if (step[1] == 0 && aster[1] == 0)
			step[1] = -1;
	}
}

static void	print_type(char c, va_list *content, int *step, int *aster)
{
	if (c == '%')
		manage_without(&content, step, aster);
	if (c == 'c')
		manage_char(&content, step, aster);
	if (c == 's')
		manage_string(&content, step, aster);
	if (c == 'p')
		manage_pointer(&content, step, aster);
	if (c == 'd' || c == 'i')
		manage_int(&content, step, aster);
	if (c == 'u')
		manage_unsigned(&content, step, aster);
	if (c == 'x')
		manage_hex(&content, step, aster, 87);
	if (c == 'X')
		manage_hex(&content, step, aster, 55);
}

int			ft_printf(const char *param, ...)
{
	va_list		ap;
	char		*p_str;
	static int	count;
	int			step[4];
	int			aster[4];

	count ? count = 0 : count;
	va_start(ap, param);
	while (param && *param != '\0')
	{
		init_array(step, aster);
		if ((p_str = ft_strchr(param, '%')))
		{
			p_str++;
			get_width_with_zero_and_minus(&p_str, step, aster);
			manage_dot(&p_str, step, aster);
			print_type(*p_str, &ap, step, aster);
			param = ++p_str;
		}
		else
			break ;
	}
	va_end(ap);
	count = count_symbols(1);
	return (count);
}
