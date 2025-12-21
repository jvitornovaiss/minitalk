/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovais <jnovais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:20:54 by jnovais          #+#    #+#             */
/*   Updated: 2025/09/03 12:19:31 by jnovais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
		count += ft_putchar(*s++);
	return (count);
}

int	ft_putnbr(int n)
{
	long int	nbr;
	int			count;

	nbr = (long int)n;
	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + 48);
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar((n % 10) + 48);
	return (count);
}

int	ft_puthexa(unsigned long int n, const char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthexa(n / 16, base);
	count += ft_putchar(base[n % 16]);
	return (count);
}
