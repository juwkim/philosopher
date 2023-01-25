/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:56:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/25 14:39:02 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_bonus.h"

void	print_state(sem_t *sm_print, long long start_time, \
						int philo_id, const char *message)
{
	sem_wait(sm_print);
	printf("%lld\t%d %s\n", get_milisecond(start_time), philo_id, message);
	sem_post(sm_print);
}

void	print_died(sem_t *sm_print, long long start_time, \
						int philo_id, const char *message)
{
	sem_wait(sm_print);
	printf(RED "%lld\t%d %s\n" DEF_COLOR, get_milisecond(start_time), \
													philo_id, message);
}

void	print_done(sem_t *sm_print)
{
	sem_wait(sm_print);
	printf(GREEN "Simulation stopped successfully!\n" DEF_COLOR);
}
