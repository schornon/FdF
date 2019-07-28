/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:28:38 by schornon          #+#    #+#             */
/*   Updated: 2019/03/27 16:06:13 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_s_sec(t_s *new)
{
	t_mlx	*m;
	t_mid	*mid;

	m = (t_mlx*)malloc(sizeof(t_mlx));
	new->m = m;
	mid = (t_mid*)malloc(sizeof(t_mid));
	new->mid = mid;
}

t_s		*init_s(char **av)
{
	t_s		*new;
	t_po	*po;

	new = (t_s*)malloc(sizeof(t_s));
	new->fd = open(av[1], O_RDWR);
	new->buff = (char*)malloc(sizeof(char));
	new->buff[0] = '\0';
	new->f_x = 0;
	new->f_y = 0;
	new->size = 1;
	new->plane = 1;
	new->line = NULL;
	new->clrs = (int*)malloc(sizeof(int) * 8);
	new->dr = (t_dr*)malloc(sizeof(t_dr));
	new->dr->color_1 = 0xC9C9C9;
	new->dr->color_2 = 0xDB0000;
	new->color_mod = 0;
	po = create_new_po();
	new->po = po;
	init_s_sec(new);
	new->c_map = (char**)malloc(sizeof(char*));
	return (new);
}

t_po	*create_new_po(void)
{
	t_po *new;

	new = (t_po*)malloc(sizeof(t_po));
	new->x = 0.0;
	new->y = 0.0;
	new->z = 0.0;
	new->color = 0;
	new->cnt_x = 0;
	new->cnt_y = 0;
	new->zoom = 0;
	new->next = NULL;
	return (new);
}

void	data_to_list(t_s *s, int r, char **tab, int w)
{
	int		i;
	t_po	*tmp;
	t_po	*new;
	double	z;

	tmp = s->po;
	while (tmp->next != NULL)
		tmp = tmp->next;
	i = -1;
	while (++i < w)
	{
		new = create_new_po();
		new->x = (double)i;
		new->y = r;
		z = (double)ft_atoi(tab[i]);
		while (z > 10000)
			z /= 10;
		new->z = z;
		new->cnt_x = i;
		new->cnt_y = r;
		s->f_x > 50 ? new->zoom = 18 : 0;
		tmp->next = new;
		free(tab[i]);
		tmp = tmp->next;
	}
}

void	create_linked_list(t_s *s)
{
	int		w;
	int		r;
	char	**tab;

	r = -1;
	while (++r < s->f_y)
	{
		w = ft_words(s->c_map[r], ' ');
		tab = ft_strsplit(s->c_map[r], ' ');
		validate_z(w, tab);
		data_to_list(s, r, tab, w);
		free(tab);
	}
}
