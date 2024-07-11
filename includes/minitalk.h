/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:33:25 by flmarsou          #+#    #+#             */
/*   Updated: 2024/07/11 10:35:46 by flmarsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void		ft_putchr(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int nbr);
int			ft_atoi(char *str);
int			ft_strlen(char *str);

#endif
