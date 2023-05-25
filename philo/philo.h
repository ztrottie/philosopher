/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:43:41 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/24 21:02:08 by ztrottie         ###   ########.fr       */
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

typedef struct s_fork
{
	pthread_mutex_t	lock;
	int				use;
}	t_fork;


typedef struct s_philo
{
	pthread_t		thread;
	int				nb;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_meal;
	struct s_fork	left_fork;
	struct s_fork	right_fork;
	bool			meal_limit;
	int				*died;
}	t_philo;

typedef struct	s_data
{
	struct s_philo	*philo;
	struct s_fork	*fork;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_meal;
	bool			meal_limit;
}	t_data;

int		args_checker(int argc, char **argv);
size_t	ft_strlen(const char *s);
int		ft_isint(char *str);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	init_fork(t_data *data);
void	destroy_mutex(t_data *data);
void	lauch_philo(t_data *data);

#endif