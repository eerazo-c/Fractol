/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:21:55 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/03/30 00:11:56 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/fractol.h"

int close_key(t_plano *f)
{
	mlx_destroy_image(f->mlx,
			f->img.img_ptr);
	mlx_destroy_window(f->mlx,
			f->mlx_win);
	//revisar en fractal initatt lo de destroy imagen debe
	//distroy display pero no esta en la minilib
	mlx_destroy_image(f->mlx, f->img.img_ptr);
	free(f->mlx);
	exit(EXIT_SUCCESS);
}

int key_read(int keysym, t_plano *f)
{
	if (keysym == ESC)
		close_key(f);
	if (keysym == K_Left)
		f->shift_x += (0.5 * f->zoom);
	else if (keysym == K_Right)
		f->shift_x -= (0.5 * f->zoom);
	else if (keysym == K_UP)
		f->shift_y -= (0.5 * f->zoom);
	else if (keysym == K_Down)
		f->shift_y += (0.5 * f->zoom);
	else if (keysym == K_plus)
		f->interations_definition += 10;
	else if (keysym == K_minus)
		f->interations_definition -= 10;

	start_render(f);
	return (0);
}

int mouse_handler(int button, t_plano *f)
{
	//zoom in
	if (button == Button5)
	{
		f->zoom *=0.95;
	}
	else if (button == Button4)
	{
		f->zoom *= 1.05;
	}

	start_render(f);
	return (0);
}

int julia(int x, int y, t_plano *f)
{
	if (!ft_strncmp(f->name, "julia", 5))
	{
		f->julia_x = (map(x, -2, +2, 0, WIDTH) * f->zoom) + f->shift_x;
		f->julia_y = (map(y, +2, -2, 0, HEIGHT) * f->zoom) + f->shift_y;
	}
	return (0);
}
