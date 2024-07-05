/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:13:06 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/05 15:52:43 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	sig_handler(int signum)
{
	// Bits to Char
}

int	main(void)
{
	ft_putstr("\e[1mServer PID: \e[4m");
	ft_putnbr(getpid());
	ft_putstr("\e[0m\n");
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}
