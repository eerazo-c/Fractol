/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_initit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:18:50 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/03/30 00:11:37 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/fractol.h"

static	void malloc_error(void)
{
	perror("problems with malloc");
	exit(EXIT_FAILURE);
}

void data_initit(t_plano *f)
{
	f->escape_value = 4;
	f->interations_definition = 42;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	//zoom factor
	f->zoom = 1.0;
}
void fractal_initit(t_plano *f)
{
	f->mlx = mlx_init();	
	if (f->mlx == NULL)
		malloc_error();
		f->mlx_win = mlx_new_window(f->mlx,
			  						WIDTH, //sixe_x:
			   						HEIGHT, //size_y:
									f->name);
	if (f->mlx_win == NULL)
	{
		mlx_destroy_image(f->mlx, f->img.img_ptr);
		free(f->mlx);
		malloc_error();
	}
	f->img.img_ptr = mlx_new_image(f->mlx,
		   						WIDTH, HEIGHT);
	
	if (f->img.img_ptr == NULL)
	{
		mlx_destroy_window(f->mlx, f->mlx_win); //mlx_ptr: win_ptr: 
		mlx_destroy_image(f->mlx, f->img.img_ptr); 
		free(f->mlx);
		malloc_error();
	}
	f->img.pixels_ptr = mlx_get_data_addr(f->img.img_ptr, //img_p:
									&f->img.bpp, //bits_per_pixel:
									&f->img.line_len, //size_line:
									&f->img.end); //end:

	//init fractal
	data_initit(f);
//	mouse(f);
}
