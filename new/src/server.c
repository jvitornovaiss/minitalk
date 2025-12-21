/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovais <jnovais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:51:02 by jnovais          #+#    #+#             */
/*   Updated: 2025/10/16 17:45:36 by jnovais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	handler_signal(int signum, siginfo_t *info, void *context)
{
	static int	character = 0;
	static int	bit_count = 0;

	(void)context;
	character = character << 1;
	if (signum == SIGUSR2)
		character = character | 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (character == 0)
			ft_printf("\n");
		else
			write(1, &character, 1);
		character = 0;
		bit_count = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	server_action;
	pid_t				server_pid;

	server_pid = getpid();
	ft_printf("Server iniciado!\n");
	ft_printf("PID: %d\n", server_pid);
	ft_printf("Aguardando mensagens...\n\n");
	server_action.sa_sigaction = handler_signal;
	server_action.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&server_action.sa_mask);
	sigaction(SIGUSR1, &server_action, NULL);
	sigaction(SIGUSR2, &server_action, NULL);
	while (1)
		pause();
	return (0);
}
