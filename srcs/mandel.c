/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:44:34 by mray              #+#    #+#             */
/*   Updated: 2018/03/14 18:44:34 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandel_set_draw(t_gl *gl, t_canvas *canvas)
{
	double n[4];
	int	ints[3];
	double i;
	i = 0;
	ints[0] = -1;
	while (++ints[0] < HEIGHT)
	{
		ints[1] = -1;
		while (++ints[1] < WIDTH)
		{
		n[0] = 0;
		n[1] = 0;
			n[2] = 1.5 * (ints[1] - WIDTH / 2) /
					   (0.5 * gl->live_trans[0] * WIDTH) +
				   gl->live_trans[1];
			n[3] = (ints[0] - HEIGHT / 2) / (0.5 * gl->live_trans[0] * HEIGHT) +
				   gl->live_trans[2];
			ints[2] = -1;
			while (++ints[2] < gl->live_trans[5] && n[0] * n[0] + n[1] * n[1] <= 4)
			{
				i = n[0] * n[0] - n[1] * n[1];
				n[1] = (n[0] + n[0]) * n[1] + n[2];
				n[0] = i + n[3];
			}
			store_pix(canvas, ints[1], ints[0], get_color(gl, ints[2], gl->live_trans[5]));
		}
	}
}
