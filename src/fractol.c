/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:43:08 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/08 21:15:43 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>

#include <stdio.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void put_square(int size, t_data *img);
void put_circle(double y0, double x0, double r, t_data *img);
void put_triangles(int start_y, int start_x, int hight, t_data *img);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
//	my_mlx_pixel_put(&img, 500, 500, 0x00FF0000);
	put_square(200, &img);
	put_circle(200, 500, 100, &img);
	put_circle(600, 500, 200, &img);
	put_triangles(100, 700, 150, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return 0;
}

void put_triangles(int start_y, int start_x, int hight, t_data *img)
{
	int j;
	int i = 0;
	while (i < hight)
	{
		int r = 255;
		int g = 255;
		int b = 255;
		j = 0;
		while (j < hight * 2)
		{
			int tmp = (r<<16) | (g<<8) | b;
			if ((hight) - i <= j && j <= hight)
				my_mlx_pixel_put(img, start_x + j, start_y + i, tmp);
			if ((hight) + i >= j && j >= hight)
				my_mlx_pixel_put(img, start_x + j, start_y + i, tmp);
			if (j < 255)
			{
				r--;
				g--;
				b--;
			}
			else
			{
				r++;
				g++;
				b++;
			}
			j++;
		}
		i++;
	}
}

void put_circle(double y0, double x0, double rad, t_data *img)
{
	double start_y = y0 - rad;
	double start_x = x0 - rad;
	int j;
	int i = 0;
	while (i < (int)rad * 2)
	{
		int r = 255;
		int g = 255;
		int b = 255;
		j = 0;

//sqrt((Xa - Xb) * (Xa - Xb) + (Ya - Yb) * (Ya - Yb))

		while (j < (int)rad * 2)
		{
			int tmp = (r<<16) | (g<<8) | b;
//			printf("dis=%f, rad=%f\n", sqrt((start_x + j - x0) * (start_x + j - x0) + (start_x + j - y0) * (start_x + j - y0)), rad);
			if (sqrt((start_x + j - x0) * (start_x + j - x0) + (start_y + i - y0) * (start_y + i - y0)) <= rad)
				my_mlx_pixel_put(img, (int)start_x + j, (int)start_y + i, tmp);
			if (j < 255)
			{
				r--;
				g--;
				b--;
			}
			else
			{
				r++;
				g++;
				b++;
			}
			j++;
		}
		i++;
	}
}

void put_square(int size, t_data *img)
{
	int x = 100;
	int y = 100;
	int i, j;
	i = 0;
	while (i < 1000)
	{
		j = 0;
		int r = 255;
		int g = 0;
		int b = 0;
		while (j < 1000)
		{
			if (r == 255 && b < 255)
				b++;
			else if (r > 0 && b == 255)
				r--;
			else if (b == 255 && g < 255)
				g++;
			else
				b--;
			int tmp = (r<<16) | (g<<8) | b;
//			printf("%x\n", tmp);
			my_mlx_pixel_put(img, j, i, tmp);
			j++;
		}
		i++;
	}
	i = 0;
//	printf("%x\n", 0xFF000000);
	while (i < size)
	{
		int r = 255;
		int g = 255;
		int b = 255;
		j = 0;
		while (j < size)
		{
			int tmp = (r<<16) | (g<<8) | b;
			my_mlx_pixel_put(img, x + j, y + i, tmp);
			r--;
			g--;
			b--;
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	*((int *)(data->addr) + y * data->line_lenght / (data->bits_per_pixel / 8) + x) = color;
}
