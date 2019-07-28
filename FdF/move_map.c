/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:21:55 by schornon          #+#    #+#             */
/*   Updated: 2019/03/27 14:10:11 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		x_incr(t_s *s, int n)
{
	t_po *tmp;

	tmp = s->po;
	s->mid->x += n;
	while (tmp)
	{
		tmp->x += n;
		tmp = tmp->next;
	}
	return (1);
}

int		x_decr(t_s *s, int n)
{
	t_po *tmp;

	tmp = s->po;
	s->mid->x -= n;
	while (tmp)
	{
		tmp->x -= n;
		tmp = tmp->next;
	}
	return (1);
}

int		y_incr(t_s *s, int n)
{
	t_po *tmp;

	tmp = s->po;
	s->mid->y += n;
	while (tmp)
	{
		tmp->y += n;
		tmp = tmp->next;
	}
	return (1);
}

int		y_decr(t_s *s, int n)
{
	t_po *tmp;

	tmp = s->po;
	s->mid->y -= n;
	while (tmp)
	{
		tmp->y -= n;
		tmp = tmp->next;
	}
	return (1);
}

void	first_draw(t_s *s, int k)
{
	int i;

	i = -1;
	if (k == 2)
	{
		iso(s);
		while (++i < 18 && s->f_x < 50 && s->f_y < 50)
		{
			change_size(s, 116, 1.2);
			x_incr(s, 20);
			y_incr(s, 20);
		}
		draw(s);
	}
	if (k == 1 && s->f_x < 50 && s->f_y < 50)
	{
		while (++i < 18)
		{
			change_size(s, 116, 1.2);
			x_incr(s, 20);
			y_incr(s, 20);
		}
	}
}
