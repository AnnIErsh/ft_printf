/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtianna <vtianna@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 22:03:03 by vtianna           #+#    #+#             */
/*   Updated: 2020/07/09 22:04:25 by vtianna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strchr_aster(const char *s, int c);
void	ft_putstr_fd(char const *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd_hex(unsigned long nbr, int fd, int letter);
int		ft_devide_hex_pos(unsigned long n, int letter, int len);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_putnbr_fd_size_t(unsigned int nbr, int fd);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, int n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
char	*ft_itoa_size_t(size_t n);
int		ft_printf(const char *format, ...);
int		count_symbols(int i);
void	print_space(int size, int diff);
void	print_zero(int edge);
void	print_space_or_zero(int size, int diff, int zero);
int		check_value(char **p_str);
int		check_aster(char *p_str);
int		check_aster_before_dot(char *p_str);
void	add_values_with_asters(int *aster, int *step, va_list ***content);
void	manage_without(va_list **content, int *step, int *aster);
void	manage_string(va_list **content, int *step, int *aster);
void	manage_pointer(va_list **content, int *step, int *aster);
void	manage_int(va_list **content, int *step, int *aster);
void	manage_char(va_list **content, int *step, int *aster);
void	manage_unsigned(va_list **content, int *step, int *aster);
void	manage_hex(va_list **content, int *step, int *aster, int letter);

#endif
