/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:29:05 by majmani           #+#    #+#             */
/*   Updated: 2022/12/27 16:06:38 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	first_proc(char *argv1,	char *argv2, char **env, int *f)
{
	char	**str;
	int		fi;
	int		l;
	char	*paths;

	l = 0;
	fi = open(argv1, O_RDONLY);
	if (fi == -1)
		exit(1);
	str = ft_split(argv2, ' ');
	dup2(fi, 0);
	dup2(f[1], 1);
	close(f[0]);
	close(f[1]);
	paths = get_path(env, str[0]);
	if (execve(paths, str, env))
		exit(0);
}

void	second_proc(char *argv3, char *argv4, char **env, int *f)
{
	char	**str;
	int		fi1;
	char	*paths;

	str = ft_split(argv3, ' ');
	dup2(f[0], 0);
	fi1 = open(argv4, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fi1 == -1)
		perror("");
	dup2(fi1, 1);
	close(f[0]);
	close(f[1]);
	paths = get_path(env, str[0]);
	if (execve(paths, str, env))
		exit(0);
}

void	check_command(char **argv, int argc, char **env)
{
	int		i;
	char	**str;

	i = 2;
	if (open(argv[1], O_RDONLY) == -1)
		perror("file");
	while (i < argc - 1)
	{
		str = ft_split(argv[i], ' ');
		if (!get_path(env, str[0]))
		{
			write(2, "Command not found: ", 19);
			write(2, argv[i], ft_strlen(argv[i]));
			write(2, "\n", 1);
			if (i == argc - 2)
				exit (127);
		}
		free(str);
		i++;
	}
	exit(0);
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	id[2];

	if (argc == 5 && ft_check_path(env, argv[2], argv[3]) == 1)
	{
		if (pipe(fd) == -1)
			perror("pipe");
		id[0] = fork();
		if (id[0] == 0)
			first_proc(argv[1], argv[2], env, fd);
		id[1] = fork();
		if (id[1] == 0)
			second_proc(argv[3], argv[4], env, fd);
		if (id[0] != 0 && id[1] != 0)
		{
			close(fd[1]);
			close(fd[0]);
			waitpid(id[0], NULL, 0);
			waitpid(id[1], NULL, 0);
			check_command(argv, argc, env);
		}
	}
	else
		exit(127);
	return (0);
}
