/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:57:35 by mray              #+#    #+#             */
/*   Updated: 2018/02/26 13:57:35 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int  x = 0;
int  y = 0;
void store_pix(t_canvas *canvas, int x, int y, unsigned int c)
{
	int i;

	i = (x * 4) + (y * canvas->size_line);
	*(canvas->pix_data + i) = c;
	*(canvas->pix_data + i + 1) = c >> 8;
	*(canvas->pix_data + i + 2) = c >> 16;
}

int key_handler(int key, void *parameters)
{
	t_params *para;
	t_gl *	gl;
	t_canvas *canvas;
	t_inputs *inputs;

	para = (t_params *)parameters;
	gl = (t_gl *)para->p1;
	inputs = (t_inputs *)para->p3;
	canvas = (t_canvas *)para->p2;
	if (key == 257)
		inputs->shift_key = 1;
	else
		inputs->shift_key = 0;
	if(key == 126)
		gl->live_trans[2] -= (0.05 / gl->live_trans[0]);
	if(key == 125)
		gl->live_trans[2] += (0.05 / gl->live_trans[0]);
	if(key == 123)
		gl->live_trans[1] -= (0.05 / gl->live_trans[0]);
	if(key == 124)
		gl->live_trans[1] += (0.05 / gl->live_trans[0]);
	draw_frac(gl, canvas);
	ft_putnbr(key);
	return (0);
}

int mouse_handler(int m_key, int x, int y, void *parameters)
{
	t_params *para;
	t_gl *	gl;
	t_canvas *canvas;
	t_inputs *inputs;
	para = (t_params *)parameters;
	gl = (t_gl *)para->p1;
	canvas = (t_canvas *)para->p2;
	inputs = (t_inputs *)para->p3;
	if (m_key == 4)
	{
		gl->live_trans[1] += ((x - (WIDTH / 2)) / (WIDTH * gl->live_trans[0]));
		gl->live_trans[2] += ((y - (HEIGHT / 2)) / (HEIGHT * gl->live_trans[0]));
		gl->live_trans[0] *= 0.5;
	}
	if (m_key == 5)
	{
		gl->live_trans[2] += ((y - (HEIGHT / 2)) / (HEIGHT * gl->live_trans[0]));
		gl->live_trans[1] += ((x - (WIDTH / 2)) / (WIDTH * gl->live_trans[0]));
		gl->live_trans[0] /= 0.5;
	}
	draw_frac(gl, canvas);
	ft_putnbr(m_key);
	ft_putchar('\n');
	ft_putnbr(x);
	ft_putstr(", ");
	ft_putnbr(y);
	ft_putchar('\n');
	ft_putnbr(gl->live_trans[1]);
	return (0);
}

int hover_handler(int x, int y, void *parameters)
{
	t_params *para;
	t_gl *	gl;
	t_canvas *canvas;
	t_inputs *inputs;
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

int main(int argc, char **argv)
{
	t_gl *	gl;
	void *	mlx;
	void *	window;
	t_canvas *canvas;
	t_params *para;
	t_inputs *inputs;
	if (argc == 2)
	{
		para = (t_params *)malloc(sizeof(t_params));
		inputs = (t_inputs *)malloc(sizeof(t_inputs));
		mlx = mlx_init();
		window = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract'ol Visualizer");
		gl = create_gl(mlx, window);
		canvas = create_canvas(gl);
		init_frac(argv[1], canvas);
		para->p1 = gl;
		para->p2 = canvas;
		para->p3 = inputs;
		mlx_hook(gl->surf, 2, 0, key_handler, para);
		mlx_hook(gl->surf, 4, 0, mouse_handler, para);
		mlx_hook(gl->surf, 6, 0, hover_handler, para);
		draw_frac(gl, canvas);
		mlx_loop(gl->lib);
	}
}
