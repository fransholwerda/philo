/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 12:33:45 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/20 15:03:37 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "info_struct_utility.h"
#include "philo_struct_utility.h"
#include "philo_enum.h"
#include "philo_print.h"
#include "my_time.h"

static void	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork);
	philo_print(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->next->fork);
	philo_print(philo, "has taken a fork\n");
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->next->fork);
}

static void	update_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->info->death_lock);
	philo->last_time_eaten = timestamp(philo->info->start_time);
	philo->amount_eaten++;
	pthread_mutex_unlock(philo->info->death_lock);
}

static int	zero_eat_check(t_philo *philo)
{
	pthread_mutex_lock(philo->info->death_lock);
	if (philo->info->eat_amount == 0)
	{
		pthread_mutex_unlock(philo->info->death_lock);
		return (DONE_EATING);
	}
	pthread_mutex_unlock(philo->info->death_lock);
	return (SUCCESS);
}

int	eat(t_philo *philo)
{
	if (zero_eat_check(philo) == DONE_EATING)
		return (DONE_EATING);
	grab_forks(philo);
	philo_print(philo, "is eating\n");
	if (proper_sleep(philo->info->eat_time) == FAIL)
	{
		drop_forks(philo);
		return (FAIL);
	}
	update_eating(philo);
	drop_forks(philo);
	pthread_mutex_lock(philo->info->death_lock);
	if (philo->info->eat_amount > -1
		&& philo->amount_eaten >= philo->info->eat_amount)
	{
		pthread_mutex_unlock(philo->info->death_lock);
		return (DONE_EATING);
	}
	else
	{
		pthread_mutex_unlock(philo->info->death_lock);
		return (SUCCESS);
	}
}
