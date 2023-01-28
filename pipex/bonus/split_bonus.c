/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:14:47 by majmani           #+#    #+#             */
/*   Updated: 2022/12/27 17:17:48 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_skeap(int num, char const *s, char c, int i)
{
	if (num == 1)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	else if (num == 2)
	{
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (i);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		i = ft_skeap(1, s, c, i);
		if (s[i] != c && s[i] != '\0')
			count++;
		i = ft_skeap(2, s, c, i);
	}
	return (count);
}

static char	*ft_str(char const *s, char c)
{
	int		i;
	int		j;
	char	*st;

	i = 0;
	j = ft_skeap(2, s, c, i);
	st = malloc(sizeof(char) * j + 1);
	if (!st)
		return (0);
	while (i < j)
	{
		st[i] = s[i];
		i++;
	}
	st[i] = '\0';
	return (st);
}

static char	**ft_free_split(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	j = 0;
	i = 0;
	if (s == NULL)
		return (0);
	str = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!str)
		return (0);
	while (s[i] != '\0')
	{
		i = ft_skeap(1, s, c, i);
		if (s[i] != c && s[i] != '\0')
		{
			str[j] = ft_str(s + i, c);
			if (str[j] == NULL)
				return (ft_free_split(str, j));
			j++;
		}
		i = ft_skeap(2, s, c, i);
	}
	str[j] = 0;
	return (str);
}
