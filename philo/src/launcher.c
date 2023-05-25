/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:37:10 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/25 13:37:12 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	start_eat(t_philo *philo)
{
	
}

static void	*life_start(void *var)
{
	t_philo *philo;
	
	philo = (t_philo *)var;
	start_eat()
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
		i += 2;
	}
	i = 1;
	usleep(data->time_die * 1000);
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &life_start, &data->philo[i]) != 0)
			return ;
		i += 2;
	}
}