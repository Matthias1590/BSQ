/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwijnsma <mwijnsma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:39:49 by mwijnsma          #+#    #+#             */
/*   Updated: 2024/06/26 16:20:59 by mwijnsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

bool	parse_first_line(t_string *string, size_t *height,
	size_t *first_line_width)
{
	size_t	i;

	i = 0;
	while (string->characters[i] && string->characters[i] != '\n')
	{
		i++;
	}
	if (string->characters[i] != '\n' || i < 4)
	{
		return (false);
	}
	*first_line_width = i;
	g_empty_char = string->characters[i - 3];
	g_obstacle_char = string->characters[i - 2];
	g_square_char = string->characters[i - 1];
	string->characters[i - 3] = '\0';
	*height = ft_atoi(string->characters);
	return (*height > 0 && g_empty_char != g_obstacle_char
		&& g_empty_char != g_square_char && g_obstacle_char != g_square_char);
}

void	solve_square_min(t_vector pos, t_vector size,
	t_solution *solution, size_t index)
{
	unsigned int	min_neighbor;

	min_neighbor = solution->map[index - 1];
	if (solution->map[index - size.x] < min_neighbor)
		min_neighbor = solution->map[index - size.x];
	if (solution->map[index - size.x - 1] < min_neighbor)
		min_neighbor = solution->map[index - size.x - 1];
	solution->map[index] = min_neighbor + 1;
	if (solution->map[index] > solution->max_square_size)
	{
		solution->max_square_size = solution->map[index];
		solution->max_square_pos = pos;
	}
}

bool	solve_square(t_vector p, t_vector s,
	t_solution *solution, char *content)
{
	if (content[p.y * (s.x + 1) + p.x] == g_obstacle_char)
		solution->map[p.y * s.x + p.x] = 0;
	else if (content[p.y * (s.x + 1) + p.x] == g_empty_char)
	{
		if (p.x == 0 || p.y == 0)
		{
			solution->map[p.y * s.x + p.x] = 1;
			if (solution->map[p.y * s.x + p.x] > solution->max_square_size)
			{
				solution->max_square_size = solution->map[p.y * s.x + p.x];
				solution->max_square_pos = p;
			}
		}
		else
			solve_square_min(p, s, solution, p.y * s.x + p.x);
	}
	else
	{
		free(solution->map);
		ft_fputstr(2, "map error\n");
		return (false);
	}
	return (true);
}

bool	solve_loop(t_vector size, t_solution *solution, char *content)
{
	t_vector		pos;

	pos.y = 0;
	while (pos.y < size.y)
	{
		pos.x = 0;
		while (pos.x < size.x)
		{
			if (!solve_square(pos, size, solution, content))
				return (false);
			pos.x++;
		}
		if (content[pos.y * (size.x + 1) + size.x] != '\n')
		{
			free(solution->map);
			ft_fputstr(2, "map error\n");
			return (false);
		}
		pos.y++;
	}
	return (true);
}

void	fill_square(t_solution solution, t_vector size, char *content)
{
	size_t	y;
	size_t	x;

	y = solution.max_square_pos.y - (solution.max_square_size - 1);
	while (y <= solution.max_square_pos.y)
	{
		x = solution.max_square_pos.x - (solution.max_square_size - 1);
		while (x <= solution.max_square_pos.x)
		{
			content[y * (size.x + 1) + x] = g_square_char;
			x++;
		}
		y++;
	}
}
