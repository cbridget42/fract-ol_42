/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:55:44 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/10 20:08:12 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int itcount[width][hight];

void	ft_mandelbrot(t_data *img)
{
/*	double	re_start = -2;
	double	re_end = 1;
	double	im_start = -1;
	double	im_end = 1;*/
	unsigned int color;
	unsigned int i;
	unsigned int j;
//	int itcount[width][hight];
	i = 0;
	while (i < hight)
	{
		j = 0;
		while (j < width)
		{
			color = ft_mandelbrot_color((-2) + ((double)j / (double)width) * (2 - (-2)), (-2) + ((double)i / (double)hight) * (2 - (-2)));
			itcount[j][i] = color;
//			my_mlx_pixel_put(img, j, i, color);
			j++;
		}
		i++;
	}
	img = 0;
	create_color();
}

unsigned int	ft_mandelbrot_color(double x, double y)
{
	double	x0;
	double	y0;
	double	tmpx;
	int		i;
	int		max_iter;

	x0 = 0.5;
	y0 = 0.5;
	max_iter = 250;
	i = 0;
	while (x * x + y * y < 4 && i < max_iter)
	{
		tmpx = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = tmpx;
		i++;
	}
	return (i);
/*	if (i == max_iter)
		return (0x0);
	else
		return (create_color(i));*/
}

unsigned int	create_color()
{
	int	i = 0;
	int	j = 0;
	int	tmp;
	int numitpp[width * hight];
	double hue[width][hight] = {};

	while (i < hight)
	{
		j = 0;
		while (j < width)
		{
			tmp = itcount[j][i];
			numitpp[tmp]++;
			j++;
		}
		i++;
	}
	i = 0;;
	int total = 0;
	while (i < width * hight)
	{
		total += numitpp[i];
		i++;
	}
	i = j = 0;
	while (i < hight)
	{
		j = 0;
		while (j < width)
		{
			tmp = 0;
			while (tmp < itcount[j][i])
			{
				hue[j][i] += numitpp[tmp] / total;
				tmp++;
			}
			j++;
		}
		i++;
	}
	i = j = 0;
	while (i < hight)
	{
		j = 0;
		while (j < width)
		{
			printf("%f ", hue[j][i]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0xff);
}
