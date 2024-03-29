/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:25:25 by hefurrer          #+#    #+#             */
/*   Updated: 2023/09/25 13:25:28 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_in_ms(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

int	make_mutex(t_rules *rules)
{
	int	i;

	i = rules->number_of_philosophers;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(rules->fork[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rules->write_lock), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->death_lock), NULL))
		return (1);
	return (0);
}

void	set_philo(t_rules *rules, int actual_philo)
{
	t_philosopher	*philo;

	philo = rules->philosopher;
	if (rules->number_of_philosophers == 1)
	{
		philo[actual_philo].right_fork_id = actual_philo;
		philo[actual_philo].left_fork_id = 0;
		philo[actual_philo].last_meal = get_time_in_ms();
		philo[actual_philo].philo_id = (actual_philo + 1);
		philo[actual_philo].rules = rules;
		return ;
	}
	if (actual_philo == 0)
		philo[actual_philo].left_fork_id = rules->number_of_philosophers - 1;
	else
		philo[actual_philo].left_fork_id = actual_philo - 1;
	philo[actual_philo].right_fork_id = actual_philo;
	philo[actual_philo].last_meal = get_time_in_ms();
	philo[actual_philo].philo_id = (actual_philo + 1);
	philo[actual_philo].rules = rules;
}

void	init_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		set_philo(rules, i);
		i++;
	}
}
