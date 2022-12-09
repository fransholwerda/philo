/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_struct_utility.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 17:12:44 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/09 17:02:25 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "info_struct_utility.h"
#include "philo_struct_utility.h"

void	free_philo(t_philo *philo)
{
	t_philo	*temp;

	while (philo)
	{
		temp = philo;
		philo = philo->next;
		if (temp->fork)
			free(temp);
		free(temp);
		temp = NULL;
	}
	philo = NULL;
}

static t_philo	*new_philo(int id, t_info *info)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->last_time_eaten = 0;
	philo->last_time_slept = 0;
	philo->death = 0;
	philo->amount_eaten = 0;
	philo->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!philo->fork)
	{
		free(philo);
		return (NULL);
	}
	philo->info = info;
	philo->next = NULL;
	return (philo);
}

static t_philo	*philo_add_back(t_philo *start, t_philo *add)
{
	t_philo	*i;

	if (!start || !add)
	{
		free_philo(start);
		return (NULL);
	}
	i = start;
	while (i->next)
		i = i->next;
	i->next = add;
	return (start);
}

static void	loop_philos(t_philo	*philos)
{
	t_philo	*last;

	last = philos;
	while (last->next)
		last = last->next;
	last->next = philos;
}

t_philo	*init_philos(t_info *info)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = NULL;
	if (!info)
		return (NULL);
	while (i < info->philos)
	{
		if (!philos)
		{
			philos = new_philo(i + 1, info);
			if (!philos)
				return (NULL);
		}
		else
		{
			if (!philo_add_back(philos, new_philo(i + 1, info)))
				return (NULL);
		}
		i++;
	}
	loop_philos(philos);
	return (philos);
}
