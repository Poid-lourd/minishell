/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:11:58 by pcardin           #+#    #+#             */
/*   Updated: 2024/02/19 15:08:58 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fd	*ft_init(void)
{
	t_fd	*file_d;

	file_d = malloc(sizeof(t_fd));
	if (!file_d)
		return (NULL);
	file_d->chunk = NULL;
	file_d->line = NULL;
	file_d->totrim = NULL;
	file_d->nl = NULL;
	return (file_d);
}

void	ft_lastlineisnull(t_fd *file_d)
{
	if (*file_d->chunk == '\0')
	{
		free(file_d->chunk);
		file_d->chunk = NULL;
	}
}

char	*extract_chunk(int fd, t_fd	*file_d)
{
	ssize_t	bytesread;
	char	*temp;

	while (1)
	{
		bytesread = read(fd, file_d->buffer, BUFFER_SIZE);
		if (bytesread == -1 || bytesread == 0)
		{
			if (bytesread == 0 && file_d->chunk)
			{
				ft_lastlineisnull(file_d);
				return (file_d->chunk);
			}
			free(file_d->chunk);
			return (NULL);
		}
		file_d->buffer[bytesread] = '\0';
		temp = gnl_strjoin(file_d->chunk, file_d->buffer);
		free(file_d->chunk);
		file_d->chunk = temp;
		if (gnl_strchr(file_d->buffer, '\n') != 0)
			break ;
	}
	return (file_d->chunk);
}

char	*extract_line(int fd, t_fd	*file_d)
{
	size_t	linelen;

	file_d->chunk = extract_chunk(fd, file_d);
	if (!file_d->chunk)
		return (NULL);
	file_d->nl = gnl_strchr(file_d->chunk, '\n');
	if (file_d->nl)
	{
		linelen = ft_strlen(file_d->chunk) - ft_strlen(file_d->nl) + 1;
		file_d->line = gnl_strndup(file_d->chunk, linelen);
		file_d->totrim = file_d->chunk;
		file_d->chunk = gnl_strdup(file_d->nl + 1);
		free(file_d->totrim);
	}
	else
	{
		file_d->line = gnl_strdup(file_d->chunk);
		free(file_d->chunk);
		file_d->chunk = NULL;
	}
	return (file_d->line);
}

char	*get_next_line(int fd)
{
	static t_fd	*file_d;

	if (!file_d)
		file_d = ft_init();
	file_d->line = extract_line(fd, file_d);
	if (!file_d->line && file_d)
	{
		free(file_d);
		file_d = NULL;
		return (NULL);
	}
	return (file_d->line);
}
