/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:01:10 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/28 17:56:24 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	print_philo_state(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->died == false)
		printf("%lld %d %s\n", get_time(), philo->nb, state);
	pthread_mutex_unlock(&philo->data->print);
}

static void	think_sleep(t_philo *philo)
{
	print_philo_state(philo, SLEEP);
	smart_usleep(philo->data->time_sleep, philo);
	print_philo_state(philo, THINK);
	usleep(100);
}

static void	start_eat(t_philo *philo)
{
	while (!look_fork(philo))
	{
		if (philo->tt_die <= get_time())
		{
			philo_dead(philo);
			return ;
		}
		if (philo->data->died)
			break ;
		usleep(100);
	}
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_philo_state(philo, FORK);
	pthread_mutex_lock(&philo->right_fork->mutex);
	print_philo_state(philo, FORK);
	print_philo_state(philo, EAT);
	philo->tt_die = get_time() + philo->data->time_die;
	smart_usleep(philo->data->time_eat, philo);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	philo->left_fork->use = false;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	philo->right_fork->use = false;
}

static void	*life_start(void *var)
{
	t_philo *philo;
	
	philo = (t_philo *)var;
	if (philo->nb & 1)
		smart_usleep(philo->data->time_eat, philo);
	while (philo->data->died == false)
	{
		start_eat(philo);
		if (philo->data->meal_limit == true)
			philo->nb_meal--;
		if (philo->data->meal_limit == true && philo->nb_meal == 0)
			return (NULL);
		if (philo->data->died)
			break ;
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
