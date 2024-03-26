/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:27:38 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/03/26 21:26:51 by eerazo-c         ###   ########.fr       */
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
	else if (ft_strncmp(*av, "mandelbrot", 10) != '\0' && ft_strncmp(*av,
			"julia", 5) != '\0')
	{
		write(1, "Avaliable fractals:\n", 18);
		write(1, "- Mandelbrot\n", 13);
		write(1, "- Julia\n", 8);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_all	f;

	if (!check(ac, &av[1]))
		exit(1);

//	f.name = av[1];
//	fractal_initit(&f);
	new_win(&f, av[1]);
	start_all(&f, av[1]);
	start_render(&f.frac);


	mlx_loop(f.win.win, 2, 0, read_key, &f);
	mlx_loop(f.win.win, 4, 0, read_mouse, &f);

	fractol(&f, -1, -1);

	mlx_loop(&f, -1, -1);
	return (EXIT_SUCCESS);
}
