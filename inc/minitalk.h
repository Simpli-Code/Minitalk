/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:15:27 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/11 08:47:54 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_BUFF	9096
# define MSG		"\e[1;32mWaiting for Client's Message \e[0m\n"
# define ERR_MSG	"\e[1;31mInvalid input, Please enter: \
Server's PID and a message <string>\e[0m\n"

void	ft_server(void);
void	ft_putnbr(int num);
size_t	ft_strlen(char *str);
void	handle_err_exit(void);
int		ft_atoi(const char *s);
void	ft_sig_handler(int sig);
void	ft_bzero(void *s, size_t n);
void	ft_client(const char *pid, char *str);
void	ft_send_bits(int pid, unsigned int byte);
void	ft_receive_bits(int signum, siginfo_t *siginfo, void *context);

#endif
