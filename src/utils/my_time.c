/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 14:51:58 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/02 17:00:34 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>

long int	get_start_time(void)
{
	struct timeval	current_time;
	long int		start_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	start_time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (start_time);
}

long int	timestamp(long int start_time)
{
	struct timeval	current_time;
	long int		timestamp;

	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	timestamp = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	timestamp -= start_time;
	return (timestamp);
}
