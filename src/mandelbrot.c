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

void	ft_mandelbrot(t_data *img)
{
	unsigned int color;
	unsigned int x;
	unsigned int y;
	double k;
	unsigned char rgb[4];
	x = 0;
//	img = 0;
	while (x < width)
	{
		y = 0;
		while (y < hight)
		{
			color = ft_mandelbrot_color((-2) + ((double)x / (double)width) * (2 - (-2)), (-2) + ((double)y / (double)hight) * (2 - (-2)));
//			my_mlx_pixel_put(img, x, y, color);
			if (color == 50)
				my_mlx_pixel_put(img, x, y, 0x0);
			else
			{
				/*k = 1 - (double)color / 50;
				rgb[0] = (unsigned char)((1 - k) * 87 + k * 179);
				rgb[1] = (unsigned char)((1 - k) * 202 + k * 107);
				rgb[2] = (unsigned char)((1 - k) * 255 + k * 0);
				rgb[3] = (unsigned char)0x0;*/
				k = (double)color / (double)50;
				rgb[0] = (unsigned char)0x0;
				rgb[1] = (unsigned char)(18 * (1 - k) * pow(k, 3) * 255);
				rgb[2] = (unsigned char)(144 * pow((1 - k), 2) * pow(k, 2) * 255);
				rgb[3] = (unsigned char)(1 * pow((1 - k), 3) * k * 255);
				my_mlx_pixel_put(img, x , y, *(int*)rgb);
			}
			y++;
		}
		x++;
	}
//	create_color(img);
}

unsigned int	ft_mandelbrot_color(double x, double y)
{
	double	x0;
	double	y0;
	double	tmpx;
	int		i;
	int		max_iter;
//	double	cl;
//	unsigned char rgb[4];

	x0 = x;
	y0 = y;
	max_iter = 50;
	i = 0;
	while (x * x + y * y <= 4 && i < max_iter)
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
		int palette[50];
		int j = 0;
		int pl = 50;
		while (j < 50)
		{
			palette[j] = pl;
			if (pl > 250)
				pl = 100;
			pl += 4;
			j++;
		}
		double log_zn = log(x * x + y * y) / 2;
		double nu = log(log_zn / M_LN2) / M_LN2;
		double iter = i - nu + 1;
//		if (iter > 30)
//			printf("%f ", floor(iter));
		rgb[0] = (unsigned char)0x0;
		rgb[1] = (unsigned char)palette[(int)floor(iter) - 5];
		rgb[2] = (unsigned char)iter % 1;
		rgb[3] = (unsigned char)palette[(int)floor(iter)];
		return (*(int *)rgb);
	}*/
}
