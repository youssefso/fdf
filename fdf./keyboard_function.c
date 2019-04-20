/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:59:00 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/03/05 21:10:08 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	t_kees_mini_f(int key, t_init *init)
{
	if (key == 4)
		init->mode = 1;
	if (key == 5)
		init->mode = 0;
	if (key == 0)
		init->color_0 -= 10;
	if (key == 1)
		init->color_1 -= 10;
	if (key == 2)
		init->color_2 -= 10;
	if (key == 12)
		init->color_0 += 10;
	if (key == 13)
		init->color_1 += 10;
	if (key == 14)
		init->color_2 += 10;
	if (key == 69)
		init->zoom += 1;
	if (key == 124)
		init->move_hoz += 10;
	if (key == 123)
		init->move_hoz -= 10;
}

void	t_kees_1(int key, t_init *init)
{
	if (key == 16)
	{
		init->color_0 = 40;
		init->color_2 = 70;
	}
	t_kees_mini_f(key, init);
	if (key == 126)
		init->move_ver -= 10;
	if (key == 125)
		init->move_ver += 10;
	if (key == 53)
	{
		free(init->fre_1);
		free(init->color);
		free(init);
		exit(0);
	}
	if ((key >= 0 && key <= 5) || (key >= 12 && key <= 16)
	|| key == 53 || key == 78
	|| key == 69 || (key >= 123 && key <= 126))
		ft_read_file(init);
}

int		t_kees(int key, t_init *init)
{
	if ((key >= 0 && key <= 5) || (key >= 12 && key <= 16)
	|| key == 53 || key == 78
	|| key == 69 || (key >= 123 && key <= 126))
		ft_bzero(init->img_str, WIDTH * HEIGHT * 4);
	if (key == 3)
	{
		init->hight -= 1;
	}
	if (key == 15)
	{
		init->hight += 1;
	}
	if (key == 78)
	{
		if (init->zoom > 1)
			init->zoom -= 1;
	}
	t_kees_1(key, init);
	mlx_put_image_to_window(init->init, init->win, init->img, 0, 0);
	return (0);
}
