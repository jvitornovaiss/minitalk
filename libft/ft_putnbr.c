/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovais <jnovais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 21:50:11 by jnovais           #+#    #+#             */
/*   Updated: 2025/12/20 21:50:11 by jnovais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_int(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n = (-1) * n;
		}
		if (n >= 10)
		{
			put_int(n / 10, fd);
			n = n % 10;
		}
		if (n < 10)
		{
			c = n + '0';
			write(fd, &c, 1);
		}
	}
}

int	ft_putnbr(int n, int fd)
{
	unsigned long long	nb;

	put_int(n, fd);
	if (n >= 0)
		return (n_digits(n, 10));
	else
	{
		nb = (unsigned long long)n * -1;
		return (1 + n_digits(nb, 10));
	}
}
