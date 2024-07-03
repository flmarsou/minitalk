/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:49:12 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/03 14:42:26 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	sender(int pid, char *msg)
{
	int	c;
	int	i;
	int	bit;

	c = 0;
	while (msg[c])
	{
		i = 7;
		while (i >= 0)
		{
			bit = (msg[c] >> i) & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
		}
		write(1, " ", 1);
		c++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		sender(ft_atoi(argv[1]), argv[2]);
	else
		write(1, "\e[1;97mUsage:\e[0m ./client <PID> <Message>\n", 43);
	return (0);
}
