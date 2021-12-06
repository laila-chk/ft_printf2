/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 09:15:42 by lchokri           #+#    #+#             */
/*   Updated: 2021/12/06 21:15:56 by lchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_puthexaptr(unsigned long n, int i, char *mabase)
{
	char			*p;
	unsigned long	y;

	y = n;
//	if (*str == 'X')
//		mabase = "0123456789ABCDEF";
	while (y)
	{
		y /= 16;
		i++;
	}
	y = n;
	p = (char *)ft_calloc(i + 1, sizeof(char));
	while (n)
	{
		p[--i] = mabase[n % 16];
		n /= 16;
	}
	ft_putstr("0x");
	if (y == 0)
		ft_putstr("0");
	else
		ft_putstr(p);
	free(p);
}

void	print(const char *s, va_list args)
{
	if (*s == 'c')
		ft_putchar(va_arg(args, int));
	else if (*s == 's')
		ft_putstr(va_arg(args, char *));
	else if (*s == '%')
		ft_putchar('%');
	else if (*s == 'u')
		ft_putnbr2(va_arg(args, unsigned int));
	else if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(args, int));
}

void	hexafunctions(const char *str, va_list args)
{
	if (*str == 'p')
		ft_puthexaptr(va_arg(args, long), 0, "0123456789abcdef");
	if (*str == 'x' || *str == 'X')
		ft_puthexa(va_arg(args, unsigned int), 0, str, "0123456789abcdef");
}

int	ft_printf(const char *str, ...)
{
	va_list		args;

	va_start(args, str);
	g_counter = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			print(str, args);
			hexafunctions(str, args);
			if (*str != '\0')
				str++;
		}
		else
		{
			ft_putchar(*str);
			if (*str)
				str++;
		}
	}
	return (g_counter);
}
