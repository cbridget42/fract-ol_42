/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:41:25 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/25 17:16:25 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>

# include <stdio.h>//fix this!!!

# define hight 1000
# define width 1000

typedef struct s_flags {
	int	frc;
	int	crk;
} t_flags;

typedef struct s_coords {
	int x;
	int y;
	unsigned int max_it;
	unsigned int cof;
	double c_x;
	double c_y;
	unsigned long long scale;
} t_coords;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

typedef struct s_envf {
	void *mlx;
	void *win;
	t_coords coords;
	t_data img;
	t_flags flags;
} t_envf;


/*typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;*/

int			ft_close(t_envf *env_f);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_mandelbrot(t_envf *env_f);
unsigned int	ft_mandelbrot_color(t_envf *env_f, double x, double y);

#endif
