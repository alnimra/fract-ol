/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:59:40 by mray              #+#    #+#             */
/*   Updated: 2018/03/17 13:59:40 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handler(int m_key, int x, int y, void *parameters)
{
	t_params	*para;
	t_gl		*gl;
	t_canvas	*canvas;
	t_inputs	*inputs;

	para = (t_params *)parameters;
	gl = (t_gl *)para->p1;
	canvas = (t_canvas *)para->p2;
	inputs = (t_inputs *)para->p3;
	if (m_key == 4)
	{
		gl->live_trans[1] += ((x - (WIDTH / 2)) / (WIDTH * gl->live_trans[0]));
		gl->live_trans[2] +=
			((y - (HEIGHT / 2)) / (HEIGHT * gl->live_trans[0]));
		gl->live_trans[0] *= 0.5;
	}
	if (m_key == 5)
	{
		gl->live_trans[2] +=
			((y - (HEIGHT / 2)) / (HEIGHT * gl->live_trans[0]));
		gl->live_trans[1] += ((x - (WIDTH / 2)) / (WIDTH * gl->live_trans[0]));
		gl->live_trans[0] /= 0.5;
	}
	draw_frac(gl, canvas);
	return (0);
}

int	hover_handler(int x, int y, void *parameters)
{
	t_params	*para;
	t_gl		*gl;
	t_canvas	*canvas;
	t_inputs	*inputs;

	para = (t_params *)parameters;
	gl = (t_gl *)para->p1;
	canvas = (t_canvas *)para->p2;
	inputs = (t_inputs *)para->p3;
	if (inputs->shift_key == 1)
	{
		if (canvas->frac_type == 0)
		{
			gl->live_trans[3] = change_julia_para_x(x);
			gl->live_trans[4] = change_julia_para_y(y);
			draw_frac(gl, canvas);
		}
	}
	inputs->p_mouse_pos[0] = x;
	inputs->p_mouse_pos[1] = y;
	return (0);
}
