/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:56:53 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/25 14:50:42 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static void	*check_died(void *arg);
static void	eat(t_philosopher *philo);

void	philosopher(t_philosopher *philo)
{
	t_manager	*manager;
	pthread_t	tid;

	manager = philo->manager;
	sem_wait(manager->sm_start);
	sem_post(manager->sm_start);
	if (pthread_create(&tid, NULL, check_died, (void *) philo) != 0)
		return ;
	while (true)
	{
		eat(philo);
		print_state(manager->sm_print, manager->start_time, philo->id, SLEEP);
		msleep(manager->time_to_sleep);
		print_state(manager->sm_print, manager->start_time, philo->id, THINK);
	}
}

static void	*check_died(void *arg)
{
	long long		time_interval;
	t_philosopher	*philo;
	t_manager		*manager;

	philo = (t_philosopher *) arg;
	manager = philo->manager;
	while (true)
	{
		sem_wait(manager->sm_eat[philo->id]);
		if (manager->eat_count[philo->id] == 0)
			time_interval = get_milisecond(manager->start_time);
		else
			time_interval = get_milisecond(manager->last_eat_time[philo->id]);
		if (time_interval > manager->time_to_die)
		{
			print_died(manager->sm_print, manager->start_time, philo->id, DIE);
			sem_post(manager->sm_dead);
		}
		sem_post(manager->sm_eat[philo->id]);
		msleep(1);
	}
	return (NULL);
}

static void	eat(t_philosopher *philo)
{
	t_manager	*manager;

	manager = philo->manager;
	sem_wait(manager->sm_fork);
	print_state(manager->sm_print, manager->start_time, philo->id, PICKUP);
	sem_wait(manager->sm_fork);
	print_state(manager->sm_print, manager->start_time, philo->id, PICKUP);
	sem_wait(manager->sm_eat[philo->id]);
	print_state(manager->sm_print, manager->start_time, philo->id, EAT);
	manager->last_eat_time[philo->id] = get_milisecond(0);
	++manager->eat_count[philo->id];
	if (manager->eat_count[philo->id] == manager->must_eat)
		sem_post(manager->sm_done);
	sem_post(manager->sm_eat[philo->id]);
	msleep(manager->time_to_eat);
	sem_post(manager->sm_fork);
	sem_post(manager->sm_fork);
}
