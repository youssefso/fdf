/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_calcul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:36:34 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/03/09 13:13:09 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_alloc_mini_line(int check, int fd)
{
	close(fd);
	return (check);
}

int		ft_alloc_map(int fd, int *j)
{
	int		i;
	int		check;
	char	*lead;
	char	**str_map;

	str_map = NULL;
	if (get_next_line(fd, &lead) == 0)
		return (0);
	ft_alloc_mini_f(str_map, lead, &check);
	while (1)
	{
		i = 0;
		if (get_next_line(fd, &lead) == 0)
			return (ft_alloc_mini_line(check, fd));
		str_map = ft_strsplit(lead, ' ');
		free(lead);
		while (str_map[i] != 0)
			i += 1;
		free(str_map);
		if (check > i)
			return (-1);
		*j += 1;
	}
	return (0);
}

int		**ft_int_map(int **int_map, int i, int j, int fd)
{
	char	*str_map;
	char	**str_map_split;
	int		l;
	int		ll;

	l = 0;
	ll = 0;
	while (ll < j)
	{
		l = 0;
		if (get_next_line(fd, &str_map) <= 0)
			exit(1);
		str_map_split = ft_strsplit(str_map, ' ');
		while (l < i)
		{
			int_map[ll][l] = ft_atoi(str_map_split[l]);
			l++;
		}
		ll++;
		free(str_map_split);
	}
	free(str_map);
	return (int_map);
}

int		**ft_stock_iso_calcule(int **iso_map, int **int_map
	, t_point p, t_init *init)
{
	int jj;
	int ii;
	int il;
	int jl;

	jj = 0;
	while (jj < p.y)
	{
		ii = 0;
		while (ii < p.x)
		{
			il = ii * init->zoom;
			jl = jj * init->zoom;
			iso_map[ii + (p.x * jj)][0] = init->move_hoz + 500 +
		(il - jl) * cos(0.523599);
			iso_map[ii + (p.x * jj)][1] = init->move_ver + 500 +
		(il + jl) * sin(0.523599);
			iso_map[ii + (p.x * jj)][2] = int_map[jj][ii] * init->hight / 8;
			ii++;
		}
		jj++;
	}
	return (iso_map);
}

int		**ft_iso_calcule(int **int_map, const int i, const int j, t_init *init)
{
	int			**iso_map;
	int			l;
	t_point		p;

	p.x = i;
	p.y = j;
	l = 0;
	iso_map = (int **)malloc(sizeof(int *) * i * j);
	while (l < i * j)
	{
		iso_map[l] = (int *)malloc(sizeof(int) * 3);
		ft_bzero(iso_map[l], 12);
		l++;
	}
	iso_map = ft_stock_iso_calcule(iso_map, int_map, p, init);
	return (iso_map);
}
