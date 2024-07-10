/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:13:06 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/10 15:56:14 by flmarsou         ###   ########.fr       */
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
	(void)info;
	(void)context;

	if (signum == SIGUSR1)
		byte = byte << 1;
	else if (signum == SIGUSR2)
		byte = (byte << 1) | 1;
	bit++;
	if (bit == 8)
	{
		ft_putchr(byte);
		byte = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	printer();
	sa.sa_sigaction = receiver;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
