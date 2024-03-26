/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:21:55 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/03/26 21:17:23 by eerazo-c         ###   ########.fr       */
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

void fractol(t_all *f, int x, int y)
{
    double re;
    double im;
    double dif;

    mlx_clear_window(f->win.mlx, f->win.win);
    while (++y < H)
    {
        x = -1;
        dif = f->frac.min_im - f->frac.max_im;
        im = f->frac.max_im + ((double)y + f->mv.y) * dif / (H * f->mv.z);
        while (++x < W)
        {
            dif = f->frac.max_re - f->frac.min_re;
            re = f->frac.min_re + ((double)x + f->mv.x) * dif / (W * f->mv.z);
            put_color_px(type(f, re, im), f, x, y);
        }
    }
    mlx_put_image_to_window(f->win.mlx, f->win.win, f->win.img, 0, 0);
}

int mouse_handler(int button, t_all *f)
{
	//zoom in
	if (button == Button4)
		f->mv.z +=0.01;
	else if (button == Button5)
		f->mv.z -= 0.1;

	fractol(f, -1, -1);
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
