/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 16:04:53 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/15 16:05:33 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include <pthread.h>
# include "info_struct_utility.h"

pthread_t	*create_threads(t_info *info);
void		join_threads(pthread_t *threads, int amount);

#endif
