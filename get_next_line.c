/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banunes <nunes.barbarac@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:42:11 by banunes           #+#    #+#             */
/*   Updated: 2023/11/02 15:40:39 by banunes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*read_file(int fd, char *buffer)
{
	int		bytes_read;
	char	break_line[1];

	bytes_read = 0;
	while (bytes_read <= BUFFER_SIZE && !ft_strfind(buffer, '\n')
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

	if (fd < 0 || BUFFER_SIZE == 0)
	{
		ft_putstr("File open error");
		close(fd);
		return (NULL);
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer = read_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	while (!ft_strfind(buffer, '\n'))
	{
		temp = read_file(fd, temp);
		buffer = ft_strjoin(buffer, temp);
		if (temp == NULL)
		{
			free(temp);
			return (buffer);
		}
	}
	free(temp);
	return (buffer);
}

int	main(int argc, char *argv[])
{
	int	file;

	if (check_argc(argc) == 0)
		return (0);
	if (!fopen(argv[1], "r"))
	{
		ft_putstr("Cannot read file.");
		ft_putstr("\n");
		return (0);
	}
	file = open(argv[1], O_RDONLY);
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
