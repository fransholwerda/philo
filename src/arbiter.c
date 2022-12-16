/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arbiter.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 13:47:53 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/16 18:06:46 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "info_struct_utility.h"
#include "philo_struct_utility.h"
#include "philo_enum.h"
#include "my_time.h"

int	philo_alive_check(t_philo *philo, t_info *info)
{
	long int	check;

	pthread_mutex_lock(info->death_lock);
	check = philo->last_time_eaten + info->die_time;
	if (check < timestamp(info->start_time))
	{
		philo->info->death = DEATH;
		pthread_mutex_unlock(info->death_lock);
		return (DEATH);
	}
	pthread_mutex_unlock(info->death_lock);
	return (ALIVE);
}

int	arbiter(t_philo *philo, t_info *info)
{
	while (1)
	{
		if (philo_alive_check(philo, info) == DEATH)
		{
			pthread_mutex_lock(info->print);
			printf("%ld %d died\n", timestamp(info->start_time), philo->id);
			pthread_mutex_unlock(info->print);
			return (DEATH);
		}
		philo = philo->next;
		if (philo->id == philo->info->philos)
			usleep(500);
	}
}
