/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovais <jnovais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 21:52:49 by jnovais           #+#    #+#             */
/*   Updated: 2025/12/20 21:52:49 by jnovais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s, int fd)
{
	int		i;
	char	c;
	int		len;

	len = 0;
	if (!s)
		return (write(fd, "(null)", 6));
	i = 0;
	while (s[i] != '\0')
	{
		c = s[i];
		len += write(fd, &c, 1);
		i++;
	}
	return (len);
}
