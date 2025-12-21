/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovais <jnovais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:12:50 by jnovais           #+#    #+#             */
/*   Updated: 2025/12/20 20:12:50 by jnovais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int main(void)
{
	ft_printf("Server's PID: %d\n", getpid());
	ft_printf("Aguardando pela mensagem\n");
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();

	return (0);
}