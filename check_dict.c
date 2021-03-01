/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdrillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:32:17 by tdrillea          #+#    #+#             */
/*   Updated: 2020/09/27 20:47:38 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*int		ft_check_keys(char *buf)
{
	char	key[BUF_SIZE + 1];
	int		fd;
	int		ret;
	int 	i;
	int 	j;
	int 	count;
	
	fd = open("keys.dict", O_RDONLY);
	ret = read(fd, key, BUF_SIZE);
	key[ret] = '\0';
	i = 0;
	count = 0;
	while (buf[i])
	{
		j = 0;
		while (key[j])
		{
			if (buf[i] == key[j])
				i++;
			j++;
		}
		i++;
	}
	return (0);
}*/

int		ft_check_dict(char *buf)
{	
	int i;
	int numbers;
	int letters;

	i = 0;
	if (buf[i] == '\0')
		return (0);
	while (buf[i])
	{
		numbers = 0;
		letters = 0;
		while (numbers == 0)
		{
			while (buf[i] >= '0' && buf[i] <= '9')
				i++;
			while (buf[i] == 32)
				i++;
			if (buf[i] != ':')
				return (0);
			numbers = 1;
		}
		while (letters == 0)
		{
			while (buf[i] >= 32 && buf[i] < 127)
				i++;
			if (buf[i] == '\n')
				letters = 1;
		}
		i++;
	}
	return (1);
}
