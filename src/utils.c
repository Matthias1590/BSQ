/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwijnsma <mwijnsma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:58:29 by mwijnsma          #+#    #+#             */
/*   Updated: 2024/06/26 16:23:23 by mwijnsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	i;

	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		return (NULL);
	}
	i = 0;
	while (i < old_size)
	{
		((char *)new_ptr)[i] = ((char *)old_ptr)[i];
		i++;
	}
	free(old_ptr);
	return (new_ptr);
}

size_t	ft_atoi(char *str)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb);
}

t_string	*read_file(int fd)
{
	t_string	*string;
	static char	buffer[8096];
	int			bytes_read;

	string = new_string();
	if (!string)
		return (NULL);
	while (true)
	{
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
		if (bytes_read < 0)
		{
			free_string(string);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!append_to_string(string, buffer))
		{
			free_string(string);
			return (NULL);
		}
	}
	return (string);
}

void	ft_fputstr(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}
