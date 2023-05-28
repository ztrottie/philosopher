/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:38:50 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/28 17:19:16 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	look_fork(t_philo *philo)
{
	int	use;
	
	pthread_mutex_lock(&philo->data->check_fork);
	if (philo->left_fork == philo->right_fork)
		use = 0;
	else if (!philo->left_fork->use || !philo->right_fork->use)
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

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(data->nb_philo * sizeof(t_fork));
	ft_bzero(data->fork, sizeof(t_fork *));
	while (i < data->nb_philo)
	{
		data->fork->use = false;
		if (pthread_mutex_init(&data->fork[i].mutex, NULL) != 0)
			return ;
		i++;
	}
	pthread_mutex_init(&data->check_fork, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->die, NULL);
}

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->fork[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&data->check_fork);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->die);
	free(data->fork);
}
