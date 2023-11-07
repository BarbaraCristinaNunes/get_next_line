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

size_t	ft_strlen(const char *s)
{
	int	str_length;

	str_length = 0;
	while (s[str_length] != '\0')
		str_length++;
	return (str_length);
}

int	ft_strfind(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return (1);
}

void	ft_putstr(char *str)
{
	write (1, str, ft_strlen(str));
}

static char	*fill_concat_str(char *concat_str, char const *s1,
		char const *s2, int concat_str_length)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && i <= concat_str_length)
	{
		concat_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && i <= concat_str_length)
	{
		concat_str[i] = s2[j];
		j++;
		i++;
	}
	concat_str[i] = '\0';
	return (concat_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat_str;
	int		length;

	if (s2 == NULL)
		return ((char *)s1);
	if (s1 == NULL)
		return ((char *)s2);
	length = ft_strlen(s1) + ft_strlen(s2);
	concat_str = (char *)malloc(length + 1);
	if (concat_str == NULL)
		return (0);
	return (fill_concat_str(concat_str, s1, s2, length));
}

char	*read_file(int fd, char *buffer)
{
	int		bytes_read;
	char	break_line[1];
	bytes_read = 0;
	while (bytes_read <= BUFFER_SIZE && !ft_strfind(buffer, '\n') && read(fd, break_line, 1) > 0)
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