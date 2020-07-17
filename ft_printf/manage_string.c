/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:04:53 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 18:14:11 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*s_pos(char *s, int size, int zero)
{
	int	len;
	int	diff;

	diff = 0;
	len = (int)ft_strlen(s);
	if (size > len)
	{
		while (diff < size - len)
		{
			if (zero)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			diff++;
		}
	}
	return (s);
}

static char	*if_pres(char *s, int size_pres, int flag)
{
	char	*new_s;
	char	*to_free;
	int		i;

	if (size_pres == -1 && !flag)
		return ("");
	i = 0;
	if (size_pres > 0 && size_pres < (int)ft_strlen(s))
	{
		new_s = ft_calloc(size_pres + 1, 1);
		while (i < size_pres)
		{
			*(new_s + i) = *(s + i);
			i++;
		}
		*(new_s + i) = '\0';
		to_free = new_s;
		free(new_s);
		return (to_free);
	}
	new_s = s;
	return (new_s);
}

static void	check_s_negative(char *s, int size, int size_pres)
{
	int		len;
	int		diff;
	char	*new_str;

	new_str = if_pres(s, size_pres, 0);
	ft_putstr_fd(new_str, 1);
	size *= -1;
	diff = 0;
	len = (int)ft_strlen(new_str);
	if (size > len)
	{
		while (diff < size - len)
		{
			ft_putchar_fd(' ', 1);
			diff++;
		}
	}
}

void		manage_string(va_list **content, int *step, int *aster)
{
	char	*s;

	add_values_with_asters(aster, step, &content);
	s = va_arg(**content, char*);
	!s ? s = "(null)" : s;
	if (step[0] > 0)
		ft_putstr_fd(s_pos(if_pres(s, step[1], aster[3]), step[0], step[2]), 1);
	else if (step[0] < 0)
		check_s_negative(s, step[0], step[1]);
	else
		ft_putstr_fd(if_pres(s, step[1], aster[3]), 1);
}
