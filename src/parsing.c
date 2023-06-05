/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 08:23:56 by hefurrer          #+#    #+#             */
/*   Updated: 2023/06/05 08:24:00 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../includes/philosophers.h"

t_args	get_args(char **av, int ac)
{
	t_args	args;

	args.nop = ft_atoi(av[1]);
	args.ttd = ft_atoi(av[2]);
	args.tte = ft_atoi(av[3]);
	args.tts = ft_atoi(av[4]);
	if (ac > 5)
		args.notepme = ft_atoi(av[5]);
	return (args);
}
