/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:11:00 by majmani           #+#    #+#             */
/*   Updated: 2022/12/27 20:12:58 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_proc_here(char *argv1,	char *argv2, char **env, int *f)
{
	char	**str;
	int		fi;

	fi = open(argv1, O_RDONLY);
	str = ft_split(argv2, ' ');
	dup2(fi, 0);
	dup2(f[1], 1);
	close(f[0]);
	close(f[1]);
	execve(get_path(env, str[0]), str, env);
}

void	second_proc_here(char *argv3, char *argv4, char **env, int *f)
{
	char	**str;
	int		fi1;

	str = ft_split(argv3, ' ');
	dup2(f[0], 0);
	fi1 = open(argv4, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fi1 == -1)
		perror("");
	dup2(fi1, 1);
	close(f[0]);
	close(f[1]);
	execve(get_path(env, str[0]), str, env);
}

void	full_proc(char **argv, char **env, int argc)
{
	int		id[2];
	int		fd[2];

	if (pipe(fd) == -1)
		perror("pipe");
	id[0] = fork();
	if (id[0] == 0)
		first_proc_here("archive.txt", argv[3], env, fd);
	id[1] = fork();
	if (id[1] == 0)
		second_proc_here(argv[4], argv[5], env, fd);
	if (id[0] != 0 && id[1] != 0)
	{
		unlink("archive.txt");
		check_command1(argv, argc, env, 2);
	}	
}

void	ft_her_doc(char **argv, int argc, char **env)
{
	int		f;
	char	*l;
	char	*p;

	f = open("archive.txt", O_CREAT | O_TRUNC | O_RDWR, 0777);
	p = ft_strjoin(argv[2], "\n");
	while (1)
	{
		write(1, "heredoc> ", 9);
		l = get_next_line(0);
		if (ft_strcmp(l, p) == 0)
			break ;
		ft_putstr_fd(l, f);
		free(l);
	}
	free(p);
	free(l);
	full_proc(argv, env, argc);
}
