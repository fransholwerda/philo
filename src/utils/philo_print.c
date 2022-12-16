/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_print.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 13:05:01 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/16 17:28:16 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "info_struct_utility.h"
#include "philo_struct_utility.h"
#include "philo_enum.h"
#include "my_time.h"

int	alive_check(t_info *info)
{
	int	status;

	pthread_mutex_lock(info->death_lock);
	if (info->death == ALIVE)
		status = ALIVE;
	else
		status = DEATH;
	pthread_mutex_unlock(info->death_lock);
	return (status);
}

void	philo_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->info->print);
	if (alive_check(philo->info) == ALIVE)
	{
		printf("%ld %d %s", timestamp(philo->info->start_time),
			philo->id,
			msg);
		pthread_mutex_unlock(philo->info->print);
		return ;
	}
	pthread_mutex_unlock(philo->info->print);
}
