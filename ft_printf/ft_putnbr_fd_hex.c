/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:47:48 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:57:28 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_devide_hex(unsigned long n, int fd, int letter, int len)
{
	if (n >= 16)
		len = ft_devide_hex(n / 16, fd, letter, ++len);
	if (n % 16 >= 10)
		ft_putchar_fd(n % 16 + letter, fd);
	else
		ft_putchar_fd(n % 16 + '0', fd);
	return (len);
}

int			ft_putnbr_fd_hex(unsigned long nbr, int fd, int letter)
{
	int	len;

	len = ft_devide_hex(nbr, fd, letter, 0);
	return (len + 1);
}
