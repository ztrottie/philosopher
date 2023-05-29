/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:31:19 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/29 14:06:03 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <semaphore.h>

# define FORK "fork"
typedef long long	t_time;

typedef struct s_pidlst
{
	pid_t			pid;
	struct s_pidlst	*next;
}	t_pidlst;

typedef struct s_data
{
	t_pidlst		*philo;
	sem_t			*forks;
	int				nb_philo;
	t_time			time_die;
	t_time			time_eat;
	t_time			time_sleep;
	int				nb_meal;
	bool			died;
	bool			meal_limit;
}	t_data;

typedef struct s_philo
{
	int				nb;
	t_time			tt_die;
	int				nb_meal;
	t_data			*data;
}	t_philo;

int		args_checker(int argc, char **argv);
int		ft_atoi(const char *str);
int		ft_isint(char *str);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	pidlst_addend(t_pidlst *pidlst, pid_t pid);

#endif