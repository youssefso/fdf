/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:09:47 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/03/04 22:21:26 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	slop_high(t_point pi, t_point pf, t_init *init)
{
	int dx;
	int dy;
	int xi;
	int pxx;

	dx = abs(pf.x - pi.x);
	dy = pf.y - pi.y;
	xi = (pf.x - pi.x >= 0) ? 1 : -1;
	pxx = 2 * dx - dy;
	while (pi.y <= pf.y)
	{
		ft_light_pixel(init, pi.x, pi.y);
		if (pxx > 0)
		{
			pi.x += xi;
			pxx = pxx - (2 * dy);
		}
		pxx = pxx + (2 * dx);
		pi.y++;
	}
}

void	slop_low(t_point pi, t_point pf, t_init *init)
{
	int dx;
	int dy;
	int yi;
	int pxx;

	dy = abs(pf.y - pi.y);
	dx = pf.x - pi.x;
	yi = (pf.y - pi.y >= 0) ? 1 : -1;
	pxx = 2 * dy - dx;
	while (pi.x <= pf.x)
	{
		ft_light_pixel(init, pi.x, pi.y);
		if (pxx >= 0)
		{
			pi.y += yi;
			pxx = pxx - (2 * dx);
		}
		pxx = pxx + (2 * dy);
		pi.x++;
	}
}

void	line_draw(t_point pi, t_point pf, t_init *init)
{
	if (abs(pf.y - pi.y) < abs(pf.x - pi.x))
	{
		if (pi.x > pf.x)
			slop_low(pf, pi, init);
		else
			slop_low(pi, pf, init);
	}
	else
	{
		if (pi.y > pf.y)
			slop_high(pf, pi, init);
		else
			slop_high(pi, pf, init);
	}
}
