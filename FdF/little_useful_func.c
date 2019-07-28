/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_useful_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:29:40 by schornon          #+#    #+#             */
/*   Updated: 2019/03/27 16:02:21 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fix_po(t_s *s, int k)
{
	t_po *tmp;

	if (k == 1)
	{
		tmp = s->po;
		s->po = s->po->next;
		free(tmp);
	}
	if (k == 2)
	{
		tmp = s->back;
		s->back = s->back->next;
		free(tmp);
	}
}

char	*b_remalloc(char *buff)
{
	free(buff);
	buff = NULL;
	buff = (char*)malloc(sizeof(char) * 1);
	buff[0] = 0;
	return (buff);
}

void	change_color(t_s *s, t_dr *dr)
{
	int i;

	s->clrs[0] = 0xC9C9C9;
	s->clrs[1] = 0xDB0000;
	s->clrs[2] = 0x46B9F7;
	s->clrs[3] = 0xF1F122;
	s->clrs[4] = 0xF140E8;
	s->clrs[5] = 0x07E3D5;
	s->clrs[6] = 0x8EF92D;
	s->clrs[7] = 0xCA1153;
	i = -1;
	while (++i < 9)
	{
		dr->color_1 == s->clrs[i] ? dr->color_1 = i : 0;
		dr->color_2 == s->clrs[i] ? dr->color_2 = i : 0;
	}
	dr->color_1 >= 6 ? dr->color_1 = 0 : (dr->color_1 += 2);
	dr->color_2 >= 7 ? dr->color_2 = 0 : (dr->color_2 += 2);
	dr->color_1 = s->clrs[dr->color_1];
	dr->color_2 = s->clrs[dr->color_2];
	draw(s);
}

void	check_pro(char **av)
{
	int i;

	i = 0;
	if (ft_strcmp(av[4], "ISO") == 0)
		i = 1;
	if (ft_strcmp(av[4], "MAIN") == 0)
		i = 1;
	if (i != 1)
	{
		ft_putstr(av[4]);
		ft_putendl(" - is not valid plane.");
		ft_putendl("Make your choice between MAIN or ISO.");
		exit(0);
	}
}

void	reset_xyz(t_s *s)
{
	t_po *tmp;
	t_po *pb;

	tmp = s->po;
	pb = s->back;
	while (tmp)
	{
		tmp->x = pb->x;
		tmp->y = pb->y;
		tmp->z = pb->z;
		tmp->zoom = pb->zoom;
		pb = pb->next;
		tmp = tmp->next;
	}
	find_mid(s);
	s->plane == 1 ? first_draw(s, 1) : 0;
	s->plane == 2 ? first_draw(s, 2) : 0;
	draw(s);
}
