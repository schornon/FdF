/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:23:11 by schornon          #+#    #+#             */
/*   Updated: 2019/03/27 14:11:42 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**c_map_create(t_s *s)
{
	int		i;
	char	**c_map_n;

	c_map_n = (char**)malloc(sizeof(char*) * s->f_y + 1);
	i = -1;
	while (++i < s->f_y)
	{
		c_map_n[i] = ft_strdup_f(s->c_map[i]);
	}
	c_map_n[i] = ft_strdup_f(s->line);
	free(s->c_map);
	s->f_y++;
	return (c_map_n);
}

void	find_mid(t_s *s)
{
	t_po	*tmp;
	double	z_min;
	double	z_max;

	s->mid->x = (double)(s->f_x / 2);
	s->mid->y = (double)(s->f_y / 2);
	tmp = s->po;
	z_min = 9999999999;
	z_max = 0;
	while (tmp != NULL)
	{
		if (tmp->z < z_min)
			z_min = tmp->z;
		if (tmp->z > z_max)
			z_max = tmp->z;
		tmp->color = tmp->z;
		tmp = tmp->next;
	}
	s->mid->z = (z_max - z_min) / 2;
	s->mid->z_min = z_min;
}

void	find_f_x(t_s *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s->c_map[0][++i])
		if (s->c_map[0][i] == ' ')
			if (i > 0 && s->c_map[0][i - 1] != ' ')
				j++;
	s->f_x = j + 1;
}

void	pars(t_s *s)
{
	while (get_next_line(s->fd, &s->line) > 0)
		s->c_map = c_map_create(s);
	validation(s);
	find_f_x(s);
	create_linked_list(s);
	fix_po(s, 1);
	make_backup(s);
}

void	make_backup(t_s *s)
{
	t_po *tmp;
	t_po *b;
	t_po *pb;

	tmp = s->po;
	b = create_new_po();
	s->back = b;
	pb = b;
	while (tmp)
	{
		b = create_new_po();
		b->x = tmp->x;
		b->y = tmp->y;
		b->z = tmp->z;
		b->zoom = tmp->zoom;
		b->color = tmp->color;
		b->cnt_x = tmp->cnt_x;
		b->cnt_y = tmp->cnt_y;
		pb->next = b;
		tmp = tmp->next;
		pb = pb->next;
	}
	fix_po(s, 2);
}
