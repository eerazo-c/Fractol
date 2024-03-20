/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:11:16 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/03/16 04:06:44 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/fractol.h"

void my_pixel_p(int x, int y, t_img *img, int color)
{
	int level;

	level = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + level) = color;
}

void handle_pixel(int x, int y, t_plano *f)
{
	t_complex	z;
	t_complex	c;
	int 		i;
	int			color;

//ITERACION CON FORMULA
	i = 0;
	z.x = 0.0;
	z.y = 0.0;
//PIXEL DE COORDINACION
	c.x = map(x, -2, +2, 0, WIDTH); //unsacled: new_min: old_min: old_max:
	c.y = map(y, -2, -2, 0, HEIGHT); //unsacled: new_min: old_min: old_max:

//how many interate time z^2 + c
//to check if the point scaped?
	while (i < f->interations_definition)
	{	
		//actual z^2 + c
		//z = z^2 + c
		z = sum_complex(square_complex(z), c);

		//is the value scaped?
		if ((z.x * z.x) + (z.y * z.y) >  f->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, f->escape_value); //unscaled_num: new_min: new_max: old_min: old_max: 
			my_pixel_p(x, y, &f->img, color); //img:
			return ;
		}
		++i;
	}
	//madebrot interaciones
	my_pixel_p(x, y, &f->img, WHITE); //img: color:
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
