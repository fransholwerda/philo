/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_time.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 15:09:35 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/06 10:42:14 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_TIME_H
# define MY_TIME_H

long int	get_start_time(void);
long int	timestamp(long int start_time);
int			proper_sleep(long int sleep_time);

#endif
