/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:16:09 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:17:52 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_value(char **p_str)
{
	int		step;
	char	*step_str;
	size_t	step_len;

	step = ft_atoi(*p_str);
	step_str = ft_itoa(step);
	step_len = ft_strlen(step_str);
	if (*step_str == '0')
		step_len = 0;
	if (step_len)
		*p_str = *p_str + step_len;
	free(step_str);
	return (step);
}
