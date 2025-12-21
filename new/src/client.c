/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovais <jnovais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:50:59 by jnovais          #+#    #+#             */
/*   Updated: 2025/10/16 18:17:53 by jnovais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	g_bit_confirmed;

static void	handler(int signum)
{
	(void)signum;
	g_bit_confirmed = 1;
}

static void	set_end_message(pid_t server_pid)
{
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		g_bit_confirmed = 0;
		kill(server_pid, SIGUSR1);
		while (!g_bit_confirmed)
			usleep(100);
		bit_index--;
	}
}

static void	send_signals(pid_t server_pid, char *str)
{
	int	i;
	int	current_bit;

	i = 0;
	while (str[i])
	{
		current_bit = 0;
		while (current_bit <= 7)
		{
			g_bit_confirmed = 0;
			if (str[i] & (128 >> current_bit))
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			while (!g_bit_confirmed)
				usleep(100);
			current_bit++;
		}
		i++;
	}
	set_end_message(server_pid);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	int				result;
	int				sign;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (sign * result);
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	client_action;

	if (argc != 3)
	{
		ft_printf("Use: ./client <PID> <menssage>\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Use: ./client <PID> <menssage>\n");
		exit(EXIT_FAILURE);
	}
	sigemptyset(&client_action.sa_mask);
	client_action.sa_handler = &handler;
	client_action.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &client_action, NULL);
	send_signals(server_pid, argv[2]);
	return (0);
}
