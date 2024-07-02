/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:49:12 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/02 15:59:08 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, const char **argv)
{
	int			pid;
	const char	*msg;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
	}
	else
		write(1, "\e[1;31mError:\e[1;97m Not Enough Argument\n\e[0m", 45);
}