/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:21:55 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/03/21 21:50:57 by eerazo-c         ###   ########.fr       */
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
	mlx_destroy_display(f->mlx);
	free(f->mlx_conection);
	exit(EXIT_SUCCESS);
}

int key_handler(int key, t_plano *f)
{
	if (key == XK_Escape)
		close_handler(f);
	if (key == XK_Left)
		f->shift_x += (0.5 * f->zoom);
	else if (key == XK_Right)
		f->shift_x -= (0.5 * f->zoom);
	else if (key == XK_UP)
		f->shift_y -= (0.5 * f->zoom);
	else if (key == XK_Down)
		f->shift_y += (0.5 * f->zoom);
	else if (key == XK_plus)
		f->iteration_definition += 10;
	else if (key == XK_minus)
		f->iteration_definition -= 10;

	start_render(f);
	return (0);
}

int mouse_handler(int button, int x, int y, t_plano *f)
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
