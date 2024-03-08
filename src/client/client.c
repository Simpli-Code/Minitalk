/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:00:15 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/06 15:04:22 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_var = 0;

int	main(int argc, char *argv[])
{
	signal(SIGUSR2, &ft_sig_handler);
	if (argc != 3)
		handle_error_msg();
	else if (argv[2][0] == '\0')
		handle_error_msg();
	else
	{
		ft_client(argv[1], argv[2]);
	}
	return (0);
}

void	ft_client(const char *pid, char *str)
{
	int	server_pid;
	int	i;

	i = 0;
	if (ft_atoi(pid) <= 0)
		handle_error_msg();
	else
	{
		server_pid = ft_atoi(pid);
	}
	while (str[i])
	{
		ft_send_bits(server_pid, str[i]);
		i++;
	}
	ft_send_bits(server_pid, '\n');
}

void	ft_send_bits(int server_pid, unsigned int byte)
{
	int	i;
	int	l_var;

	i = 0;
	if (kill(server_pid, 0) == -1)
		handle_error_msg();
	while (i < 8)
	{
		l_var = g_var;
		if (byte & (1 << i))
		{
			kill(server_pid, SIGUSR1);
		}
		else
		{
			kill(server_pid, SIGUSR2);
		}
		while (l_var == g_var)
		{
		}
		i++;
	}
}

void	ft_sig_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		g_var++;
	}
}
