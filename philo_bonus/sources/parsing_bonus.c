/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:56:44 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/24 23:24:15 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

static int	_atoi(const char *str);
static bool	is_space(int c);
static bool	is_sign(int c);
static bool	is_digit(int c);

bool	parsing(t_manager *manager, int argc, char **argv)
{
	int			idx;
	int *const	manager_ptr = (int *) manager;

	idx = 1;
	while (idx < argc)
	{
		manager_ptr[idx - 1] = _atoi(argv[idx]);
		if (manager_ptr[idx - 1] == -1)
		{
			printf("Invald input while parsing\n");
			return (false);
		}
		++idx;
	}
	if (argc == 5)
		manager->must_eat = 0;
	manager->start_time = 0;
	return (true);
}

static int	_atoi(const char *str)
{
	int	num;

	num = 0;
	while (is_space(*str))
		++str;
	if (is_sign(*str))
	{
		if (*str == '-')
			return (-1);
		++str;
	}
	while (is_digit(*str))
		num = num * 10 + *str++ - '0';
	if (*str == '\0')
		return (num);
	else
		return (-1);
}

static bool	is_space(int c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

static bool	is_sign(int c)
{
	return (c == '-' || c == '+');
}

static bool	is_digit(int c)
{
	return ('0' <= c && c <= '9');
}
