/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:06:55 by mray              #+#    #+#             */
/*   Updated: 2018/03/17 14:06:55 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keyify(int key, t_gl *gl, t_inputs *inputs)
{
	if (key == 257)
		inputs->shift_key = 1;
	else
		inputs->shift_key = 0;
	if (key == 126)
		gl->live_trans[2] -= (0.05 / gl->live_trans[0]);
	if (key == 125)
		gl->live_trans[2] += (0.05 / gl->live_trans[0]);
	if (key == 123)
		gl->live_trans[1] -= (0.05 / gl->live_trans[0]);
	if (key == 124)
		gl->live_trans[1] += (0.05 / gl->live_trans[0]);
	if (key == 6)
		gl->live_trans[5]++;
	if (key == 7)
		gl->live_trans[5]--;
	if (key == 12)
		gl->live_trans[6] = generate_random_hex();
	if (key == 53)
		exit(1);
}

int		key_handler(int key, void *parameters)
{
	t_params	*para;
	t_gl		*gl;
	t_canvas	*canvas;
	t_inputs	*inputs;

	para = (t_params *)parameters;
	gl = (t_gl *)para->p1;
	inputs = (t_inputs *)para->p3;
	canvas = (t_canvas *)para->p2;
	keyify(key, gl, inputs);
	draw_frac(gl, canvas);
	ft_putnbr(key);
	return (0);
}
