/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:41:17 by eerazo-c          #+#    #+#             */
/*   Updated: 2024/04/05 20:52:35 by eerazo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

//# <biblioteca.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../Inc/printf/ft_printf.h"
# include "../Inc/libft/libft.h"
# include <mlx.h>

# define WIDTH	800
# define HEIGHT	800

//colors
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
# define LIME_SHOCK      0xCCFF00  // A blinding lime
# define NEON_ORANGE     0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
# define AQUA_DREAM      0x33CCCC  // A bright turquoise
# define HOT_PINK        0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE   0x0066FF  // A radiant blue
# define LAVA_RED        0xFF3300  // A bright, molten red//

# define ESC 53
# define CTR 256
# define S_DOWN 5
# define S_UP 4
# define K_LEFT 123
# define K_RIGHT 124
# define K_UP 126
# define K_DOWN 125
# define ZOOM_IN 78
# define ZOOM_OUT 69
# define BUTTON5 5
# define BUTTON4 4

//struct
typedef struct s_complex
{
	double	x;

	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		end;
	int		line_len;
}				t_img;

typedef struct s_plano
{
	char	*name;
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	double	escape_value;
	int		interations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;

}				t_plano;

//PROTOTIPO_FUNCIONES
int			check(int ac, char **av);
void		fractal_initit(t_plano *f, char **av);
void		data_initit(t_plano *f, char **av);
void		my_pixel_put(int x, int y, t_img *img, int color);
void		mandel_and_julia(t_complex *z, t_complex *c, t_plano *f);
int			start_render(t_plano *f);
void		handle_pixel(int x, int y, t_plano *f);
double		map(double unscaled_num, double new_min, double new_max, \
		double old_min);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			close_key(t_plano *f);
int			key_read(int keysym, t_plano *f);
int			julia(int x, int y, t_plano *f);
int			mouse_handler(int button, int x, int y, t_plano *f);
void		error(void);

#endif
