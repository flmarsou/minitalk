/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:13:06 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/11 10:22:34 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	printer(void)
{
	ft_putstr("███████╗███████╗██████╗ ██╗   ██╗███████╗██████╗ \n");
	ft_putstr("██╔════╝██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗\n");
	ft_putstr("███████╗█████╗  ██████╔╝██║   ██║█████╗  ██████╔╝\n");
	ft_putstr("╚════██║██╔══╝  ██╔══██╗╚██╗ ██╔╝██╔══╝  ██╔══██╗\n");
	ft_putstr("███████║███████╗██║  ██║ ╚████╔╝ ███████╗██║  ██║\n");
	ft_putstr("╚══════╝╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝\n");
	ft_putstr("\e[97;1mPID: ");
	ft_putnbr(getpid());
	ft_putstr("                  \e[0;90mcreated by flmarsou\n");
	ft_putstr("\e[97;1mUse: ./client <PID> \"message\"\n");
}

static void	receiver(int signum, siginfo_t *info, void *context)
{
	static unsigned char	byte;
	static unsigned int		bit;
	static char				buffer[2048];
	static unsigned int		i;

	(void)context;
	if (signum == SIGUSR1)
		byte = byte << 1;
	else if (signum == SIGUSR2)
		byte = (byte << 1) | 1;
	bit++;
	if (bit == 8)
	{
		buffer[i++] = byte;
		if (byte == '\0')
		{
			buffer[i] = '\0';
			ft_putstr(buffer);
			kill(info->si_pid, SIGUSR2);
			i = 0;
		}
		byte = 0;
		bit = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	printer();
	sa.sa_sigaction = receiver;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
