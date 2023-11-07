/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banunes <nunes.barbarac@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:33:22 by banunes           #+#    #+#             */
/*   Updated: 2023/11/07 12:46:28 by banunes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
int		ft_strfind(const char *s, int c);
void	ft_putstr(char *str);
char	*fill_concat_str(char *concat_str, char const *s1,
			char const *s2, int concat_str_length);
char	*ft_strjoin(char const *s1, char const *s2);

#endif