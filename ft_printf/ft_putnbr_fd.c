/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:44:54 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:46:06 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_devide(long n, int fd, int sign)
{
	if (sign == 1)
	{
		ft_putchar_fd('-', fd);
		sign = 0;
	}
	if (n >= 10)
		ft_devide(n / 10, fd, sign);
	ft_putchar_fd(n % 10 + '0', fd);
}

void		ft_putnbr_fd(int nbr, int fd)
{
	int	sign;

	sign = (nbr < 0);
	sign == 1 ? nbr *= -1 : nbr;
	ft_devide(nbr, fd, sign);
}
