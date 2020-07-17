/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_devide_hex_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:46:58 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:47:23 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_devide_hex_pos(unsigned long n, int letter, int len)
{
	if (n >= 16)
		len = ft_devide_hex_pos(n / 16, letter, ++len);
	return (len);
}
