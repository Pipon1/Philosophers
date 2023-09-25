/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:27:23 by hefurrer          #+#    #+#             */
/*   Updated: 2023/09/25 13:27:27 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	death(t_rules *rules, int *i)
{
	t_philosopher	*philo;

	philo = rules->philosopher;
	while (++*i < rules->number_of_philosophers && rules->dieded == 0)
	{
		pthread_mutex_lock(&rules->death_lock);
		if (time_diff(philo[*i].last_meal, get_time_in_ms())
			> rules->time_to_die)
		{
			print_action(rules, philo[*i].philo_id, "died", 1);
			pthread_mutex_lock(&rules->write_lock);
			rules->dieded = 1;
			pthread_mutex_unlock(&rules->write_lock);
		}
		pthread_mutex_unlock(&rules->death_lock);
	}
}

int	error_management(char **av, int ac)
{
	if (input_check(av, ac))
	{
		printf("invalid argument, make sure to only input numbers\n");
		return (1);
	}
	if (validity_check(av, ac) == 2)
		return (1);
	else if (validity_check(av, ac) == 1)
	{
		printf("wrong inputs pls make sure to be reasonnable\n");
		return (1);
	}
	return (0);
}
