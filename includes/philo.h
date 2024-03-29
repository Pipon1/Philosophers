/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:48:45 by hefurrer          #+#    #+#             */
/*   Updated: 2023/09/25 07:48:54 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# define CYAN "\033[0;36m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define PURPLE "\033[0;35m"
# define RESET "\033[0m"

typedef struct s_philosopher {
	int					left_fork_id;
	int					right_fork_id;
	int					philo_id;
	int					x_meal;
	pthread_t			thread;
	long long			last_meal;
	struct s_rules		*rules;

}				t_philosopher;

typedef struct s_rules {
	int					number_of_philosophers;
	long long			time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					dieded;
	int					meal_finished;
	int					meal_number;
	long long			prog_debut;
	t_philosopher		philosopher[250];
	pthread_mutex_t		fork[250];
	pthread_mutex_t		write_lock;
	pthread_mutex_t		death_lock;
}				t_rules;

int				ft_atoi(char *str);
int				is_number(char nb);
int				av_check(char *av);
int				input_check(char **av, int ac);
int				make_rules(t_rules *rules, char **av, int ac);
int				end_thread(t_rules *rules);
int				make_philo_thread(t_rules *rules);
long long		get_time_in_ms(void);
void			print_philo(t_rules *rules);
void			set_philo(t_rules *rules, int actual_philo);
int				make_mutex(t_rules *rules);
void			dynamic_sleep(long long t_to_sleep, t_rules *rules);
long long		time_diff(long long past, long long pres);
void			init_philo(t_rules *rules);
void			philo_eats(t_philosopher *philo);
void			print_action(t_rules *r, int philo_id, char *print, int color);
int				validity_check(char **av, int ac);
void			death(t_rules *rules, int *i);
int				error_management(char **av, int ac);

#endif
