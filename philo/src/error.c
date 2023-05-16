/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:48:38 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/16 10:51:40 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	args_checker(int argc, char **argv)
{
	if (argc > 6)
		return (write(2, "Too many arguments!", 19), 1);
	if (argc < 5)
		return (write(2, "Not enough arguments!", 21), 1);
}