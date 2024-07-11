/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:49:12 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/11 10:34:41 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	received(int signum)
{
	static unsigned int	size;

	if (signum == SIGUSR1)
		size++;
	else
	{
		ft_putnbr(size);
		ft_putchr('\n');
		exit(0);
	}
}

static void	sender(int pid, char *str)
{
	int	byte;
	int	i;
	int	bit;

	byte = -1;
	while (str[++byte])
	{
		i = 8;
		while (i--)
		{
			bit = (str[byte] >> i) & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(600);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(600);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr("\e[1;97mUsage:\e[0m ./client <PID> \"Message\"\n");
		exit(1);
	}
	ft_putstr("\e[1;97mByte Sent: ");
	ft_putnbr(ft_strlen(argv[2]));
	ft_putstr("\nByte Received: ");
	signal(SIGUSR1, received);
	signal(SIGUSR2, received);
	sender(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
