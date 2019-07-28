/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_size_ect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:21:30 by schornon          #+#    #+#             */
/*   Updated: 2019/03/27 15:46:23 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_l(t_s *s)
{
	t_po	*tmp;
	double	prev_x;
	double	prev_y;

	tmp = s->po;
	while (tmp)
	{
		tmp->x -= s->mid->x;
		tmp->y -= s->mid->y;
		prev_x = tmp->x;
		prev_y = tmp->y;
		tmp->x = prev_x * cos(0.174533) + prev_y * sin(0.174533);
		tmp->y = -prev_x * sin(0.174533) + prev_y * cos(0.174533);
		tmp->x += s->mid->x;
		tmp->y += s->mid->y;
		tmp = tmp->next;
	}
	draw(s);
}

void	rotate_r(t_s *s)
{
	t_po	*tmp;
	double	prev_x;
	double	prev_y;

	tmp = s->po;
	while (tmp)
	{
		tmp->x -= s->mid->x;
		tmp->y -= s->mid->y;
		prev_x = tmp->x;
		prev_y = tmp->y;
		tmp->x = prev_x * cos(0.174533) - prev_y * sin(0.174533);
		tmp->y = prev_x * sin(0.174533) + prev_y * cos(0.174533);
		tmp->x += s->mid->x;
		tmp->y += s->mid->y;
		tmp = tmp->next;
	}
	draw(s);
}

int		change_size(t_s *s, int keycode, double n)
{
	t_po	*tmp;

	tmp = s->po;
	while (tmp)
	{
		tmp->x -= s->mid->x;
		tmp->y -= s->mid->y;
		if (keycode == 116 && tmp->zoom <= 50)
		{
			tmp->x *= n;
			tmp->y *= n;
			tmp->zoom++;
		}
		if (keycode == 121 && tmp->zoom > 18)
		{
			tmp->x /= n;
			tmp->y /= n;
			tmp->zoom--;
		}
		tmp->x += s->mid->x;
		tmp->y += s->mid->y;
		tmp = tmp->next;
	}
	return (1);
}

void	color_mod(t_s *s)
{
	if (s->color_mod == 0)
		s->color_mod = 1;
	else if (s->color_mod != 0)
		s->color_mod = 0;
	draw(s);
}
