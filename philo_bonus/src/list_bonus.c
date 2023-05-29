/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:38:50 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/29 13:46:55 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	pidlst_addend(t_pidlst *philo, pid_t pid)
{
	t_pidlst	*ptr;
	
	if (!philo)
	{
		philo = (t_pidlst *)malloc(sizeof(t_pidlst));
		if (!philo)
			return ;
		philo->pid = pid;
		philo->next = NULL;
	}
	else
	{
		ptr = philo;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = (t_pidlst *)malloc(sizeof(t_pidlst));
		ptr->next->pid = pid;
		ptr->next->next = NULL;
	}
}
