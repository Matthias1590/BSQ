/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwijnsma <mwijnsma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:41:52 by mwijnsma          #+#    #+#             */
/*   Updated: 2024/06/26 19:25:11 by mwijnsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include "bsq.h"

void	solve(t_vector size, t_string *string, char *content);
bool	parse_first_line(t_string *string, size_t *height,
			size_t *first_line_width);
bool	solve_loop(t_vector size, t_solution *solution, char *content);
void	fill_square(t_solution solution, t_vector size, char *content);

#endif
