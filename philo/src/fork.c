/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:38:50 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/24 18:56:18 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_fork(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(data->nb_philo * sizeof(t_fork));
	while (i < data->nb_philo)
	{
		data->fork[i].use = 0;
		pthread_mutex_init(&data->fork[i].lock, NULL);
		i++;
	}
}

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->fork[i].lock);
		i++;
	}
	free(data->fork);
}
