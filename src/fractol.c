/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:11:16 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/03/30 02:13:53 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/fractol.h"

void my_pixel_put(int x, int y, t_img *img, int color)
{
	int level;

	level = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + level) = color;
}

void mandel_and_julia(t_complex *z, t_complex *c, t_plano *f)
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

void handle_pixel(int x, int y, t_plano *f)
{
	t_complex	z;
	t_complex	c;
	int 		i;
	int			color;

//ITERACION CON FORMULA
	i = 0;
//PIXEL DE COORDINACION
	z.x = (map(x, -2, +2, 0, WIDTH) * f->zoom) + f->shift_x; //unsacled: new_min: old_min: old_max:
	z.y = (map(y, +2, -2, 0, HEIGHT) * f->zoom) + f->shift_y; //unsacled: new_min: old_min: old_max:

	mandel_and_julia(&z, &c, f);

//how many interate time z^2 + c
//to check if the point scaped?
	while (i < f->interations_definition)
	{	
		//actual z^2 + c
		//z = z^2 + c
		z = sum_complex(square_complex(z), c);

		//is the value scaped?
		if ((z.x * z.x) + (z.y * z.y) > f->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, f->interations_definition); //unscaled_num: new_min: new_max: old_min: old_max: 
			my_pixel_put(x, y, &f->img, color); //img: ; 0x03B674H
			return ;
		}
		++i;
	}
	//madebrot interaciones
	my_pixel_put(x, y, &f->img, BLACK); //img: color:
}

void start_render(t_plano *f)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while(++x < WIDTH)
		{
			handle_pixel(x, y, f);
		}
	}
	mlx_put_image_to_window(f->mlx,
							f->mlx_win,
							f->img.img_ptr,
							0, 0);
}
