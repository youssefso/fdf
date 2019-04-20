/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:23:23 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/03/09 13:05:38 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		m_kees(int button, int x, int y, t_init *init)
{
	static t_point	xl;
	static t_point	yl;
	static int		i;

	if (button == 1)
	{
		if (i == 0)
		{
			xl.x = x;
			xl.y = y;
			i = 1;
		}
		else
		{
			yl.x = x;
			yl.y = y;
			line_draw(xl, yl, init);
			mlx_put_image_to_window(init->init, init->win, init->img, 0, 0);
			i = 0;
		}
	}
	return (0);
}

void	ft_light_pixel(t_init *v, int x, int y)
{
	int i;

	if (x >= WIDTH || x < 0 || y < 0 || y >= HEIGHT)
		return ;
	i = 4 * x + 4 * y * WIDTH;
	v->img_str[i] = (unsigned char)(-v->color[v->jj][v->ii] * 2
			+ 255 + v->color_0);
	v->img_str[i + 1] = (unsigned char)(v->color[v->jj][v->ii] * 5
			+ 255 + v->color_1);
	v->img_str[i + 2] = (unsigned char)(255 + v->color_2);
}

void	initialisize(t_init *init)
{
	init->move_ver = 10;
	init->move_hoz = 0;
	init->zoom = 10;
	init->hight = 10;
	init->mode = 0;
}

void	ft_check_open(char *param)
{
	int		fd;
	char	buf[2];

	fd = open(param, O_RDONLY);
	if (read(fd, buf, 0) < 0)
	{
		ft_putstr("nothing to read \n");
		exit(1);
	}
	close(fd);
}

int		main(int ac, char **av)
{
	t_init	*init;

	if (ac == 2)
	{
		ft_check_open(av[1]);
		init = (t_init *)malloc(sizeof(t_init));
		init->fd = open(av[1], O_RDONLY);
		if (init->fd < 0)
			mini_main_1(init);
		init->param = av[1];
		mini_main(init);
	}
	else
		ft_putstr("entre one (only one) path file as param\n");
	return (0);
}
