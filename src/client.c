/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:49:12 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/05 15:52:11 by flmarsou         ###   ########.fr       */
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
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_puterr("\e[1;31m[x] - Failed to send signal!\e[0m\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_puterr("\e[1;31m[x] - Failed to send signal!\e[0m\n");
			}
			usleep(1000);
		}
		i = 8;
		while (i--)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_puterr("\e[1;31m[x] - Failed to send signal!\e[0m\n");
			usleep(1000);
		}
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
