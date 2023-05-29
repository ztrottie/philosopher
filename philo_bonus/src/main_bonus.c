/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:25:33 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/29 15:48:54 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static void	start_philo(t_data *data)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < data->nb_philo)
	{
		pid = fork();
		if (pid < 0)
			return ;
		else if (!pid)
			lauch_life;
		else
			pidlst_addend(data->philo, pid)
	}
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
	data->forks = sem_open(FORK, O_CREAT, 0644, data->nb_philo) + 1;
}

int	main(int argc, char **argv)
{
	t_data	data;
	
	sem_unlink(FORK);
	if (args_checker(argc, argv))
		return (1);
	init_data(&data, argv);
}
