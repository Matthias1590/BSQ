/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwijnsma <mwijnsma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:01:18 by mwijnsma          #+#    #+#             */
/*   Updated: 2024/06/26 16:16:25 by mwijnsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_string	*new_string(void)
{
	t_string	*string;

	string = malloc(sizeof(t_string));
	if (!string)
	{
		return (NULL);
	}
	string->characters = malloc(1);
	if (!string->characters)
	{
		free_string(string);
		return (NULL);
	}
	string->characters[0] = '\0';
	string->size = 1;
	return (string);
}

void	free_string(t_string *string)
{
	if (string)
	{
		if (string->characters)
		{
			free(string->characters);
		}
		free(string);
	}
}

bool	append_to_string(t_string *str1, char *str2)
{
	size_t	str2_len;
	size_t	i;

	str2_len = ft_strlen(str2);
	str1->characters = ft_realloc(str1->characters,
			str1->size, str1->size + str2_len);
	if (!str1->characters)
	{
		return (false);
	}
	i = 0;
	while (i < str2_len)
	{
		str1->characters[str1->size - 1 + i] = str2[i];
		i++;
	}
	str1->size += str2_len;
	str1->characters[str1->size - 1] = '\0';
	return (true);
}
