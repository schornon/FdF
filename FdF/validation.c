/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:29:26 by schornon          #+#    #+#             */
/*   Updated: 2019/03/27 17:18:37 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	validate_z(int w, char **tab)
{
	int r;
	int i;
	int cnt;

	r = -1;
	while (++r < w)
	{
		cnt = 0;
		i = -1;
		while (tab[r][++i])
		{
			if (tab[r][i] >= '0' && tab[r][i] <= '9')
				cnt++;
			if (!(tab[r][i] >= '0' && tab[r][i] <= '9'))
				break ;
		}
		if (cnt == 0)
		{
			ft_putendl("Not valid map(z).");
			exit(0);
		}
	}
}

void	validation(t_s *s)
{
	int j;
	int r;
	int w;

	w = ft_words(s->c_map[0], ' ');
	j = w;
	r = 0;
	while (++r < s->f_y)
	{
		w = ft_words(s->c_map[r], ' ');
		if (w != j)
		{
			ft_putendl("Not valid map.");
			exit(0);
		}
	}
}

void	usage(void)
{
	ft_putstr("Usage: ./fdf map window_width window_height 'MAIN' or 'ISO'\n");
	exit(0);
}

void	fd_checker(char **av)
{
	char	temp[1];
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (read(fd, temp, 1) < 1)
	{
		ft_putendl("Invalid file.");
		close(fd);
		exit(0);
	}
	check_win_w_h(av);
	check_pro(av);
}

void	check_win_w_h(char **av)
{
	int win_w;
	int win_h;

	win_w = ft_atoi(av[2]);
	win_h = ft_atoi(av[3]);
	if (win_w < 1 || win_w > 2000)
	{
		ft_putendl("Invalid window_width.");
		ft_putendl("Valid values from 2 to 2000");
		exit(0);
	}
	if (ft_atoi(av[3]) < 1 || win_h > 1300)
	{
		ft_putendl("Invalid window_height.");
		ft_putendl("Valid values from 2 to 1200");
		exit(0);
	}
}
