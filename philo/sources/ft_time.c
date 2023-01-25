/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:50:06 by seojo             #+#    #+#             */
/*   Updated: 2023/01/24 21:54:08 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_time.h"

long long	get_milisecond(long long start_time)
{
	struct timeval	current_time;
	long long		time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_sec * 1000 + (current_time.tv_usec / 1000);
	return (time - start_time);
}

void	msleep(long long time)
{
	long long	start_time;

	start_time = get_milisecond(0);
	while (time > get_milisecond(0) - start_time)
		usleep(100);
}
