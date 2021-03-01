/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:52:26 by lpascrea          #+#    #+#             */
/*   Updated: 2020/09/27 21:37:22 by pcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define DICO(argc) (argc == 3 ? argv[1] : "numbers.dict")
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# define BUF_SIZE 4096

void	ft_putstr(char *str);
int		ft_strlen(char *argv);
int		ft_check_args(int argc, char **argv);
int		ft_check_dict(char *buf);
int		ft_check_keys(char *buf);
char	*ft_get_number(char *av);

typedef	struct		s_dico
{
	char	*numbers;
	char	*letters;
}					t_dico;

int	ft_nb_line(char *buf);
struct s_dico	*ft_dico_to_tab(char *buf);
int		ft_nb_line(char *buf);
struct s_dico		*ft_dico_to_tab(char *buf);

void	ft_print_number(char *av, t_dico *tab);

#endif
