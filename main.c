/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:19:05 by lpascrea          #+#    #+#             */
/*   Updated: 2020/09/27 21:29:35 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int	fd;
	int ret;	
	char buf[BUF_SIZE + 1];
	t_dico *tab;

	if (ft_check_args(argc, argv) == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
    fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error\n");
		return (0);
	}
    ret = read(fd, buf, BUF_SIZE); 
	buf[ret] = '\0';	
	if (ft_check_dict(buf) == 0)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	/*if (ft_check_keys(buf) == 0)
	{
		ft_putstr("Dict Error2\n");
		return (0);
	}*/
	tab = ft_dico_to_tab(buf);
	ft_print_number(argv[1], tab);
	/*printf("nbr d'octets : %d\n", ret);
	printf("%s", buf);
	printf("file descriptor : %d\n", fd);*/
	close (fd);
	return (0);
}
