/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:23:05 by schornon          #+#    #+#             */
/*   Updated: 2019/03/27 15:44:24 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		change_down_dxy(t_dr *dr, t_s *s, t_po *tmp1, t_po *tmp2)
{
	int i;

	if (tmp1->cnt_y == s->f_y - 1)
		return (0);
	i = -1;
	while (++i + 1 < s->f_x)
		tmp2 = tmp2->next;
	if (s->color_mod == 1)
	{
		((int)tmp2->color == tmp1->color) ? dr->color = dr->color_1 : 0;
		((int)tmp2->color != tmp1->color) ? dr->color = dr->color_2 : 0;
	}
	if (s->color_mod == 0)
	{
		((int)tmp2->color == tmp1->color) ? dr->color = dr->color_1 : 0;
		if ((int)tmp2->color > 0 || (int)tmp1->color > 0)
			dr->color = dr->color_2;
	}
	dr->x1 = tmp1->x * s->size;
	dr->y1 = tmp1->y * s->size;
	dr->x2 = tmp2->x * s->size;
	dr->y2 = tmp2->y * s->size;
	return (1);
}

int		change_dxy(t_dr *dr, t_s *s, t_po *tmp1, t_po *tmp2)
{
	if (tmp1->cnt_x == s->f_x - 1)
		return (0);
	if (s->color_mod == 1)
	{
		if ((int)tmp2->color == tmp1->color)
			dr->color = dr->color_1;
		if ((int)tmp2->color != tmp1->color)
			dr->color = dr->color_2;
	}
	if (s->color_mod == 0)
	{
		((int)tmp2->color == tmp1->color) ? dr->color = dr->color_1 : 0;
		if ((int)tmp2->color > 0 || (int)tmp1->color > 0)
			dr->color = dr->color_2;
	}
	dr->x1 = tmp1->x * s->size;
	dr->y1 = tmp1->y * s->size;
	dr->x2 = tmp2->x * s->size;
	dr->y2 = tmp2->y * s->size;
	return (1);
}

void	dda_line(t_dr *dr, t_s *s)
{
	dr->dx = (dr->x2 - dr->x1);
	dr->dy = (dr->y2 - dr->y1);
	if (fabs(dr->dx) >= fabs(dr->dy))
		dr->step = fabs(dr->dx);
	else
		dr->step = fabs(dr->dy);
	if (dr->step == 0)
		return ;
	dr->x = dr->x1;
	dr->y = dr->y1;
	dr->dx = dr->dx / dr->step;
	dr->dy = dr->dy / dr->step;
	dr->i = 1;
	while (dr->i <= dr->step)
	{
		mlx_pixel_put(s->m->mlx_ptr, s->m->win_ptr, dr->x, dr->y, dr->color);
		dr->x = dr->x + dr->dx;
		dr->y = dr->y + dr->dy;
		dr->i = dr->i + 1;
	}
}

void	iso(t_s *s)
{
	double	prev_x;
	double	prev_y;
	t_po	*tmp;

	tmp = s->po;
	s->plane = 2;
	while (tmp)
	{
		tmp->x -= s->mid->x;
		tmp->y -= s->mid->y;
		prev_x = tmp->x;
		prev_y = tmp->y;
		tmp->x = (prev_x - prev_y) * cos(0.523599);
		tmp->y = -tmp->z / 10 + (prev_x + prev_y) * sin(0.523599);
		tmp->x += s->mid->x;
		tmp->y += s->mid->y;
		tmp = tmp->next;
	}
}

void	draw(t_s *s)
{
	t_po *tmp1;
	t_po *tmp2;

	mlx_clear_window(s->m->mlx_ptr, s->m->win_ptr);
	tmp1 = s->po;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		change_dxy(s->dr, s, tmp1, tmp2) == 1 ? dda_line(s->dr, s) : 0;
		change_down_dxy(s->dr, s, tmp1, tmp2) == 1 ? dda_line(s->dr, s) : 0;
		tmp1 = tmp1->next;
	}
}
