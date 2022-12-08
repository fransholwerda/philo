/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 12:34:58 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/08 17:21:40 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>
#include "philosopher.h"
#include "utils.h"
#include "my_time.h"

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
t_info	*init_info(int argc, char *argv[])
{
	t_info			*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->philos = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	info->print = malloc(sizeof(pthread_mutex_t));
	if (!info->print)
	{
		free(info);
		return (NULL);
	}
	if (argc == 6)
		info->eat_amount = ft_atoi(argv[5]);
	else
		info->eat_amount = -1;
	return (info);
}

void	*test_philo(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	pthread_mutex_lock(info->print);
	printf("I am created!\n");
	pthread_mutex_unlock(info->print);
	pthread_mutex_lock(info->print);
	printf("I am destroyed!\n");
	pthread_mutex_unlock(info->print);
	return (NULL);
}

int	philosophers(int argc, char *argv[])
{
	t_info		*info;
	pthread_t	*threads;
	int			i;
	int			error;


	info = init_info(argc, argv);
	if (!info)
		return (0);
	i = 0;
	//engage philos
	threads = (pthread_t *)malloc(info->philos * sizeof(pthread_t));
	if (pthread_mutex_init(info->print, NULL) != 0)
	{
		printf("HELP!\n");
		return (0);
	}
	if (!threads)
		return (0);
	while (i < info->philos)
	{
		error = pthread_create(&threads[i], NULL, &test_philo, (void *)info);
		if (error != 0)
			printf("Something went wrong\n");
		usleep(1);
		i++;
	}
	//arbiter(info);
	//printf("philos: %d\ndie_time: %d\neat_time: %d\nsleep_time: %d\nstart_time: %ld", info->philos, info->die_time, info->eat_time, info->sleep_time, info->start_time);
	return (1);
}
