/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:57:42 by majmani           #+#    #+#             */
/*   Updated: 2022/12/27 16:00:27 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close(int **f, int argc)
{
	close(f[argc - 5][1]);
	close(f[argc - 5][0]);
	while (wait(NULL) != -1)
		;
}

int	ft_add(char **str, int i, char *com_total, char *com)
{
	ft_free(str);
	free(com);
	if (str[i] == NULL)
	{
		free(com_total);
		return (0);
	}
	return (1);
}

char	*get_path(char **env, char *cmd)
{
	int		i;
	char	**str;
	char	*com_total;
	char	*com;

	i = 0;
	if (access(cmd, X_OK) != -1)
		return (cmd);
	while (ft_strncmp("PATH=", env[i], 5) != 0)
		i++;
	str = ft_split(&env[i][5], ':');
	i = 0;
	com = ft_strjoin("/", cmd);
	com_total = ft_strjoin(str[i++], com);
	while (str[i] && access(com_total, X_OK) == -1)
	{
		free(com_total);
		com_total = ft_strjoin(str[i++], com);
	}
	if (ft_add(str, i, com_total, com) == 0)
		return (NULL);
	return (com_total);
}

void	check_command1(char **argv, int argc, char **env, int etat)
{
	int		i;
	char	**str;

	i = 3;
	if (etat == 1)
	{
		i = 2;
		if (open(argv[1], O_RDONLY) == -1)
			perror("file");
	}
	while (i < argc - 1)
	{
		str = ft_split(argv[i], ' ');
		if (!get_path(env, str[0]))
		{
			write(2, argv[i], ft_strlen(argv[i]));
			write(2, ": Command not found", 19);
			write(2, "\n", 1);
			if (i == argc -2)
				exit (127);
		}
		free(str);
		i++;
	}
	exit(0);
}

int	ft_check_path_b(char **env, char **argv, int argc, int etat)
{
	int		i;

	if (etat == 1)
		i = 3;
	else
		i = 2;
	while (i < argc - 1)
	{
		if (access(argv[i], X_OK) != -1)
			return (1);
		i++;
	}
	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (1);
		i++;
	}
	return (0);
}
