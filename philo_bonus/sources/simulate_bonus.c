/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:56:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/25 14:50:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate_bonus.h"

static void	sem_all_init(t_manager *manager);
static void	destroy(t_manager *manager, int n);
static void	manage(t_manager *manager);
static void	*check_done(void *arg);

void	simulate(t_manager *manager)
{
	int				idx;
	t_philosopher	philos[MAX_PHILO_COUNT];

	sem_all_init(manager);
	sem_wait(manager->sm_start);
	manager->start_time = get_milisecond(0);
	manager->is_died = false;
	idx = -1;
	while (++idx < manager->philo_count)
	{
		philos[idx].id = idx;
		philos[idx].manager = manager;
		sem_unlink("sm_eat");
		manager->sm_eat[idx] = sem_open("sm_eat", O_CREAT, 0644, 1);
		manager->eat_count[idx] = 0;
		manager->pids[idx] = fork();
		if (manager->pids[idx] == 0)
			return (philosopher(philos + idx));
		if (manager->pids[idx] < 0)
			return ;
	}
	if (idx == manager->philo_count)
		manage(manager);
	destroy(manager, idx);
}

static void	sem_all_init(t_manager *manager)
{
	sem_unlink("sm_dead");
	manager->sm_dead = sem_open("sm_dead", O_CREAT, 0644, 0);
	sem_unlink("sm_done");
	manager->sm_done = sem_open("sm_done", O_CREAT, 0644, 0);
	sem_unlink("sm_start");
	manager->sm_start = sem_open("sm_start", O_CREAT, 0644, 1);
	sem_unlink("sm_print");
	manager->sm_print = sem_open("sm_print", O_CREAT, 0644, 1);
	sem_unlink("sm_fork");
	manager->sm_fork = sem_open("sm_fork", O_CREAT, 0644, manager->philo_count);
}

static void	destroy(t_manager *manager, int n)
{
	while (--n >= 0)
	{
		sem_unlink("sm_eat");
		sem_close(manager->sm_eat[n]);
		kill(manager->pids[n], SIGTERM);
	}
	sem_unlink("sm_dead");
	sem_close(manager->sm_dead);
	sem_unlink("sm_done");
	sem_close(manager->sm_done);
	sem_unlink("sm_start");
	sem_close(manager->sm_start);
	sem_unlink("sm_print");
	sem_close(manager->sm_print);
	sem_unlink("sm_fork");
	sem_close(manager->sm_fork);
}

static void	manage(t_manager *manager)
{
	pthread_t	tid;
	int			idx;

	sem_post(manager->sm_start);
	if (pthread_create(&tid, NULL, check_done, (void *) manager) != 0)
		return ;
	sem_wait(manager->sm_dead);
	manager->is_died = true;
	idx = 0;
	while (idx < manager->philo_count)
	{
		sem_post(manager->sm_done);
		++idx;
	}
	pthread_join(tid, NULL);
}

static void	*check_done(void *arg)
{
	int			idx;
	t_manager	*manager;

	manager = (t_manager *) arg;
	idx = 0;
	while (idx < manager->philo_count)
	{
		sem_wait(manager->sm_done);
		++idx;
	}
	if (manager->is_died == false)
	{
		print_done(manager->sm_print);
		sem_post(manager->sm_dead);
	}
	return (NULL);
}
