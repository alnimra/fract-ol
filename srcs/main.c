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

void	store_pix(t_canvas *canvas, int x, int y, unsigned int c)
{
	int i;

	i = (x * 4) + (y * canvas->size_line);
	*(canvas->pix_data + i) = c;
	*(canvas->pix_data + i + 1) = c >> 8;
	*(canvas->pix_data + i + 2) = c >> 16;
}

int		main(int argc, char **argv)
{
	t_gl		*gl;
	void		*mlx;
	void		*window;
	t_canvas	*canvas;
	t_params	*para;

	if (argc == 2)
	{
		para = (t_params *)malloc(sizeof(t_params));
		mlx = mlx_init();
		window = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract'ol Visualizer");
		gl = create_gl(mlx, window);
		canvas = create_canvas(gl);
		init_frac(argv[1], canvas);
		para->p1 = gl;
		para->p2 = canvas;
		para->p3 = (t_inputs *)malloc(sizeof(t_inputs));
		mlx_hook(gl->surf, 2, 0, key_handler, para);
		mlx_hook(gl->surf, 4, 0, mouse_handler, para);
		mlx_hook(gl->surf, 6, 0, hover_handler, para);
		draw_frac(gl, canvas);
		mlx_loop(gl->lib);
	}
	errorify();
	return (0);
}
