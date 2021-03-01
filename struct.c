/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:42:53 by lpascrea          #+#    #+#             */
/*   Updated: 2020/09/27 21:03:49 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_nb_line(char *buf)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

void	ft_copy_words(char *buf, t_dico *tab)
{
	int i;
	int k;
	int j;
	int count;
	int spaces;
	
	i = 0;
	k = 0;
	j = 0;
	count = 0;
	spaces = 0;
	while (buf[i])
	{
		j = 0;
		if (buf[i - 1] == ':')
			count++;
		while (buf[i] == 32)
			i++;
		while (buf[i] > 31 && buf[i] < 127 && count == 1)
		{
			if ((buf[i] == 32  && buf[i + 1] == 32) || buf[i] == '\n' || (buf[i] == 32 && buf[i + 1] == '\n'))
				i++;
			else
			{
				tab[k].letters[j] = buf[i];
				i++;
				j++;
			}
		}
		if (j != 0 && count == 1)
			k++;
		count = 0;
		i++;
	}

}

void	ft_malloc_words(char *buf, t_dico *tab)
{
	int i;
	int j;
	int k;
	int count;
	int start;
	int words_to_malloc;

	i = 0;
	j = 0;
	k = 0;
	count = 0;
	start = 0;
	words_to_malloc = 0;
	while (buf[i])
	{
		
		while (buf[i] == 32 || buf[i] == ':')
		{
			if (buf[i] == ':')
				start = 1;
			i++;
		}
		while (buf[i] >= 32 && buf[i] < 127 && start == 1)
		{
			i++;
			words_to_malloc++;
		}
		if (words_to_malloc != 0)
		{
			if(!(tab[k].letters = malloc(sizeof(char) * (words_to_malloc + 1))))
				return ;
			k++;
		}
		if (buf[i] == '\n')
		{
			start = 0;
			words_to_malloc = 0;
		}
		i++;
	}
	tab[k].letters = 0;
	ft_copy_words(buf, tab);
}

void	ft_copy_nbr(char *buf, t_dico *tab)
{
	int i;
	int k;
	int j;
	int count;
	
	i = 0;
	k = 0;
	j = 0;
	count = 0;
	while (buf[i])
	{
		j = 0;
		if (buf[i - 1] == ':')
			count++;
		while (buf[i] >= '0' && buf[i] <= '9' && count < 1)
		{
			tab[k].numbers[j] = buf[i];
			i++;
			j++;
		}
		if (j != 0 && count < 1)
		{
			tab[k].numbers[j] = 0;
			k++;
		}
		count = 0;
		i++;
	}
}

struct s_dico	*ft_dico_to_tab(char *buf)
{
	t_dico *tab;
	int i;
	int k;
	int nbr_to_malloc;
	int count;

	i = 0;
	k = 0;
	count = 0;
	if (!(tab = malloc(sizeof(struct s_dico) * (ft_nb_line(buf) + 1))))
		return (0);
	
	while (buf[i])
	{
		nbr_to_malloc = 0;
		if (buf[i - 1] == ':')
			count++;
		while (buf[i] >= '0' && buf[i] <= '9')
		{
			i++;
			nbr_to_malloc++;
		}
		if (nbr_to_malloc != 0 && count < 1)
		{
			if (!(tab[k].numbers = malloc(sizeof(char) * (nbr_to_malloc + 1))))
				return (0);
			k++;
		}
		count = 0;
		i++;
		tab[k].numbers = 0;
	}
	ft_copy_nbr(buf, tab);
	ft_malloc_words(buf, tab);
	/*k = 0;
	while (tab[k].numbers)
	{
		ft_putstr(tab[k].letters);
		write(1, "\n", 1);
		k++;
	}*/
	return (tab);
}
