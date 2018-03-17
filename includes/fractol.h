/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:03:03 by mray              #+#    #+#             */
/*   Updated: 2018/02/26 14:03:03 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <time.h>
# define WIDTH  400
# define HEIGHT 400

typedef struct		s_gl
{
	void	*lib;
	void	*surf;
	double	live_trans[7];
}					t_gl;
t_gl				*create_gl(void *lib, void *surf);
typedef struct		s_canvas
{
	void	*img;
	char	*pix_data;
	int		size_line;
	int		byte_size;
	int		endian;
	int		frac_type;
}					t_canvas;
t_canvas			*create_canvas(t_gl *gl);
typedef struct		s_params
{
	void *p1;
	void *p2;
	void *p3;
}					t_params;
typedef struct		s_inputs
{
	int	p_mouse_pos[2];
	int shift_key;
}					t_inputs;
double				change_julia_para_x(int x);
double				change_julia_para_y(int y);
void				julia_set_draw(t_gl *gl, t_canvas *canvas);
void				mandel_set_draw(t_gl *gl, t_canvas *canvas);
void				tricorn_set_draw(t_gl *gl, t_canvas *canvas);
void				burning_ship_set_draw(t_gl *gl, t_canvas *canvas);
void				init_frac(char *fractol_type, t_canvas *canvas);
void				draw_frac(t_gl *gl, t_canvas *canvas);
void				store_pix(t_canvas *canvas, int x, int y, unsigned int c);
int					mouse_handler(int m_key, int x, int y, void *parameters);
int					hover_handler(int x, int y, void *parameters);
int					key_handler(int key, void *parameters);
void				errorify(void);
int					get_color(t_gl *gl, int hue, int max);
int					generate_random_hex(void);
#endif
