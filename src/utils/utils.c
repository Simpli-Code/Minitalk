/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:46:36 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/06 15:04:08 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int num)
{
	unsigned int	n;

	if (num < 0)
	{
		write(1, "-", 1);
		n = -num;
	}
	else
	{
		n = num;
	}
	if (num > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		n = n + '0';
		write(1, &n, 1);
	}
}

int	ft_atoi(const char *s)
{
	int	i;
	int	sum;
	int	sign;

	i = 0;
	sum = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		sum = sum * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] != '\0')
		handle_error_msg();
	return (sum * sign);
}

void	handle_error_msg(void)
{
	write(2, "Invalid input, Please enter: Server's PID  \"string\"\n", 54);
	exit (EXIT_FAILURE);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = s;
	i = 0;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}
