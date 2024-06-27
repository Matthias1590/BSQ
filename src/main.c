/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwijnsma <mwijnsma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:45:57 by mwijnsma          #+#    #+#             */
/*   Updated: 2024/06/26 19:23:24 by mwijnsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	g_line_buffer[MAX_LINE_LENGTH];
char	g_empty_char;
char	g_obstacle_char;
char	g_square_char;

void	process_file(int fd)
{
	size_t		first_line_width;
	t_string	*content;
	t_vector	size;

	content = read_file(fd);
	if (!content)
	{
		ft_fputstr(2, "map error\n");
		free_string(content);
		return ;
	}
	if (!parse_first_line(content, &size.y, &first_line_width))
	{
		ft_fputstr(2, "map error\n");
		free_string(content);
		return ;
	}
	size.x = (content->size - first_line_width - 2) / size.y - 1;
	if ((content->size - first_line_width - 2) % size.y != 0)
	{
		ft_fputstr(2, "map error\n");
		free_string(content);
		return ;
	}
	solve(size, content, content->characters + first_line_width + 1);
}

void	solve(t_vector size, t_string *string, char *content)
{
	t_solution		solution;

	solution.max_square_size = 0;
	solution.map = malloc(sizeof(unsigned int) * size.x * size.y);
	if (!solution.map)
	{
		ft_fputstr(2, "map error\n");
		free_string(string);
		return ;
	}
	if (!solve_loop(size, &solution, content))
	{
		free_string(string);
		return ;
	}
	if (solution.max_square_size != 0)
	{
		fill_square(solution, size, content);
	}
	free(solution.map);
	ft_fputstr(1, content);
	free_string(string);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
	{
		process_file(0);
		return (0);
	}
	while (argc > 1)
	{
		fd = open(*(++argv), O_RDONLY);
		if (fd < 0)
		{
			ft_fputstr(2, "map error\n");
			if (argc > 2)
				ft_fputstr(1, "\n");
			argc--;
			continue ;
		}
		process_file(fd);
		if (argc > 2)
			ft_fputstr(1, "\n");
		close(fd);
		argc--;
	}
	return (0);
}
