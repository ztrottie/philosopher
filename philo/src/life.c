/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:01:10 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/26 22:00:35 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	print_philo_state(t_philo *philo, char *state)
{
	long int ms;

	pthread_mutex_lock(&philo->data->print);
	ms = timestamp(philo->data->start_time);
	printf("%6ld %3d %s\n", ms, philo->nb, state);
	pthread_mutex_unlock(&philo->data->print);
}

static void	think_sleep(t_philo *philo)
{
	print_philo_state(philo, SLEEP);
	usleep(1000 * philo->data->time_sleep);
	print_philo_state(philo, THINK);
	usleep(1000 * philo->data->time_eat - philo->data->time_sleep);
}

static void	start_eat(t_philo *philo)
{
	philo->tt_die = philo->data->time_die;
	pthread_mutex_lock(philo->left_fork);
	print_philo_state(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	print_philo_state(philo, FORK);
	print_philo_state(philo, EAT);
	usleep(1000 * philo->data->time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	*life_start(void *var)
{
	t_philo *philo;
	
	philo = (t_philo *)var;
	if (philo->data->started == false)
		gettimeofday(&philo->data->start_time, NULL);
	if (philo->nb & 1)
		usleep(philo->data->time_eat * 1000);
	while (philo->data->died != true)
	{
		start_eat(philo);
		think_sleep(philo);
	}
	return (NULL);
}

void	lauch_philo(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &life_start, &data->philo[i]) != 0)
			return ;
		i++;
	}
}
