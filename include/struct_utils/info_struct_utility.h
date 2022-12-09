/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   info_struct_utility.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 13:03:06 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/09 17:02:09 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_STRUCT_UTILITY_H
# define INFO_STRUCT_UTILITY_H

# include <pthread.h>

typedef struct s_info
{
	int				philos;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_amount;
	long int		start_time;
	pthread_mutex_t	*print;
	pthread_mutex_t	*death;
}				t_info;

void	free_info(t_info *info);
t_info	*init_info(int argc, char *argv[]);

#endif
