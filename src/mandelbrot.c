/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:55:44 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/21 16:09:28 by cbridget         ###   ########.fr       */
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
//	img = 0;
	create_color(img);
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
	max_iter = 1000;
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

unsigned int	create_color(t_data *img)
{
	int	i = 0;
	int	j = 0;
	int	tmp;
	int numitpp[1000] = {0};
	double hue[width][hight] = {0};

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
	i = 0;
	long total = 0;
	while (i < 1000)
	{
		total += numitpp[i];
		i++;
	}
	i = j = 0;
//	printf("%d\n", numitpp[1]);
	while (i < hight)
	{
		j = 0;
		while (j < width)
		{
			tmp = 0;
			while (tmp <= itcount[j][i])
			{
				hue[j][i] += (double)numitpp[tmp] / (double)total;
				if (hue[j][i] > 1)
					printf("%f ", hue[j][i]);
				tmp++;
			}
			j++;
		}
		i++;
	}

	int palette[5];
	palette[0] = 0xffffff;
	palette[1] = 0xff9f9f;
	palette[2] = 0xce4646;
	palette[3] = 0x840c0c;
	palette[4] = 0x0;
	i = 0;
	while (i < hight)
	{
		j = 0;
		while (j < width)
		{
//			if (hue[j][i] > 1)
//				printf("%d ", (int)hue[j][i]);
			my_mlx_pixel_put(img, j, i, palette[(int)hue[j][i]]);
			j++;
		}
//		printf("\n");
		i++;
	}
	return (0xff);
}
