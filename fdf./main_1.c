/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 12:48:01 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/03/09 12:48:21 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mini_main(t_init *init)
{
	int		bpp;
	int		s_l;
	int		endian;

	init->init = mlx_init();
	initialisize(init);
	init->win = mlx_new_window(init->init, WIDTH, HEIGHT, "fdf pdf fdp");
	mlx_hook(init->win, 2, 1, t_kees, init);
	mlx_mouse_hook(init->win, m_kees, init);
	init->img = mlx_new_image(init->init, WIDTH, HEIGHT);
	init->img_str = (unsigned char *)mlx_get_data_addr(init->img,
		&bpp, &s_l, &endian);
	ft_bzero(init->img_str, WIDTH * HEIGHT * 4);
	ft_read_file(init);
	mlx_put_image_to_window(init->init, init->win, init->img, 0, 0);
	mlx_loop(init->init);
}
