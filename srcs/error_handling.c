/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mray <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:49:02 by mray              #+#    #+#             */
/*   Updated: 2018/03/14 18:49:02 by mray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	errorify(void)
{
	ft_putstr("Usage: ./fractol [name of fractol]\nFractol");
	ft_putstr("Names:\njulia\nmandel\nburningship\ntricorn\n");
	exit(1);
}
