/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:54:09 by seojo             #+#    #+#             */
/*   Updated: 2023/01/24 21:50:36 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_state(pthread_mutex_t *m_print, long long start_time, \
						int philo_id, const char *message)
{
	pthread_mutex_lock(m_print);
	printf("%lld\t%d %s\n", get_milisecond(start_time), philo_id, message);
	pthread_mutex_unlock(m_print);
}

void	print_died(pthread_mutex_t *m_print, long long start_time, \
						int philo_id, const char *message)
{
	pthread_mutex_lock(m_print);
	printf(RED "%lld\t%d %s\n" DEF_COLOR, get_milisecond(start_time), \
													philo_id, message);
	exit(EXIT_FAILURE);
	pthread_mutex_unlock(m_print);
}

void	print_done(pthread_mutex_t *m_print)
{
	pthread_mutex_lock(m_print);
	printf(GREEN "Simulation stopped successfully!\n" DEF_COLOR);
	exit(EXIT_SUCCESS);
	pthread_mutex_unlock(m_print);
}
