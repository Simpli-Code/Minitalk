/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:00:10 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/06 15:04:00 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	newact;

	ft_server();
	newact.sa_sigaction = &ft_receive_bits;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &newact, NULL);
	sigaction(SIGUSR2, &newact, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}

void	ft_server(void)
{
	int	pid;

	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr(pid);
	write(1, "\n", 1);
	write(1, "Waiting for Client's Signal \n", 29);
}

static void	ft_put_c_to_s(unsigned char c)
{
	static char	string_buffer[MAX_BUFF + 1];
	static int	char_count;

	if (c != '\n')
	{
		string_buffer[char_count] = c;
		char_count++;
	}
	else if (char_count >= MAX_BUFF)
	{
		string_buffer[char_count] = '\0';
		write (1, string_buffer, char_count);
		char_count = 0;
		ft_bzero(string_buffer, MAX_BUFF);
	}
	else
	{
		string_buffer[char_count] = '\0';
		write (1, string_buffer, char_count);
		write (1, "\n", 1);
		char_count = 0;
	}
}

void	ft_receive_bits(int signum, siginfo_t *siginfo, void *context)
{
	static unsigned int	buffer;
	static unsigned int	bits_received;
	pid_t				client_pid;

	client_pid = 0;
	(void)context;
	if (!client_pid)
	{
		client_pid = siginfo->si_pid;
	}
	if (signum == SIGUSR1)
	{
		buffer = buffer + (1 << bits_received);
	}
	bits_received++;
	if (bits_received == 8)
	{
		ft_put_c_to_s(buffer);
		bits_received = 0;
		buffer = 0;
	}
	kill(client_pid, SIGUSR2);
}

/*https://man7.org/linux/man-pages/man2/sigaction.2.html
https://youtu.be/_1TuZUbCnX0
*/
