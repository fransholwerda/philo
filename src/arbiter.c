/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arbiter.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 13:47:53 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/20 14:58:11 by fholwerd      ########   odam.nl         */
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
	if (info->death == DEATH)
	{
		printf("test\n");
		return (DEATH);
	}
	check = philo->last_time_eaten + info->die_time;
	if (philo->amount_eaten == info->eat_amount)
	{
		philo->amount_eaten++;
		info->done_eating++;
		pthread_mutex_unlock(info->death_lock);
		return (DONE_EATING);
	}
	if (check < timestamp(info->start_time))
	{
		philo->info->death = DEATH;
		pthread_mutex_unlock(info->death_lock);
		return (DEATH);
	}
	pthread_mutex_unlock(info->death_lock);
	return (ALIVE);
}

void	arbiter(t_philo *philo, t_info *info)
{
	while (1)
	{
		if (info->philos == 1)
		{
			if (proper_sleep(info->die_time) == FAIL)
				return ;
			pthread_mutex_lock(info->print);
			printf("%ld %d died\n", timestamp(info->start_time), philo->id);
			pthread_mutex_unlock(info->print);
			return ;
		}
		if (philo_alive_check(philo, info) == DEATH)
		{
			pthread_mutex_lock(info->print);
			printf("%ld %d died\n", timestamp(info->start_time), philo->id);
			pthread_mutex_unlock(info->print);
			return ;
		}
		else if (info->done_eating == info->philos)
			return ;
		philo = philo->next;
		if (philo->id == philo->info->philos)
			usleep(500);
	}
}
