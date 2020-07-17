/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:58:48 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:59:21 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return ;
	if (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
		ft_putstr_fd(s, fd);
	}
}
