/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:33:45 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 21:34:19 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = (void *)malloc(size * count);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (int)(size * count));
	return (mem);
}
