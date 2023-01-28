/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:17:28 by majmani           #+#    #+#             */
/*   Updated: 2022/12/21 17:04:14 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	**ft_free(char **str);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen( char *str);
int		ft_check_path(char **env, char *cmd1, char *cmd2);
int		ft_add(char **str, int i, char *com_total, char *com);

#endif
