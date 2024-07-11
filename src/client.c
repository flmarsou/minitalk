/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:49:12 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/11 13:15:37 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	received(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_putstr("\e[1;32m[✓] - Successfully received the message!\n\e[0m");
		exit(0);
	}
}

static void	sender(int pid, char *str)
{
	unsigned int	byte;
	unsigned int	i;
	unsigned int	bit;

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
			usleep(200);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr("\e[1;97mUsage:\e[0m ./client <PID> \"Message\"\n");
		exit(1);
	}
	else if (ft_strlen(argv[2]) > 1024)
	{
		ft_putstr("\e[1;97m[!] - Reached the limit (1024 characters)!\n\e[0m");
		exit(1);
	}
	signal(SIGUSR1, received);
	sender(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
