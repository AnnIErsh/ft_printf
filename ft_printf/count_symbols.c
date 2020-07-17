/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:22:11 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:23:34 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	count_symbols(int i)
{
	static int	count;
	int			j;

	if (i == 0)
		count++;
	else
	{
		j = count;
		count = 0;
		return (j);
	}
	return (count);
}
