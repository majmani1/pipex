/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:52:02 by majmani           #+#    #+#             */
/*   Updated: 2022/12/19 15:12:17 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_read(int fd, char *str)
{
	char	*s;
	int		r;

	r = 1;
	s = malloc((size_t)BUFFER_SIZE + 1);
	if (s == NULL)
		return (0);
	while (!ft_strchr(str, '\n') && r != 0)
	{
		r = read(fd, s, BUFFER_SIZE);
		if (r == -1)
		{
			free(str);
			free(s);
			return (NULL);
		}
		s[r] = '\0';
		str = ft_strjoin1(str, s);
	}
	free(s);
	return (str);
}

char	*before(char *s)
{
	char	*sh;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		sh = malloc(i + 1);
	else
		sh = malloc(i + 2);
	if (sh == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		sh[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		sh[i++] = '\n';
	sh[i] = '\0';
	return (sh);
}

char	*after(char *s)
{
	char	*sh;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	sh = malloc(ft_strlen(s) - i + 1);
	if (sh == NULL)
		return (NULL);
	while (s[++i] != '\0')
		sh[j++] = s[i];
	sh[j] = '\0';
	free(s);
	return (sh);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	l = before(str);
	str = after(str);
	if (l[0] == '\0')
	{
		free(l);
		return (NULL);
	}
	return (l);
}
