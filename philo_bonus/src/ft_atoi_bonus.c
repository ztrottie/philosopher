/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:14:29 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/29 13:15:03 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else if (c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	sign;
	int	i;

	nb = 0;
	i = 0;
	sign = 1;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb * sign);
}
