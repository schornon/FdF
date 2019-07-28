/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:35:29 by schornon          #+#    #+#             */
/*   Updated: 2019/03/27 17:06:06 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <math.h>

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct		s_po
{
	double			x;
	double			y;
	double			z;
	int				zoom;
	int				color;
	int				cnt_x;
	int				cnt_y;
	struct s_po		*next;
}					t_po;

typedef struct		s_mid
{
	double			x;
	double			y;
	double			z;
	double			z_min;
}					t_mid;

typedef struct		s_s
{
	int				fd;
	char			*line;
	char			*buff;
	char			**c_map;
	int				*clrs;
	int				color_mod;
	int				f_x;
	int				f_y;
	int				size;
	int				plane;
	struct s_mlx	*m;
	struct s_po		*po;
	struct s_mid	*mid;
	struct s_dr		*dr;
	struct s_po		*back;
}					t_s;

typedef struct		s_dr
{
	double			x;
	double			y;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			dx;
	double			dy;
	double			step;
	int				i;
	int				color;
	int				color_1;
	int				color_2;
}					t_dr;

char				*ft_strjoin_f(char *s1, char const *s2);
char				*ft_jchar_f(char *s, char chr);
char				*ft_jchar_f_i(char *s, char chr, int j);
char				*ft_jchar_f_w(char *s, char chr);
char				*ft_strdup_f(char *src);
char				*b_remalloc(char *buff);
int					ft_words(char const *s, char c);
void				validation(t_s *s);
void				validate_z(int w, char **tab);
void				fd_checker(char **av);
int					x_incr(t_s *s, int n);
int					x_decr(t_s *s, int n);
int					y_incr(t_s *s, int n);
int					y_decr(t_s *s, int n);
int					change_size(t_s *s, int keycode, double n);
void				rotate_l(t_s *s);
void				rotate_r(t_s *s);
void				rotate_l2(t_s *s);
void				rotate_r2(t_s *s);
void				rotate_l3(t_s *s);
void				rotate_r3(t_s *s);
void				iso(t_s *s);
void				pars(t_s *s);
void				create_linked_list(t_s *s);
void				data_to_list(t_s *s, int r, char **tab, int w);
void				find_mid(t_s *s);
t_po				*create_new_po(void);
void				fix_po(t_s *s, int k);
void				reset_xyz(t_s *s);
void				first_draw(t_s *s, int k);
void				draw(t_s *s);
void				dda_line(t_dr *dr, t_s *s);
void				usage(void);
void				change_color(t_s *s, t_dr *dr);
void				color_mod(t_s *s);
void				check_win_w_h(char **av);
void				check_pro(char **av);
void				make_backup(t_s *s);
t_s					*init_s(char **av);

#endif
