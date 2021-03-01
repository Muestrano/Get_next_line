/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:38:48 by lpascrea          #+#    #+#             */
/*   Updated: 2020/09/27 19:15:30 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	ft_putstr(char *str)
{
	int i;
	i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strlen(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int		ft_check_args(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 2 && argc != 3)
		return(0);
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
				return (0);
			i++;
		}
	}
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
				return (0);
			i++;
		}
	}
	return (1);
}
