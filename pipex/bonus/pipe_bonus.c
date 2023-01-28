/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:29:05 by majmani           #+#    #+#             */
/*   Updated: 2022/12/27 16:08:17 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_proc(char *argv1,	char *argv2, char **env, int **f)
{
	char	**str;
	int		fi;
	char	*paths;

	close(f[0][0]);
	fi = open(argv1, O_RDONLY);
	if (fi == -1)
		exit(1);
	str = ft_split(argv2, ' ');
	dup2(fi, 0);
	dup2(f[0][1], 1);
	paths = get_path(env, str[0]);
	if (execve(paths, str, env))
		exit(0);
}

void	second_proc(char **argv, int argc, char **env, int **f)
{
	char	**str;
	int		fi1;
	char	*paths;

	close(f[argc - 5][1]);
	str = ft_split(argv[argc - 2], ' ');
	dup2(f[argc - 5][0], 0);
	fi1 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fi1 == -1)
		perror("");
	dup2(fi1, 1);
	paths = get_path(env, str[0]);
	if (execve(paths, str, env))
	{
		ft_free(str);
		free(paths);
		exit(0);
	}
}

void	x_proc(char *argv, char **env, int **f, int i)
{
	char	**str;
	int		id;

	if (pipe(f[i + 1]) == -1)
		perror("pipe");
	id = fork();
	if (id == 0)
	{
		close(f[i][1]);
		close(f[i + 1][0]);
		str = ft_split(argv, ' ');
		dup2(f[i + 1][1], 1);
		dup2(f[i][0], 0);
		if (execve(get_path(env, str[0]), str, env))
			exit(0);
	}
	close(f[i][0]);
	close(f[i][1]);
}

void	ft_full(char **argv, int argc, char **env)
{
	int	id[2];
	int	**fd;
	int	i;
	int	j;

	i = 0;
	j = 2;
	fd = malloc(sizeof(int *) * (argc - 5 + 1));
	ft_allocat_pipe(argc - 5 + 1, fd);
	if (pipe(fd[0]) == -1)
		perror("pipe");
	id[0] = fork();
	if (id[0] == 0)
		first_proc(argv[++i], argv[2], env, fd);
	j = 2;
	while (++j < argc - 2 && argc > 5)
		x_proc(argv[j], env, fd, i++);
	id[1] = fork();
	if (id[1] == 0)
	{
		second_proc(argv, argc, env, fd);
		i++;
	}	
	ft_close(fd, argc);
}

int	main(int argc, char **argv, char **env)
{	
	if (argc == 6 && ft_strcmp(argv[1], "here_doc") == 0
		&& ft_check_path_b(env, argv, argc, 1) == 1)
		ft_her_doc(argv, argc, env);
	else if (argc > 4 && ft_strcmp(argv[1], "here_doc") != 0
		&& ft_check_path_b(env, argv, argc, 0) == 1)
	{
		ft_full(argv, argc, env);
		check_command1(argv, argc, env, 1);
	}
}
