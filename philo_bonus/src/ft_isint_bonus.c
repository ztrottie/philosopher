/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:38:16 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/29 13:14:51 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static long int	ft_li_atoi(const char *str)
{
	long int	nb;
	int			sign;
	int			i;

	nb = 0;
	i = 0;
	sign = 1;
	if (str[i] && str[i] == '-')
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

int	ft_isint(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	if (len > 10)
		return (1);
	if (len == 10 && ft_li_atoi(str) > INT_MAX)
		return (1);
	return (0);
}
