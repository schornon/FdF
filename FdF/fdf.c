/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:49:50 by schornon          #+#    #+#             */
/*   Updated: 2019/03/27 16:05:25 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int keycode, t_s *s)
{
	if (keycode == 53)
	{
		close(s->fd);
		exit(0);
	}
	if (keycode == 124 && x_incr(s, 10))
		draw(s);
	if (keycode == 123 && x_decr(s, 10))
		draw(s);
	if (keycode == 126 && y_decr(s, 10))
		draw(s);
	if (keycode == 125 && y_incr(s, 10))
		draw(s);
	if ((keycode == 116 || keycode == 121) && change_size(s, keycode, 1.1))
		draw(s);
	keycode == 89 ? rotate_l(s) : 0;
	keycode == 91 ? rotate_r(s) : 0;
	keycode == 86 ? rotate_l2(s) : 0;
	keycode == 87 ? rotate_r2(s) : 0;
	keycode == 83 ? rotate_l3(s) : 0;
	keycode == 84 ? rotate_r3(s) : 0;
	keycode == 107 ? color_mod(s) : 0;
	keycode == 105 ? reset_xyz(s) : 0;
	keycode == 113 ? change_color(s, s->dr) : 0;
	return (0);
}

int		ext(t_s *s)
{
	close(s->fd);
	exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_s *s;

	ac != 5 ? usage() : 0;
	fd_checker(av);
	if (ac == 5)
	{
		s = init_s(av);
		pars(s);
		find_mid(s);
		s->m->mlx_ptr = mlx_init();
		s->m->win_ptr = mlx_new_window(s->m->mlx_ptr, ft_atoi(av[2]),
			ft_atoi(av[3]), "FdF");
		(ft_strcmp(av[4], "ISO") == 0) ? first_draw(s, 2) : 0;
		(ft_strcmp(av[4], "MAIN") == 0) ? first_draw(s, 1) : 0;
		draw(s);
		mlx_hook(s->m->win_ptr, 2, 0, key_press, s);
		mlx_hook(s->m->win_ptr, 17, 0, ext, s);
		mlx_loop(s->m->mlx_ptr);
	}
	return (0);
}
