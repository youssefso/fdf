/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:27:13 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/03/06 12:47:41 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_iso_mini_f(int **iso_map, int i, int j, t_init *init)
{
	int		ii;
	int		jj;
	t_point pi;
	t_point pf;

	jj = 0;
	while (jj < j)
	{
		ii = 0;
		while (ii + 1 < i)
		{
			pi.x = iso_map[ii + (i * jj)][0];
			pi.y = iso_map[ii + (i * jj)][1] - iso_map[ii + (i * jj)][2];
			pf.x = iso_map[ii + (i * jj) + 1][0];
			pf.y = iso_map[ii + (i * jj) + 1][1] -
	iso_map[ii + (i * jj) + 1][2];
			init->ii = ii;
			init->jj = jj;
			line_draw(pi, pf, init);
			ii++;
		}
		jj++;
	}
}

void	ft_draw_iso(int **iso_map, int i, int j, t_init *init)
{
	int		ii;
	int		jj;
	t_point pi;
	t_point pf;

	ft_iso_mini_f(iso_map, i, j, init);
	jj = 0;
	while (jj + 1 < j)
	{
		ii = 0;
		while (ii < i)
		{
			pi.x = iso_map[ii + (i * jj)][0];
			pi.y = iso_map[ii + (i * jj)][1] - iso_map[ii + (i * jj)][2];
			pf.x = iso_map[ii + (i * jj) + i][0];
			pf.y = iso_map[ii + (i * jj) + i][1] -
	iso_map[ii + (i * jj) + i][2];
			init->ii = ii;
			init->jj = jj;
			line_draw(pi, pf, init);
			ii++;
		}
		jj++;
	}
}

void	ft_read_file_mini_f(t_init *init, t_param *dini)
{
	int **iso_map;
	int i;

	i = 0;
	iso_map = NULL;
	if (init->mode == 0)
	{
		iso_map = ft_iso_calcule(dini->int_map, dini->i, dini->j, init);
		ft_draw_iso(iso_map, dini->i, dini->j, init);
		while (i < dini->i * dini->j)
			free(iso_map[i++]);
		free(iso_map);
	}
	if (init->mode == 1)
		ft_draw_para(dini->int_map, dini->i, dini->j, init);
}

void	ft_read_file_min(void)
{
	ft_putstr("nunbres in each line are not correct\n");
	exit(1);
}

void	ft_read_file(t_init *init)
{
	int				l;
	static int		k;
	static t_param	*dini;

	if (k++ == 0)
	{
		dini = (t_param *)malloc(sizeof(t_param));
		init->fre_1 = dini;
		dini->j = 1;
		dini->i = ft_alloc_map(init->fd, &dini->j);
		if (dini->i <= 0)
			ft_read_file_min();
		dini->int_map = (int **)malloc(sizeof(int *) * dini->j);
		l = -1;
		while (++l < dini->j)
			dini->int_map[l] = (int *)malloc(sizeof(int) * dini->i);
		init->fd = open(init->param, O_RDONLY);
		dini->int_map = ft_int_map(dini->int_map, dini->i, dini->j, init->fd);
		init->color = dini->int_map;
	}
	ft_read_file_mini_f(init, dini);
}
