/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:42:39 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/29 09:34:47 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	init_philos(t_data *data)
{
	int		i;

	data->philo = malloc(data->nb_philo * sizeof(t_philo));
	if (!data->philo)
		return (1);
	ft_bzero(data->philo, sizeof(t_philo *));
	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i].tt_die = data->time_die;
		data->philo[i].nb = i + 1;
		data->philo[i].data = data;
		data->philo[i].died = false;
		data->philo[i].nb_meal = data->nb_meal;
		if (i == 0)
			data->philo[i].left_fork = &data->fork[data->nb_philo - 1];
		else
			data->philo[i].left_fork = &data->fork[i - 1];
		data->philo[i].right_fork = &data->fork[i];
		i++;
	}
	return (0);
}

static int	lauch_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, \
		&life_start, &data->philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

static int	wait_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

static void	init_data(t_data *data, char **argv)
{
	ft_bzero(data, sizeof(t_data));
	data->nb_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		data->meal_limit = true;
		data->nb_meal = ft_atoi(argv[5]);
	}
	else
		data->meal_limit = false;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (args_checker(argc, argv))
		return (1);
	init_data(&data, argv);
	if (init_mutex(&data))
		return (free_all(&data), 1);
	if (init_philos(&data))
		return (free_all(&data), 1);
	if (lauch_philo(&data))
		return (free_all(&data), 1);
	if (wait_philo(&data))
		return (free_all(&data), 1);
	if (destroy_mutex(&data))
		return (free_all(&data), 1);
	return (free_all(&data), 0);
}
