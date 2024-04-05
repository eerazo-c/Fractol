/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_initit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:18:50 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/04/05 20:15:47 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/fractol.h"

static	int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' \
			|| c == '\f' || c == '\r' || c == ' ');
}

double	parse_integer(const char *str, int *i, int *sign)
{
	double	result;

	result = 0.0;
	while (ft_isspace(str[*i]) == 1)
		(*i)++;
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
	{
		*sign = 1;
		(*i)++;
	}
	else
		*sign = 1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10.0 + (str[(*i)++] - '0');
	}
	return (result);
}

double	ft_atod(const char *str)
{
	double	result;
	int		sign;
	int		i;
	double	fraction;

	result = 0.0;
	sign = 1;
	i = 0;
	result = parse_integer(str, &i, &sign);
	if (str[i] == '.')
	{
		fraction = 0.1;
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result + (str[i++] - '0') * fraction;
			fraction *= 0.1;
		}
	}
	return (sign * result);
}

void	data_initit(t_plano *f, char **av)
{
	f->escape_value = 4;
	f->interations_definition = 42;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	if (ft_strncmp(av[1], "julia", 5) == 0)
	{
		f->julia_x = (double)ft_atod(av[2]);
		f->julia_y = (double)ft_atod(av[3]);
	}
	f->zoom = 1;
}

void	fractal_initit(t_plano *f, char **av)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		error();
	f->mlx_win = mlx_new_window(f->mlx, WIDTH, HEIGHT,
			f->name);
	if (f->mlx_win == NULL)
	{
		mlx_destroy_image(f->mlx, f->img.img_ptr);
		free(f->mlx);
	}
	f->img.img_ptr = mlx_new_image(f->mlx,
			WIDTH, HEIGHT);
	if (f->img.img_ptr == NULL)
	{
		mlx_destroy_window(f->mlx, f->mlx_win);
		mlx_destroy_image(f->mlx, f->img.img_ptr);
		free(f->mlx);
	}
	f->img.pixels_ptr = mlx_get_data_addr(f->img.img_ptr,
			&f->img.bpp,
			&f->img.line_len,
			&f->img.end);
	data_initit(f, av);
}
