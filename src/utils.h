/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwijnsma <mwijnsma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:01:37 by mwijnsma          #+#    #+#             */
/*   Updated: 2024/06/26 15:43:51 by mwijnsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "bsq.h"

typedef struct s_vector
{
	size_t	x;
	size_t	y;
}	t_vector;

typedef struct s_solution
{
	unsigned int	max_square_size;
	t_vector		max_square_pos;
	unsigned int	*map;
}	t_solution;

void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
size_t		ft_atoi(char *str);
t_string	*read_file(int fd);
void		ft_fputstr(int fd, char *str);

#endif
