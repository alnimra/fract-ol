/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_frac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:23:53 by mray              #+#    #+#             */
/*   Updated: 2018/03/14 18:23:53 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_frac(char *fractol_type, t_canvas *canvas)
{
	if (ft_strcmp(fractol_type, "julia") == 0)
		canvas->frac_type = 0;
	else if (ft_strcmp(fractol_type, "mandel") == 0)
		canvas->frac_type = 1;
	else if (ft_strcmp(fractol_type, "tricorn") == 0)
		canvas->frac_type = 2;
	else if (ft_strcmp(fractol_type, "burningship") == 0)
		canvas->frac_type = 3;
	else
		errorify();
}

void draw_frac(t_gl *gl, t_canvas *canvas)
{
	if (canvas->frac_type == 0)
		julia_set_draw(gl, canvas);
	else if (canvas->frac_type == 1)
		mandel_set_draw(gl, canvas);
	else if (canvas->frac_type == 2)
		tricorn_set_draw(gl, canvas);
	else if (canvas->frac_type == 3)
		burning_ship_set_draw(gl, canvas);
	mlx_put_image_to_window(gl->lib, gl->surf, canvas->img, 0, 0);
}
