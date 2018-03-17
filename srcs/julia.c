/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:21:59 by mray              #+#    #+#             */
/*   Updated: 2018/03/14 18:21:59 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double change_julia_para_x(int x)
{
	if (x > 0 && x < WIDTH)
		return (x * (2.1 / WIDTH));
	else if (x <= 0)
		return (0);
	return (WIDTH);
}

double change_julia_para_y(int y)
{
	if (y > 0 && y < HEIGHT)
		return (y * (2.1 / HEIGHT));
	else if (y <= 0)
		return (0);
	return (HEIGHT);
}

void julia_set_draw(t_gl *gl, t_canvas *canvas)
{
	double n[2];
	int	ints[3];
	double i;
	i = 0;
	ints[0] = -1;
	while (++ints[0] < HEIGHT)
	{
		ints[1] = -1;
		while (++ints[1] < WIDTH)
		{
			// n[0] = (ints[1] / (WIDTH / 3.5 / 2));
			// n[1] = (ints[0] / (HEIGHT / 4));
			n[0] = 1.5 * (ints[1] - WIDTH / 2) /
					   (0.5 * gl->live_trans[0] * WIDTH) +
				   gl->live_trans[1];
			n[1] = (ints[0] - HEIGHT / 2) / (0.5 * gl->live_trans[0] * HEIGHT) +
				   gl->live_trans[2];
			ints[2] = -1;
			while (++ints[2] < gl->live_trans[5] && n[0] * n[0] + n[1] * n[1] < 2)
			{
				i = n[0] * n[0] - n[1] * n[1];
				n[1] = (n[0] + n[0]) * n[1] + gl->live_trans[3];
				n[0] = i + -0.7 + gl->live_trans[4];
			}
			// ft_putnbr(ints[2]);
			store_pix(canvas, ints[1], ints[0], get_color(gl, ints[2], gl->live_trans[5]));
		}
	}
}
