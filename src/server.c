/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:13:06 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/08 15:39:08 by flmarsou         ###   ########.fr       */
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

// static void	sig_handler(int sugnum)
// {
	
// }

int	main(void)
{
	printer();
	while (1)
	{
		// signal(SIGUSR1, sig_handler);
		// signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}
