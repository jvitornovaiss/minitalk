/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovais <jnovais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:36:19 by jnovais           #+#    #+#             */
/*   Updated: 2025/12/20 22:36:19 by jnovais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_bit_confirmed;

static void	handler(int signum)
{
	(void)signum;
	g_bit_confirmed = 1;
}

static void	ft_send_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_bit_confirmed = 0;
		if (c & (128 >> bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_bit_confirmed)
			usleep(100);
		bit++;
	}
}

static void	send_error(const char *msg)
{
	ft_printf(msg);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	int					i;
	struct sigaction	client_action;

	if (argc != 3)
		send_error("Try: ./client <PID> <MESSAGE>\n");
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		send_error("Invalid PID\n");
	sigemptyset(&client_action.sa_mask);
	client_action.sa_handler = &handler;
	client_action.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &client_action, NULL);
	i = 0;
	while (argv[2][i])
	{
		ft_send_bits(pid, argv[2][i]);
		i++;
	}
	ft_send_bits(pid, '\0');
	return (0);
}
