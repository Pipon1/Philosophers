/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:26:01 by hefurrer          #+#    #+#             */
/*   Updated: 2023/09/25 13:26:06 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_rules	rules;

	if (ac < 5 || ac > 6)
	{
		printf("wrong amount of argument\n0");
		return (1);
	}
	if (make_rules(&rules, av, ac))
		return (1);
	if (make_philo_thread(&rules))
	{
		printf("error occurred with either creating/joining thread\n");
		return (1);
	}
	return (0);
}
