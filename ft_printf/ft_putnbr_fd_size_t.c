/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_size_t.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:43:26 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:44:25 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_devide_size_t(long n, int fd)
{

	if (n >= 10)
		ft_devide_size_t(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void		ft_putnbr_fd_size_t(unsigned int nbr, int fd)
{
	ft_devide_size_t(nbr, fd);
}
