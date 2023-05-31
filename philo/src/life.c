/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:01:10 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/31 11:20:14 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_philo_state(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->died == false || (philo->data->died && philo->died))
		printf("%lld %d %s\n", get_time(), philo->nb, state);
	pthread_mutex_unlock(&philo->data->print);
}

void	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->die);
	if (philo->data->died == false)
	{
		philo->died = true;
		philo->data->died = true;
		print_philo_state(philo, DIED);
	}
	pthread_mutex_unlock(&philo->data->die);
}

static int	look_fork(t_philo *philo)
{
	int	use;

	pthread_mutex_lock(&philo->data->check_fork);
	if (philo->left_fork == philo->right_fork)
		use = 0;
	else if (!philo->left_fork->use && !philo->right_fork->use)
	{
		philo->left_fork->use = true;
		philo->right_fork->use = true;
		use = 1;
	}
	else
		use = 0;
	pthread_mutex_unlock(&philo->data->check_fork);
	return (use);
}

static void	start_eat(t_philo *philo)
{
	usleep(1000);
	while (!look_fork(philo) || philo->tt_die <= get_time())
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

void	*life_start(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	if (philo->nb & 1)
		smart_usleep(philo->data->time_eat, philo);
	while (philo->data->died == false)
	{
		print_philo_state(philo, THINK);
		if (!philo->died)
			start_eat(philo);
		if (philo->data->meal_limit == true)
			philo->nb_meal--;
		if (philo->data->meal_limit == true && philo->nb_meal == 0)
			return (NULL);
		if (!philo->died)
			print_philo_state(philo, SLEEP);
		smart_usleep(philo->data->time_sleep, philo);
	}
	return (NULL);
}
