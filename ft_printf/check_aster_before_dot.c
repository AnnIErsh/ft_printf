/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_aster_before_dot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:13:57 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:15:48 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_aster_before_dot(char *p_str)
{
	char	*test;
	int		i;

	i = 0;
	while (*(p_str + i))
	{
		if (*(p_str + i) == '*')
			break ;
		if (*(p_str + i) == '.')
			return (0);
		i++;
	}
	if ((test = ft_strchr_aster(p_str, '*')))
		return (1);
	return (0);
}
