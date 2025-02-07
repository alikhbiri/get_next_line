/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 03:32:35 by alkhbiri          #+#    #+#             */
/*   Updated: 2024/12/18 01:45:21 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*_read_line(int fd, char *prompt)
{
	char	*buffer;
	int		read_bybytes;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(prompt), NULL);
	read_bybytes = 1;
	while (read_bybytes > 0 && !check_newline(prompt))
	{
		read_bybytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bybytes == -1)
			return (free(prompt), free(buffer), NULL);
		buffer[read_bybytes] = '\0';
		prompt = ft_strjoin(prompt, buffer);
	}
	free(buffer);
	if (read_bybytes == 0 && (!prompt || *prompt == '\0'))
		return (free(prompt), NULL);
	return (prompt);
}

char	*_get_line(char *prompt)
{
	char	*buffer;
	int		index;

	index = 0;
	while (prompt[index] && prompt[index] != '\n')
		index ++;
	if (prompt[index] == '\n')
		index++;
	buffer = malloc(index + 1);
	if (!buffer)
		return (NULL);
	index = 0;
	while (prompt[index] && prompt[index] != '\n')
	{
		buffer[index] = prompt[index];
		index++;
	}
	if (prompt[index] == '\n')
	{
		buffer[index] = prompt[index];
		index++;
	}
	return (buffer[index] = '\0', buffer);
}

char	*update_rest(char *prompt)
{
	int		index;
	int		j;
	char	*rest;

	index = 0;
	while (prompt[index] && prompt[index] != '\n')
		index++;
	if (prompt[index] == '\n')
		index++;
	if (!prompt[index])
		return (free(prompt), NULL);
	rest = malloc (ft_strlen(prompt) - index + 1);
	if (!rest)
		return (free(prompt), NULL);
	j = 0;
	while (prompt[index])
		rest[j++] = prompt[index++];
	rest[j] = '\0';
	return (free(prompt), rest);
}

char	*get_next_line(int fd)
{
	static char	*prompt[OPEN_MAX];
	char		*buffer;

	if (fd > OPEN_MAX)
		return (NULL);
	if (read(fd, prompt, 0) == -1 || BUFFER_SIZE <= 0)
		return (free(prompt[fd]), prompt[fd] = NULL);
	prompt[fd] = _read_line(fd, prompt[fd]);
	if (!prompt[fd])
		return (NULL);
	buffer = _get_line(prompt[fd]);
	prompt[fd] = update_rest(prompt[fd]);
	return (buffer);
}
