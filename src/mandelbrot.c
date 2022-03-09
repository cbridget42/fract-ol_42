/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:55:44 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/09 17:27:29 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_data *img)
{
/*	double	re_start = -2;
	double	re_end = 1;
	double	im_start = -1;
	double	im_end = 1;*/
	unsigned int color;
	unsigned int i;
	unsigned int j;
	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			color = ft_mandelbrot_color((-2) + ((double)j / (double)width) * (2 - (-2)), (-2) + ((double)i / (double)hight) * (2 - (-2)));
			my_mlx_pixel_put(img, j, i, color);
			j++;
		}
		i++;
	}
}

unsigned int	ft_mandelbrot_color(double x, double y)
{
	double	x0;
	double	y0;
	double	tmpx;
	int		i;
	int		max_iter;

	x0 = x;
	y0 = y;
	max_iter = 250;
	i = 0;
	while (x * x + y * y < 4 && i < max_iter)
	{
		tmpx = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = tmpx;
		i++;
	}
	if (i == max_iter)
		return (0x0);
	else
		return (create_color(i));
}

unsigned int	create_color(int i)
{
	return (i << 16);
}