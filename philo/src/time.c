/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:18:08 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/26 21:59:15 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	timestamp(struct timeval start)
{
	struct timeval	end;
	long			start_ms;
	long			end_ms;
	
	gettimeofday(&end, NULL);
	start_ms = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	end_ms = (end.tv_sec * 1000) + (end.tv_usec / 1000);
	return (end_ms - start_ms);
}
