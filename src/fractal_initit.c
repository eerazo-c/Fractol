/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_initit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:18:50 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/04/03 16:46:00 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/fractol.h"

static	void	error(void)
{
	perror("problems");
	exit(EXIT_FAILURE);
}

void	data_initit(t_plano *f)
{
	f->escape_value = 4;
	f->interations_definition = 42;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->zoom = 1;
}

void	fractal_initit(t_plano *f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		error();
	f->mlx_win = mlx_new_window(f->mlx, WIDTH, HEIGHT,
			f->name);
	if (f->mlx_win == NULL)
	{
		mlx_destroy_image(f->mlx, f->img.img_ptr);
		free(f->mlx);
	}
	f->img.img_ptr = mlx_new_image(f->mlx,
			WIDTH, HEIGHT);
	if (f->img.img_ptr == NULL)
	{
		mlx_destroy_window(f->mlx, f->mlx_win);
		mlx_destroy_image(f->mlx, f->img.img_ptr);
		free(f->mlx);
	}
	f->img.pixels_ptr = mlx_get_data_addr(f->img.img_ptr,
			&f->img.bpp,
			&f->img.line_len,
			&f->img.end);
	data_initit(f);
}
