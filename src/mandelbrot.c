/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:55:44 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/23 13:37:54y cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_envf *env_f)
{
	unsigned int color;
	unsigned int x;
	unsigned int y;
//	double k;
//	unsigned char rgb[4];
	x = 0;
//	img = 0;
	while (x < width)
	{
		y = 0;
		while (y < hight)
		{
//			color = ft_mandelbrot_color((-2) + ((double)x / (double)width) * (2 - (-2)), (-2) + ((double)y / (double)hight) * (2 - (-2)));
			color = ft_mandelbrot_color(env_f, ((double)x - (double)width / 2) / env_f->coords.scale + env_f->coords.c_x, ((double)y - (double)width / 2) / env_f->coords.scale + env_f->coords.c_y);
			my_mlx_pixel_put(&env_f->img, x, y, color);
/*			if (color == env_f->coords.max_it)
				my_mlx_pixel_put(&env_f->img, x, y, 0x0);
			else
			{
				k = (double)color / (double)env_f->coords.max_it;//50 is wrong but cool;
				rgb[0] = (unsigned char)0x0;
				rgb[1] = (unsigned char)(18 * (1 - k) * pow(k, 3) * 255);
				rgb[2] = (unsigned char)(144 * pow((1 - k), 2) * pow(k, 2) * 255);
				rgb[3] = (unsigned char)(1 * pow((1 - k), 3) * k * 255);
				my_mlx_pixel_put(&env_f->img, x , y, *(int*)rgb);
			}*/
			y++;
		}
		x++;
	}
//	create_color(img);
}

unsigned int	ft_mandelbrot_color(t_envf *env_f, double x, double y)
{
	double	x0;
	double	y0;
	double	tmpx;
	unsigned int		i;
	double	cl;
	unsigned char rgb[4];

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
//	return (i);
	if (i == env_f->coords.max_it)
		return (0x0);
	else
	{
		cl = i + 2 - log(log(x * x + y * y)) / M_LN2;
		if (cl < 0)
			cl = 0;
		cl = 8 * sqrt(cl);
		rgb[0] = (unsigned char)0x0;
		rgb[1] = (unsigned char)(floor(cl * 5)) % 255;
		rgb[2] = (unsigned char)(floor(cl * 2)) % 255;
		rgb[3] = (unsigned char)(floor(cl * 3)) % 255;
//		rgb[3] = (unsigned char)0x0;
		return (*(int *)rgb);
	}
}
