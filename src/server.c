/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:13:06 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/02 15:48:57 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(void)
{
	ft_putstr("\e[1mServer PID: \e[4m");
	ft_putnbr(getpid());
	ft_putstr("\e[0m\n	");
	return (0);
}
