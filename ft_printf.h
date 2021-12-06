/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:44:14 by lchokri           #+#    #+#             */
/*   Updated: 2021/12/06 21:09:06 by lchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	g_counter;
int		ft_printf(const char *str, ...);
void	*ft_calloc(size_t count, size_t size);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_puthexa(unsigned int n, int i, const char *str, char *mabase);
void	ft_putnbr2(unsigned int a);
void	ft_putstr(char *str);

#endif
