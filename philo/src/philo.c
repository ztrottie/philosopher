/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:42:39 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/16 13:23:52 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
}