/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 12:34:58 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/20 15:00:08 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "info_struct_utility.h"
#include "philo_struct_utility.h"
#include "arbiter.h"
#include "freedom.h"
#include "utils.h"
#include "my_time.h"
#include "eat.h"
#include "philo_print.h"
#include "threads.h"
#include "philo_enum.h"

static void	set_death(t_info *info)
{
	pthread_mutex_lock(info->death_lock);
	info->death = DEATH;
	pthread_mutex_unlock(info->death_lock);
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;
	int		eat_status;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (philo->info->philos == 1)
			return (NULL);
		if (alive_check(philo->info) == DEATH)
			return (NULL);
		eat_status = eat(philo);
		if (eat_status == DONE_EATING || eat_status == FAIL)
			return (NULL);
		philo_print(philo, "is sleeping\n");
		if (proper_sleep(philo->info->sleep_time) == FAIL)
		{
			philo_print(philo, "sleep went wrong\n");
			set_death(philo->info);
			return (NULL);
		}
		philo_print(philo, "is thinking\n");
	}
	return (NULL);
}

int	init_mutex(t_philo *philo)
{
	t_philo	*temp;
	int		i;

	temp = philo;
	i = 0;
	if (pthread_mutex_init(philo->info->death_lock, NULL) != 0)
		return (0);
	while (i < philo->info->philos)
	{
		if (pthread_mutex_init(temp->fork, NULL) != 0)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

int	engage_philos(t_philo *philo, t_info *info, pthread_t *threads)
{
	int			i;
	int			error;

	if (pthread_mutex_init(info->print, NULL) != 0)
		return (0);
	i = 0;
	if (init_mutex(philo) == 0)
		return (0);
	while (i < info->philos)
	{
		error = pthread_create(&threads[i], NULL, &philo_thread, (void *)philo);
		if (error != 0)
			return (0);
		philo = philo->next;
		i++;
	}
	return (1);
}

int	philosophers(int argc, char *argv[])
{
	t_info		*info;
	t_philo		*philo;
	pthread_t	*threads;

	info = init_info(argc, argv);
	philo = init_philos(info);
	threads = create_threads(info);
	if (!info || !philo || !threads)
	{
		free_all(philo, info, threads);
		return (0);
	}
	if (engage_philos(philo, info, threads) == 0)
	{
		free_all(philo, info, threads);
		return (0);
	}
	arbiter(philo, info);
	join_threads(threads, info->philos);
	loop_philos(philo, 0);
	free_all(philo, info, threads);
	return (1);
}
