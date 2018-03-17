/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 11:08:36 by mray              #+#    #+#             */
/*   Updated: 2018/03/17 11:08:36 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		generate_random_hex(void)
{
	int x;

	x = rand() & 0xff;
	x |= (rand() & 0xff) << 8;
	x |= (rand() & 0xff) << 16;
	x |= (rand() & 0xff) << 24;
	return (x);
}

void	select_hue(int rgb[3], int i, int hue_amount, int color_skew)
{
	if (i < (hue_amount / 6))
		rgb[1] += color_skew / (hue_amount / 6);
	if (i >= (hue_amount / 6) && i < (2 * hue_amount / 6))
		rgb[0] -= color_skew / (hue_amount / 6);
	if (i >= (2 * hue_amount / 6) && i < (3 * hue_amount / 6))
		rgb[2] += color_skew / (hue_amount / 6);
	if (i >= (3 * hue_amount / 6) && i < (4 * hue_amount / 6))
		rgb[1] -= color_skew / (hue_amount / 6);
	if (i >= (4 * hue_amount / 6) && i < (5 * hue_amount / 6))
		rgb[0] += color_skew / (hue_amount / 6);
	if (i >= (5 * hue_amount / 6))
		rgb[2] -= color_skew / (hue_amount / 6);
}

int		get_color(t_gl *gl, int hue, int max)
{
	int rgb[3];
	int i;
	int hue_amount;
	int color_skew;

	hue_amount = 200;
	color_skew = gl->live_trans[6];
	if (hue >= max)
		return (0);
	hue %= hue_amount;
	i = -1;
	ft_bzero(rgb, 3 * (sizeof(int)));
	rgb[0] = (color_skew / (hue_amount / 6)) * (hue_amount / 6);
	while (++i < hue)
		select_hue(rgb, i, hue_amount, color_skew);
	return (((rgb[0] & color_skew) << 16) | ((rgb[1] & color_skew) << 8) |
			(rgb[2] & color_skew));
}
