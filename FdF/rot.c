/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:47:28 by schornon          #+#    #+#             */
/*   Updated: 2019/03/27 14:06:41 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_l3(t_s *s)
{
	t_po	*tmp;
	double	prev_x;
	double	prev_y;
	double	prev_z;

	tmp = s->po;
	while (tmp)
	{
		tmp->x -= s->mid->x;
		tmp->y -= s->mid->y;
		prev_x = tmp->x;
		prev_y = tmp->y;
		prev_z = tmp->z;
		tmp->y = prev_y * cos(0.174533) - prev_z * sin(0.174533);
		tmp->z = prev_y * sin(0.174533) + prev_z * cos(0.174533);
		tmp->x += s->mid->x;
		tmp->y += s->mid->y;
		tmp = tmp->next;
	}
	draw(s);
}

void	rotate_r3(t_s *s)
{
	t_po	*tmp;
	double	prev_x;
	double	prev_y;
	double	prev_z;

	tmp = s->po;
	while (tmp)
	{
		tmp->x -= s->mid->x;
		tmp->y -= s->mid->y;
		prev_x = tmp->x;
		prev_y = tmp->y;
		prev_z = tmp->z;
		tmp->y = prev_y * cos(0.174533) + prev_z * sin(0.174533);
		tmp->z = -prev_y * sin(0.174533) + prev_z * cos(0.174533);
		tmp->x += s->mid->x;
		tmp->y += s->mid->y;
		tmp = tmp->next;
	}
	draw(s);
}

void	rotate_l2(t_s *s)
{
	t_po	*tmp;
	double	prev_x;
	double	prev_y;
	double	prev_z;

	tmp = s->po;
	while (tmp)
	{
		tmp->x -= s->mid->x;
		tmp->y -= s->mid->y;
		prev_x = tmp->x;
		prev_y = tmp->y;
		prev_z = tmp->z;
		tmp->x = prev_x * cos(0.174533) - prev_z * sin(0.174533);
		tmp->z = prev_x * sin(0.174533) + prev_z * cos(0.174533);
		tmp->x += s->mid->x;
		tmp->y += s->mid->y;
		tmp = tmp->next;
	}
	draw(s);
}

void	rotate_r2(t_s *s)
{
	t_po	*tmp;
	double	prev_x;
	double	prev_y;
	double	prev_z;

	tmp = s->po;
	while (tmp)
	{
		tmp->x -= s->mid->x;
		tmp->y -= s->mid->y;
		prev_x = tmp->x;
		prev_y = tmp->y;
		prev_z = tmp->z;
		tmp->x = prev_x * cos(0.174533) + prev_z * sin(0.174533);
		tmp->z = -prev_x * sin(0.174533) + prev_z * cos(0.174533);
		tmp->x += s->mid->x;
		tmp->y += s->mid->y;
		tmp = tmp->next;
	}
	draw(s);
}

int		ft_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (words);
}
