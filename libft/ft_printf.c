/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovais <jnovais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:34:33 by jnovais           #+#    #+#             */
/*   Updated: 2025/12/20 20:34:33 by jnovais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert(char type, va_list arg)
{
	if (type == 'c')
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		return (1);
	}
	else if (type == 's')
		return (ft_putstr(va_arg(arg, char *), 1));
	else if (type == 'p')
		return (ft_putptr(va_arg(arg, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(arg, int), 1));
	else if (type == 'u')
		return (ft_putnbr_unsigned(va_arg(arg, int), 1));
	else if (type == 'x' || type == 'X' )
		return (ft_puthex(va_arg(arg, unsigned int), type));
	else if (type == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *text, ...)
{
	int		i;
	int		len;
	va_list	arg;

	va_start (arg, text);
	i = 0;
	len = 0;
	while (text[i] != '\0')
	{
		if (text[i] == '%')
		{
			i++;
			len = len + convert(text[i], arg);
		}
		else
			len = len + write(1, &(text[i]), 1);
		i++;
	}
	va_end(arg);
	return (len);
}
