/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:12:51 by majmani           #+#    #+#             */
/*   Updated: 2022/12/19 15:13:01 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen( char *str)
{
	size_t	c;

	c = 0;
	if (str == NULL)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*str;

	i = -1;
	j = -1;
	if (s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (s1 == NULL && s2 == NULL)
		return (0);
	str = malloc(sizeof(const char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (0);
	while (s1[++j] != '\0')
		str[j] = s1[j];
	while (s2[++i] != '\0')
		str[j++] = s2[i];
	str[j] = '\0';
	free(s1);
	return (str);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
	}
	return (0);
}
