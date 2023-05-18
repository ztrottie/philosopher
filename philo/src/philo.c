/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:42:39 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/17 23:45:08 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	*hello_world(void *)
{
	printf("hello world!\n");
}

static void	init_philos(t_data *data)
{
	int	i;
	
	data->philo = malloc(data->nb_philo * sizeof(t_philo));
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &hello_world, NULL) != 0)
			return ;
		i++;
	}
}

static void	wait_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return ;
		i++;
	}
}

static void	init_data(t_data *data, int argc, char **argv)
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
	init_data(&data, argc, argv);
	init_philos(&data);
	wait_philo(&data);
	return (0);
}