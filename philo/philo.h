/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:43:41 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/16 13:32:15 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "unistd.h"
# include "pthread.h"
# include "stdio.h"
# include "string.h"
# include "stdbool.h"

typedef struct	s_data
{
	int		nb_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		nb_meal;
	bool	meal_limit;
}	t_data;

int		args_checker(int argc, char **argv);
size_t	ft_strlen(const char *s);
int		ft_isint(char *str);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);

#endif