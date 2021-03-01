/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:51:38 by lpascrea          #+#    #+#             */
/*   Updated: 2020/09/27 23:04:13 by pcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_unit(char res, t_dico *tab, int end)
{
	int i;
	i = 0;
	while (res != tab[i].numbers[0] || tab[i].numbers[1] != '\0')
		i++;
	ft_putstr(tab[i].letters);
	if (!end)
		write(1, " ", 1);
}

void	ft_print_1019(char *res, t_dico *tab, int i)
{
	int j;
	j = 0;
	while (res[i] != tab[j].numbers[0] || res[i + 1] != tab[j].numbers[1] ||
			ft_strlen(tab[j].numbers) != 2)
		j++;
	ft_putstr(tab[j].letters);
	write(1, " ", 1);
}

void	ft_print_2090(char *res, t_dico *tab, int i)
{
	int j;
	j = 0;
	while (res[i] != tab[j].numbers[0] || tab[j].numbers[1] != '0' ||
			ft_strlen(tab[j].numbers) != 2)
		j++;
	ft_putstr(tab[j].letters);
	write(1, " ", 1);
}

void	ft_print_power10(int len, t_dico *tab, int i)
{
	int j;
	int check;
	j = i;
	check = 1;
	if (len > 37)
	{
		ft_print_power10(len % 37, tab, i);
		if (len - (len % 37) > 37)
			ft_print_power10(len - 37 - (len % 37), tab, i);
		else
			ft_print_power10(len - (len % 37), tab, i);
	}
	else
	{
		while (len != ft_strlen(tab[j].numbers))
			j++;
		while (tab[j].numbers[check])
		{
			if (tab[j].numbers[check] != '0')
				ft_print_power10(len, tab, j);
			check++;
		}
	}
	if (check == len && tab[j].numbers[0] != '0')
	{
		ft_putstr(tab[j].letters);
		write(1, " ", 1);
	}
}

void	ft_print_zero(t_dico *tab)
{
	int j;
	j = 0;
	while (tab[j].numbers[0] != '0' || tab[j].numbers[1] != '\0')
		j++;
	ft_putstr(tab[j].letters);
}

void	ft_print_number(char *av, t_dico *tab)
{
	int i;
	int len;
	int zeros;
	int end;

	i = 0;
	zeros = 0;
	end = 0;
	len = ft_strlen(av);
	if (len == 1 && av[0] == '0')
	{
		ft_print_zero(tab);
	}
	else
	{
		while(av[i])
		{
			if (len - i == 1)
				end = 1;
			if (av[i] == '0')
			{
				zeros++;
				if ((len - i) % 3 == 1 && zeros < 3)
					ft_print_power10(len - i, tab, 0);
			}
			else
			{
				if ((len - i) % 3 == 1)
				{
					ft_print_unit(av[i], tab, end);
					if (len - i > 1)
						ft_print_power10((len - i), tab, 0);
				}
				else if ((len - i) % 3 == 2)
				{
					if (av[i] == '1')
					{
						ft_print_1019(av, tab, i);
						i++;
						ft_print_power10(len - i, tab, 0);
					}
					else
						ft_print_2090(av, tab, i);
				}
				else
				{
					ft_print_unit(av[i], tab, end);
					ft_print_power10(3, tab, 0);
				}
			}
			i++;
		}
	}
}
