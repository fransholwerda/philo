/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freedom.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 13:34:08 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/09 13:51:43 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREEDOM_H
# define FREEDOM_H

# include <pthread.h>
# include "info_struct_utility.h"
# include "philo_struct_utility.h"

void	free_all(t_philo *philo, t_info *info, pthread_t *threads);

#endif
