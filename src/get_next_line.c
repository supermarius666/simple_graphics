/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdumitru <mdumitru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:10:26 by mdumitru          #+#    #+#             */
/*   Updated: 2024/12/16 13:29:17 by mdumitru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *saved_str)
{
	char		*buffer;
	int			read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!gnl_strchr(saved_str, '\n') && read_bytes)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(saved_str);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		saved_str = gnl_strjoin(saved_str, buffer);
	}
	free(buffer);
	return (saved_str);
}

char	*get_next_line(int fd)
{
	static char	*s_saved;
	size_t		end;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s_saved)
	{
		s_saved = malloc(sizeof(char));
		*s_saved = '\0';
	}
	s_saved = ft_read_line(fd, s_saved);
	if (!s_saved)
		return (NULL);
	end = 0;
	while (s_saved[end] != '\n' && s_saved[end])
		end++;
	line = gnl_substr(s_saved, 0, end + 1, 0);
	s_saved = gnl_substr(s_saved, end + 1, BUFFER_SIZE + 1, 1);
	return (line);
}
