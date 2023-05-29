/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:18:08 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/29 10:29:58 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

void	smart_usleep(t_time ms, t_philo *philo)
{
	t_time	start;

	start = get_time();
	if (philo->tt_die < ms + start && philo->died == false \
	&& philo->tt_die > start)
	{
		usleep((philo->tt_die - start) * 1000);
		philo_dead(philo);
	}
	else
	{
		usleep((ms * 1000) * 0.9);
		while (get_time() < ms + start)
		{
			usleep(150);
		}
	}
}
