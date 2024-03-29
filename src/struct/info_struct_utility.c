/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   info_struct_utility.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 13:02:41 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/23 15:19:29 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "info_struct_utility.h"
#include "my_time.h"
#include "utils.h"
#include "philo_enum.h"

void	free_info(t_info *info)
{
	if (!info)
		return ;
	if (info->print)
		free(info->print);
	if (info->death_lock)
		free(info->death_lock);
	free(info);
	info = NULL;
}

static int	assign_input(t_info *info, int argc, char *argv[])
{
	info->philos = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		info->eat_amount = ft_atoi(argv[5]);
	else
		info->eat_amount = -1;
	if (info->philos == -2 || info->die_time == -2 || info->eat_time == -2
		|| info->sleep_time == -2 || info->eat_amount == -2)
	{
		printf("Invalid input.\n");
		return (FAIL);
	}
	if (info->philos < 1)
	{
		printf("Use at least 1 philosopher.\n");
		return (FAIL);
	}
	return (SUCCESS);
}

t_info	*init_info(int argc, char *argv[])
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->done_eating = 0;
	info->death = ALIVE;
	info->death_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	info->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!info->print || !info->death_lock
		|| assign_input(info, argc, argv) == FAIL)
	{
		free_info(info);
		return (NULL);
	}
	info->start_time = get_start_time();
	return (info);
}
