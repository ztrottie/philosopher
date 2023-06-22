/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:47:24 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/22 17:05:23 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	free_all(t_data *data)
{
	ft_free(data->philo);
	ft_free(data->fork);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	if (s)
		memset(s, 0, n);
}

int	check_dead(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->data->die);
	if (philo->data->died)
		dead = 1;
	else
		dead = 0;
	pthread_mutex_unlock(&philo->data->die);
	return (dead);
}
