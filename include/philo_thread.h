/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_thread.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/23 15:28:20 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/23 15:32:06 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREAD_H
# define PHILO_THREAD_H

# include "info_struct_utility.h"

void	set_death(t_info *info);
void	*philo_thread(void *arg);

#endif
