/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:55:44 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/30 16:47:58 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractals(t_envf *env_f)
{
	unsigned int color;
	unsigned int x;
	unsigned int y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HIGHT)
		{
			if (env_f->flags.frc == 0)
				color = ft_mandelbrot(env_f, coord_trn(x, env_f, 0), coord_trn(y, env_f, 1));
			else if (env_f->flags.frc == 1)
				color = ft_julia(env_f, coord_trn(x, env_f, 0), coord_trn(y, env_f, 1));
			else
				color = ft_burning_ship(env_f, coord_trn(x, env_f, 0), coord_trn(y, env_f, 1));
			my_mlx_pixel_put(&env_f->img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env_f->mlx, env_f->win, env_f->img.img, 0, 0);
}

unsigned int	ft_mandelbrot(t_envf *env_f, double x, double y)
{
	double			x0;
	double			y0;
	double			tmpx;
	unsigned int	i;

	x0 = x;
	y0 = y;
	i = 0;
	while (x * x + y * y <= 4 && i < env_f->coords.max_it)
	{
		tmpx = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = tmpx;
		i++;
	}
	if (!env_f->flags.drw)
		return (drawing_one(i, env_f, x, y));
	else if (env_f->flags.drw == 1)
		return (drawing_two(i, env_f));
	else
		return (drawing_three(i, env_f));
}

unsigned int	ft_julia(t_envf *env_f, double x, double y)
{
	double			tmpx;
	unsigned int	i;

	i = 0;
	while (x * x + y * y <= 4 && i < env_f->coords.max_it)
	{
		tmpx = x * x - y * y + env_f->coords.j_x;
		y = 2 * x * y + env_f->coords.j_y;
		x = tmpx;
		i++;
	}
	if (!env_f->flags.drw)
		return (drawing_one(i, env_f, x, y));
	else if (env_f->flags.drw == 1)
		return (drawing_two(i, env_f));
	else
		return (drawing_three(i, env_f));
}

unsigned int	ft_burning_ship(t_envf *env_f, double x, double y)
{
	unsigned int	i;
	double	zx;
	double	zy;
	double	tmp;

	i = 0;
	zx = x;
	zy = y;
	while (zx * zx + zy * zy <= 4 && i < env_f->coords.max_it)
	{
		tmp = zx * zx - zy * zy + x;
		zy = fabs(2 * zx * zy) + y;
		zx = tmp;
		i++;
	}
	if (env_f->flags.drw == 1)
		return (drawing_two(i, env_f));
	else
		return (drawing_three(i, env_f));
}
