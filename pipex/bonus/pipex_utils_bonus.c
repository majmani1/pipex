/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:13:56 by majmani           #+#    #+#             */
/*   Updated: 2022/12/21 15:14:53 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free(str);
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

void	ft_allocat_pipe(int i, int **f)
{
	int	j;

	j = 0;
	while (i > j)
	{
		f[j] = malloc(sizeof(int) * 2);
		j++;
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i ;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
