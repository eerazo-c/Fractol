/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:27:38 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/04/04 20:49:03 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/fractol.h"

int	check(int ac, char **av)
{
	if (ac == 1)
	{
		write(1, "The arguments are not correct\n", 30);
		return (0);
	}
	else if ((ft_strncmp(*av, "mandelbrot", 10) != '\0' && ft_strncmp(*av,
			"julia", 5) != '\0') || (!ft_strncmp(*av, "julia", 5) && ac < 4))
	{

		write(1, "Avalaible fractals:\n", 18);
		write(1, "- Mandelbrot\n", 13);
		write(1, "- Julia num1 num2\n", 18);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_plano	f;

	if (!check(ac, &av[1]))
		exit(1);
	f.name = av[1];
	fractal_initit(&f, av);
	start_render(&f);
	mlx_hook(f.mlx_win, 17, 0L, close_key, &f);
	mlx_loop_hook(f.mlx, start_render, &f);
	mlx_key_hook(f.mlx_win, key_read, &f);
	mlx_mouse_hook(f.mlx_win, mouse_handler, &f);
	mlx_loop(f.mlx);
	return (EXIT_SUCCESS);
}
