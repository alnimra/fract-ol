/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:41:19 by mray              #+#    #+#             */
/*   Updated: 2018/03/17 13:41:19 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship_eq_sub(double n[4])
{
	double i;

	i = n[0] * n[0] - n[1] * n[1] + n[2];
	n[1] = fabs(2 * n[0] * n[1] + n[3]);
	n[0] = fabs(i);
}

void	burning_ship_set_draw(t_gl *gl, t_canvas *canvas)
{
	double	n[4];
	int		ints[3];

	ints[0] = -1;
	while (++ints[0] < HEIGHT)
	{
		ints[1] = -1;
		while (++ints[1] < WIDTH)
		{
			n[2] = 1.5 * (ints[1] - WIDTH / 2) /
				(0.5 * gl->live_trans[0] * WIDTH) +
				gl->live_trans[1];
			n[3] = (ints[0] - HEIGHT / 2) / (0.5 * gl->live_trans[0] * HEIGHT) +
				gl->live_trans[2];
			n[0] = n[2];
			n[1] = n[3];
			ints[2] = -1;
			while (++ints[2] < gl->live_trans[5] &&
				n[0] * n[0] + n[1] * n[1] < 4)
				burning_ship_eq_sub(n);
			store_pix(canvas, ints[1], ints[0],
				get_color(gl, ints[2], gl->live_trans[5]));
		}
	}
}
