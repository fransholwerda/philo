/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 12:34:58 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/28 14:03:50 by fholwerd      ########   odam.nl         */
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
#include "threads.h"
#include "philo_thread.h"

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
		{
			set_death(info);
			printf("Thread %d failed to create.\n", i + 1);
			join_threads(threads, i - 1);
			return (0);
		}
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
		loop_philos(philo, 0);
		free_all(philo, info, threads);
		return (0);
	}
	arbiter(philo, info);
	join_threads(threads, info->philos);
	loop_philos(philo, 0);
	free_all(philo, info, threads);
	return (1);
}
