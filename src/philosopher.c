/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 12:34:58 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/02 17:17:15 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>
#include "philosopher.h"
#include "utils.h"
#include "my_time.h"

#include <unistd.h>
#include <stdio.h>
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
	if (argc == 6)
		info->eat_amount = ft_atoi(argv[5]);
	return (info);
}

int	philosophers(int argc, char *argv[])
{
	t_info	*info;
	int		i;

	info = init_info(argc, argv);
	if (!info)
		return (-1);
	i = 0;
	//engage philos
	while (i < info->philos)
		break ;
	info->start_time = get_start_time();
	printf("%ld\n", info->start_time);
	usleep(2000000);
	printf("%ld\n", timestamp(info->start_time));
	//arbiter(info);
	//printf("philos: %d\ndie_time: %d\neat_time: %d\nsleep_time: %d\nstart_time: %ld", info->philos, info->die_time, info->eat_time, info->sleep_time, info->start_time);
	return (1);
}
