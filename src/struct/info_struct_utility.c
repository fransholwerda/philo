/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   info_struct_utility.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 13:02:41 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/13 15:49:50 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "info_struct_utility.h"
#include "my_time.h"
#include "utils.h"

void	free_info(t_info *info)
{
	if (!info)
		return ;
	if (info->print)
		free(info->print);
	if (info->death)
		free(info->death);
	free(info);
	info = NULL;
}

t_info	*init_info(int argc, char *argv[])
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->philos = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	info->death = 0;
	info->death_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	info->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!info->print || !info->death)
	{
		free_info(info);
		return (NULL);
	}
	if (argc == 6)
		info->eat_amount = ft_atoi(argv[5]);
	else
		info->eat_amount = -1;
	info->start_time = get_start_time();
	return (info);
}
