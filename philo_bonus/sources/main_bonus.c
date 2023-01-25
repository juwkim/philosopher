/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:56:33 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/25 02:22:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	main(int argc, char **argv)
{
	t_manager		manager;

	if (argc != 5 && argc != 6)
	{
		printf("usage: philosopher_count time_to_die time_to_eat "\
				"time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (parsing(&manager, argc, argv) == false)
		return (2);
	simulate(&manager);
	return (0);
}
