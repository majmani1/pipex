/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majmani <majmani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:04:31 by majmani           #+#    #+#             */
/*   Updated: 2022/12/21 17:04:43 by majmani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
