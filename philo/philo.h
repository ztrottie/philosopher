/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:43:41 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/29 09:27:29 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/time.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

typedef long long	t_time;

typedef struct s_fork
{
	bool			use;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_data
{
	struct s_philo	*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	die;
	pthread_mutex_t	check_fork;
	t_fork			*fork;
	int				nb_philo;
	t_time			time_die;
	t_time			time_eat;
	t_time			time_sleep;
	int				nb_meal;
	bool			died;
	bool			meal_limit;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				nb;
	t_time			tt_die;
	t_fork			*left_fork;
	t_fork			*right_fork;
	bool			died;
	int				nb_meal;
	t_data			*data;
}	t_philo;

int		args_checker(int argc, char **argv);
size_t	ft_strlen(const char *s);
int		ft_isint(char *str);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		init_mutex(t_data *data);
int		destroy_mutex(t_data *data);
void	smart_usleep(t_time ms, t_philo *philo);
t_time	get_time(void);
void	philo_dead(t_philo *philo);
void	print_philo_state(t_philo *philo, char *state);
void	*life_start(void *var);
void	free_all(t_data *data);

#endif