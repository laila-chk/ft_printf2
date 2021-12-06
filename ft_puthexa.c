/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchokri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:38:45 by lchokri           #+#    #+#             */
/*   Updated: 2021/12/06 21:08:21 by lchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int n, int i, const char *str, char *mabase)
{
	char			*p;
	unsigned int	y;

	y = n;
	if (*str == 'X')
		mabase = "0123456789ABCDEF";
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
	if (y == 0)
		ft_putstr("0");
	else
		ft_putstr(p);
	free(p);
}
