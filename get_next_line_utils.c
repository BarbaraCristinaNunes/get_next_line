/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banunes <nunes.barbarac@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:29:42 by banunes           #+#    #+#             */
/*   Updated: 2023/11/07 12:44:58 by banunes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*fill_concat_str(char *concat_str, char const *s1,
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
