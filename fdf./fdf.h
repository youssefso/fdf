/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:24:48 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/03/09 12:51:00 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "./libft/includes/libft.h"
# define WIDTH 1200
# define HEIGHT 900
# include <math.h>

typedef struct	s_param
{
	int		i;
	int		j;
	int		**int_map;
}				t_param;

typedef struct	s_init
{
	int				ii;
	int				jj;
	void			*init;
	void			*win;
	void			*img;
	unsigned char	*img_str;
	int				zoom;
	int				move_ver;
	int				move_hoz;
	int				hight;
	char			*param;
	int				fd;
	int				**color;
	int				color_0;
	int				color_1;
	int				color_2;
	int				mode;
	t_param			*fre_1;
}				t_init;
typedef struct	s_point
{
	int x;
	int y;
}				t_point;
char			*get_file(int fd);
void			ft_light_pixel(t_init *v, int x, int y);
void			line_draw(t_point pi, t_point pf, t_init *init);
int				get_next_line(const int fd, char **line);
void			ft_read_file(t_init *init);
int				t_kees(int key, t_init *init);
int				**ft_iso_calcule(int **int_map, const int i,
	const int j, t_init *init);
int				**ft_stock_iso_calcule(int **iso_map, int **int_map
	, t_point p, t_init *init);
int				**ft_int_map(int **int_map, int i, int j, int fd);
int				ft_alloc_map(int fd, int *j);
void			ft_alloc_mini_f(char **str_map, char *lead, int *check);
void			ft_para_mini_f(int **int_map, int i, int j, t_init *init);
void			ft_draw_para(int **int_map, int i, int j, t_init *init);
void			mini_main_1(t_init *init);
void			mini_main(t_init *init);
int				t_kees(int key, t_init *init);
int				m_kees(int button, int x, int y, t_init *init);
void			initialisize(t_init *init);

#endif
