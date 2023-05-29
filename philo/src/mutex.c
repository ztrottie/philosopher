/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:38:50 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/29 10:29:03 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(data->nb_philo * sizeof(t_fork));
	if (!data->fork)
		return (1);
	ft_bzero(data->fork, sizeof(t_fork *));
	while (i < data->nb_philo)
	{
		data->fork->use = false;
		if (pthread_mutex_init(&data->fork[i].mutex, NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->check_fork, NULL) != 0 || \
	pthread_mutex_init(&data->print, NULL) != 0 || \
	pthread_mutex_init(&data->die, NULL) != 0)
		return (1);
	return (0);
}

int	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_destroy(&data->fork[i].mutex) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_destroy(&data->check_fork) != 0 || \
	pthread_mutex_destroy(&data->print) != 0 || \
	pthread_mutex_destroy(&data->die) != 0)
		return (1);
	return (0);
}
