/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:15:33 by majmani           #+#    #+#             */
/*   Updated: 2022/12/21 14:55:23 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	**ft_free(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free(str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*str;

	i = -1;
	j = -1;
	if (s1 == NULL || s2 == NULL)
		return (0);
	str = malloc(sizeof(const char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (0);
	while (s1[++j] != '\0')
		str[j] = s1[j];
	while (s2[++i] != '\0')
		str[j++] = s2[i];
	str[j] = '\0';
	return (str);
}

int	ft_check_path(char **env, char *cmd1, char *cmd2)
{
	int	i;

	i = 0;
	if (access(cmd1, X_OK) != -1 && access(cmd2, X_OK) != -1)
		return (1);
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (1);
		i++;
	}
	return (0);
}
