/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:48:38 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/30 14:45:01 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	args_checker(int argc, char **argv)
{
	int	i;

	if (argc > 6)
		return (write(2, "Too many arguments!\n", 20), 1);
	if (argc < 5)
		return (write(2, "Not enough arguments!\n", 22), 1);
	i = 0;
	while (++i < argc)
		if (ft_isint(argv[i]))
			return (write(2, "all arguments should be positive integers\n" \
			, 42), 1);
	if (ft_atoi(argv[1]) > 1000)
		return (write(2, "slack sur les philo big\n", 25), 1);
	return (0);
}
