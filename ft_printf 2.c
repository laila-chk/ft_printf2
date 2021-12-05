/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 09:15:42 by lchokri           #+#    #+#             */
/*   Updated: 2021/12/05 16:23:56 by lchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	if (write (1, &c, 1) == 1)
		g_counter++;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(char *)s = '\0';
		s++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, size * count);
	return (p);
}

void	print(const char *s, va_list args)
{
	if (*s == 'c')
		ft_putchar(va_arg(args, int));
	else if (*s == 's')
		ft_putstr(va_arg(args, char *));
}

void	ft_putnbr(int n)
{
	long	a;

	a = n;
	if (a < 0)
	{
		a = -1 * a;
		write(1, "-", 1);
	}
	if (a > 9)
	{
		ft_putnbr(a / 10);
		ft_putnbr(a % 10);
	}
	if (a <= 9)
		ft_putchar(a + 48);
}

void	ft_puthexa(unsigned long n, int i, const char *str)
{
	char			*mabase;
	char            *p;
    unsigned long   y;

    y = n;
	if (*str == 'X')
		mabase = "0123456789ABCDEF";
	else
		mabase = "0123456789abcdef";
	while (y)
	{
		y /= 16;
		i++;
	}
	p = (char *)ft_calloc(i + 1, sizeof(char));
	while (n)
	{
		p[--i] = mabase[n % 16];
		n /= 16;
	}
	if (*str == 'p')
		ft_putstr("0x");
	ft_putstr(p);
	free(p);
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
			if (*str == 'p' || *str == 'x' || *str == 'X')
				ft_puthexa(va_arg(args, long), 0, str);
			else if (*str == 'd' || *str == 'i' || *str == 'u')
				ft_putnbr(va_arg(args, long));
		str++;
		}
		ft_putchar(*str);
		str++;
	}
	return (g_counter);
}

int main()
{
	char g = 'X';
	char *p;
	p = &g;
	char bro[] = "yalahwiiiiiiii";

	
	   printf("jjust making sure thin%c are oki, or i'll go %s, cuz %p have extra 0x than %x & %X, my lucky numbers %d, %i & %u almost the same not like %%\n",g, bro, p, 13,13,13,13,13);
	ft_printf("jjust making sure thin%c are oki, or i'll go %s, cuz %p have extra 0x than %x & %X, my lucky numbers %d, %i & %u almost the same not like %%  ",g, bro, p, 13,13,13,13,13);
}
