/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:49:12 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/10 16:05:24 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	sender(int pid, char *msg)
{
	int	c;
	int	i;
	int	bit;

	c = -1;
	while (msg[++c])
	{
		i = 8;
		while (i--)
		{
			bit = (msg[c] >> i) & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(300);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(300);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		sender(ft_atoi(argv[1]), argv[2]);
	else
		ft_putstr("\e[1;97mUsage:\e[0m ./client <PID> \"Message\"\n");
	return (0);
}
