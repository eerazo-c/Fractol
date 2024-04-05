/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:11:16 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/04/05 19:36:15 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/fractol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	level;

	level = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + level) = color;
}

void	mandel_and_julia(t_complex *z, t_complex *c, t_plano *f)
{
	if (!ft_strncmp(f->name, "julia", 5))
	{
		c->x = f->julia_x;
		c->y = f->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_pixel(int x, int y, t_plano *f)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, +2, WIDTH) * f->zoom) + f->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * f->zoom) + f->shift_y;
	mandel_and_julia(&z, &c, f);
	while (i < f->interations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->escape_value)
		{
			color = map(i, WHITE, BLACK, f->interations_definition);
			my_pixel_put(x, y, &f->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &f->img, BLACK);
}

int	start_render(t_plano *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, f);
		}
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img.img_ptr, 0, 0);
	return (0);
}
