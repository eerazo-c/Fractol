/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:21:55 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/04/05 19:36:29 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/fractol.h"

void	error(void)
{
	perror("problems");
	exit(EXIT_FAILURE);
}

int	close_key(t_plano *f)
{
	mlx_destroy_image(f->mlx, f->img.img_ptr);
	mlx_destroy_window(f->mlx, f->mlx_win);
	exit(EXIT_SUCCESS);
}

int	key_read(int keysym, t_plano *f)
{
	if (keysym == ESC)
		close_key(f);
	if (keysym == K_LEFT)
		f->shift_x += (0.5 * f->zoom);
	else if (keysym == K_RIGHT)
		f->shift_x -= (0.5 * f->zoom);
	else if (keysym == K_UP)
		f->shift_y -= (0.5 * f->zoom);
	else if (keysym == K_DOWN)
		f->shift_y += (0.5 * f->zoom);
	else if (keysym == ZOOM_OUT)
		f->interations_definition += 10;
	else if (keysym == ZOOM_IN)
		f->interations_definition -= 10;
	start_render(f);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_plano *f)
{
	(void)x;
	(void)y;
	if (button == BUTTON5)
		f->zoom *= 0.95;
	else if (button == BUTTON4)
		f->zoom *= 1.05;
	mlx_clear_window(f->mlx, f->mlx_win);
	start_render(f);
	return (0);
}

int	julia(int x, int y, t_plano *f)
{
	if (!ft_strncmp(f->name, "julia", 5))
	{
		f->julia_x = (map(x, -2, +2, WIDTH) * f->zoom) + f->shift_x;
		f->julia_y = (map(y, +2, -2, HEIGHT) * f->zoom) + f->shift_y;
		start_render(f);
	}
	return (0);
}
