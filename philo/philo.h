/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:43:41 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/26 12:51:25 by ztrottie         ###   ########.fr       */
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

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"


typedef struct	s_data
{
	struct s_philo	*philo;
	pthread_mutex_t	*fork;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_meal;
	int				died;
	bool			meal_limit;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				nb;
	int				tt_die;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t *right_fork;
	t_data			*data;
}	t_philo;

int		args_checker(int argc, char **argv);
size_t	ft_strlen(const char *s);
int		ft_isint(char *str);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	init_fork(t_data *data);
void	destroy_mutex(t_data *data);
void	lauch_philo(t_data *data);

#endif