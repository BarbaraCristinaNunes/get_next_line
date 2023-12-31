/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banunes <nunes.barbarac@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:42:11 by banunes           #+#    #+#             */
/*   Updated: 2023/11/20 14:21:09 by banunes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buffer)
{
	int		bytes_read;
	char	break_line[1];

	bytes_read = 0;
	while (bytes_read <= BUFFER_SIZE && !ft_strchr(buffer, '\n')
		&& read(fd, break_line, 1) > 0)
	{
		buffer[bytes_read] = break_line[0];
		bytes_read++;
	}
	if (!buffer[0])
		return (NULL);
	buffer[bytes_read] = '\0';
	return (buffer);
}

int	check_argc(int argc)
{
	if (argc == 2)
		return (1);
	else if (argc < 2)
		ft_putstr("File name missing.");
	else if (argc > 2)
		ft_putstr("Too many arguments.");
	ft_putstr("\n");
	return (0);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*temp;
	char	*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || !temp)
		return (NULL);
	line = read_file(fd, buffer);
	if (!line)
	{
		free(buffer);
		free(temp);
		return (NULL);
	}
	while (!ft_strchr(line, '\n') && line != NULL)
	{
		temp = read_file(fd, temp);
		line = ft_strjoin(line, temp);
		if (!temp)
		{
			free(temp);
			return (line);
		}
	}
	free(buffer);
	free(temp);
	return (line);
}

int	main(int argc, char *argv[])
{
	int	file;

	if (check_argc(argc) == 0)
		return (0);
	file = open(argv[1], O_RDONLY);
	if (!file)
	{
		ft_putstr("Cannot read file.");
		ft_putstr("\n");
		return (0);
	}
	if (file == -1)
	{
		ft_putstr("File open error");
		close(file);
		return (1);
	}
	char	*s = get_next_line(file);
	while (s != NULL)
	{
		printf("result: %s", s);
		s = get_next_line(file);
	}
	close(file);
	return (0);
}
