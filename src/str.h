/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwijnsma <mwijnsma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:19:56 by mwijnsma          #+#    #+#             */
/*   Updated: 2024/06/26 16:16:21 by mwijnsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include "bsq.h"

typedef struct s_string
{
	char	*characters;
	size_t	size;
}	t_string;

size_t		ft_strlen(char *str);
bool		append_to_string(t_string *str1, char *str2);
void		free_string(t_string *string);
t_string	*new_string(void);

#endif
