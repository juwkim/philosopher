/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:02:55 by seojo             #+#    #+#             */
/*   Updated: 2023/01/24 22:00:57 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	pickup(t_philosopher *philo);
static void	eat(t_philosopher *philo);
static void	putdown(t_philosopher *philo);

void	*philosopher(void *arg)
{
	t_philosopher *const	philo = (t_philosopher *) arg;
	t_manager				*manager;

	manager = philo->manager;
	while (manager->start_time == 0)
		usleep(10);
	while (true)
	{
		pickup(philo);
		eat(philo);
		putdown(philo);
		print_state(&manager->m_print, manager->start_time, philo->id, SLEEP);
		msleep(manager->time_to_sleep);
		print_state(&manager->m_print, manager->start_time, philo->id, THINK);
	}
	return (NULL);
}

static void	pickup(t_philosopher *philo)
{
	t_manager	*manager;
	int			philo_count;

	manager = philo->manager;
	philo_count = manager->philo_count;
	if (philo->id & 1)
	{
		pthread_mutex_lock(&manager->m_forks[philo->id]);
		print_state(&manager->m_print, manager->start_time, philo->id, PICKUP);
		pthread_mutex_lock(&manager->m_forks[(philo->id + 1) % philo_count]);
		print_state(&manager->m_print, manager->start_time, philo->id, PICKUP);
	}
	else
	{
		pthread_mutex_lock(&manager->m_forks[(philo->id + 1) % philo_count]);
		print_state(&manager->m_print, manager->start_time, philo->id, PICKUP);
		pthread_mutex_lock(&manager->m_forks[philo->id]);
		print_state(&manager->m_print, manager->start_time, philo->id, PICKUP);
	}
}

static void	eat(t_philosopher *philo)
{
	t_manager	*manager;

	manager = philo->manager;
	pthread_mutex_lock(&manager->m_eat[philo->id]);
	manager->last_eat_time[philo->id] = get_milisecond(0);
	++manager->eat_count[philo->id];
	pthread_mutex_unlock(&manager->m_eat[philo->id]);
	print_state(&manager->m_print, manager->start_time, philo->id, EAT);
	msleep(manager->time_to_eat);
}

static void	putdown(t_philosopher *philo)
{
	t_manager	*manager;
	int			philo_count;

	manager = philo->manager;
	philo_count = manager->philo_count;
	if (philo->id & 1)
	{
		pthread_mutex_unlock(&manager->m_forks[(philo->id + 1) % philo_count]);
		pthread_mutex_unlock(&manager->m_forks[philo->id]);
	}
	else
	{
		pthread_mutex_unlock(&manager->m_forks[philo->id]);
		pthread_mutex_unlock(&manager->m_forks[(philo->id + 1) % philo_count]);
	}
}
