/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 08:05:02 by hefurrer          #+#    #+#             */
/*   Updated: 2023/06/05 08:07:19 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include	<stdio.h>
# include	<pthread.h>
# include	<unistd.h>

typedef struct s_args
{
	int	nop;
	int	ttd;
	int	tte;
	int	tts;
	int	notepme;
}				t_args;

int		ft_atoi(const char *str);
t_args	get_args(char **av, int ac);

#endif
