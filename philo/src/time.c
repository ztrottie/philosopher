/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:18:08 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/28 17:58:27 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	print_philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d %s\n", get_time(), philo->nb, DIED);
	pthread_mutex_unlock(&philo->data->print);
}

t_time	get_time(void)
{
	static struct timeval	start = {-1, -1};
	struct timeval			now;

	if (start.tv_sec == -1 && start.tv_usec == -1)
		gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000 - start.tv_sec * 1000) + \
	(now.tv_usec / 1000 - start.tv_usec / 1000));
}

void	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->die);
		if (philo->data->died == false)
		{
			philo->died = true;
			philo->data->died = true;
			print_philo_died(philo);
		}
		pthread_mutex_unlock(&philo->data->die);
}

void	smart_usleep(t_time ms, t_philo *philo)
{
	t_time	start;
	
	start = get_time();
	if (philo->tt_die < ms + start && philo->died == false && philo->tt_die > start)
		philo_dead(philo);
	else
	{
		usleep((ms * 1000) * 0.9);
		while (get_time() < ms + start)
		{
			usleep(150);
		}
	}
}
