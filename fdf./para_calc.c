/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   para_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:38:05 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/03/05 21:30:43 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_alloc_mini_f(char **str_map, char *lead, int *check)
{
	int i;
	int j;

	j = 0;
	i = 0;
	str_map = ft_strsplit(lead, ' ');
	free(lead);
	while (str_map[i] != 0)
		i += 1;
	*check = i;
	while (j < i)
		free(str_map[j++]);
	free(str_map);
}

void	ft_para_mini_f(int **int_map, int i, int j, t_init *init)
{
	int		ii;
	int		jj;
	t_point	pi;
	t_point	pf;

	jj = 0;
	while (jj + 1 < j)
	{
		ii = 0;
		while (ii < i)
		{
			init->ii = ii;
			init->jj = jj;
			pi.x = ii * init->zoom + init->move_hoz + 500;
			pi.y = jj * init->zoom - int_map[jj][ii] * init->hight
	+ 500 + init->move_ver;
			pf.x = ii * init->zoom + init->move_hoz + 500;
			pf.y = (jj + 1) * init->zoom + 500 -
	int_map[jj + 1][ii] * init->hight + init->move_ver;
			line_draw(pi, pf, init);
			ii++;
		}
		jj++;
	}
}

void	mini_main_1(t_init *init)
{
	ft_putstr("couldn't open the file\n");
	free(init);
	exit(1);
}

void	ft_draw_para(int **int_map, int i, int j, t_init *init)
{
	int		ii;
	int		jj;
	t_point	pi;
	t_point	pf;

	ft_para_mini_f(int_map, i, j, init);
	jj = 0;
	while (jj < j)
	{
		ii = 0;
		while (ii + 1 < i)
		{
			init->ii = ii;
			init->jj = jj;
			pi.x = ii * init->zoom + 500 + init->move_hoz;
			pi.y = jj * init->zoom + 500 -
	int_map[jj][ii] * init->hight + init->move_ver;
			pf.x = (ii + 1) * init->zoom + 500 + init->move_hoz;
			pf.y = jj * init->zoom + 500 -
	int_map[jj][ii + 1] * init->hight + init->move_ver;
			line_draw(pi, pf, init);
			ii++;
		}
		jj++;
	}
}
