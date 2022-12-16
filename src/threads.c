/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 16:02:21 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/16 17:38:15 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "info_struct_utility.h"



#include <stdio.h>
pthread_t	*create_threads(t_info *info)
{
	pthread_t	*threads;

	if (!info)
		return (NULL);
	threads = (pthread_t *)malloc((info->philos) * sizeof(pthread_t));
	return (threads);
}

void	join_threads(pthread_t *threads, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
