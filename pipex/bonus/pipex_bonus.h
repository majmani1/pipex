/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:15:00 by majmani           #+#    #+#             */
/*   Updated: 2022/12/27 17:17:37 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFFER_SIZE 100

int		ft_strchr(char *s, int c);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
void	ft_free(char **str);
void	ft_allocat_pipe(int i, int **f);
char	*get_next_line(int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_her_doc(char **argv, int argc, char **env);
char	*get_path(char **env, char *cmd);
int		ft_strcmp(char *s1, char *s2);
void	check_command(char **argv, int argc, char **env, int etat);
int		ft_check_path_b(char **env, char **argv, int argc, int etat);
void	ft_close(int **f, int i);
char	*get_path(char **env, char *cmd);
void	check_command1(char **argv, int argc, char **env, int etat);
char	*get_next_line(int fd);
int		ft_strchr(char *s, int c);
size_t	ft_strlen( char *str);
char	*ft_strjoin1(char *s1, char *s2);
char	*before(char *s);
char	*after(char *s);
char	*ft_read(int fd, char *str);

#endif