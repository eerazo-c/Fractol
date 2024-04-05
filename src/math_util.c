/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:02:24 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/04/05 20:53:36 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Inc/fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_min)
{
	double	result;

	result = ((new_max - new_min) * (unscaled_num - old_min) / \
			(0 - old_min) + new_min);
	return (result);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
