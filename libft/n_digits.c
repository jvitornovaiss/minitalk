/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_digits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovais <jnovais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 21:46:55 by jnovais           #+#    #+#             */
/*   Updated: 2025/12/20 21:46:55 by jnovais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	n_digits(unsigned long long n, size_t base)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count += 1;
		n /= base;
	}
	return (count);
}
