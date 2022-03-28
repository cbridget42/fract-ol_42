/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:37:59 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/28 16:56:04 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	drawing_one(unsigned int i, t_envf *env_f, double x, double y)
{
	double			cl;
	unsigned char	rgb[4];

	if (i == env_f->coords.max_it)
		return (0x0);
	else
	{
		cl = i + 2 - log(log(x * x + y * y)) / M_LN2;
		if (cl < 0)
			cl = 0;
		cl = 8 * sqrt(cl);
		rgb[0] = (unsigned char)0x0;
		rgb[1] = (unsigned char)(floor(cl * /*2*/5)) % 255;
		rgb[2] = (unsigned char)(floor(cl * /*9*/2)) % 255;
		rgb[3] = (unsigned char)(floor(cl * /*1*/3)) % 255;
		return (*(int *)rgb);
	}
}

int	drawing_two(unsigned int i, t_envf *env_f)
{
	double			k;
	unsigned char	rgb[4];
	
	if (i == env_f->coords.max_it)
		return (0x0);
	else
	{
		k = (double)i / (double)env_f->coords.max_it;//50 is wrong but cool;
		rgb[0] = (unsigned char)0x0;
		rgb[1] = (unsigned char)(18 * (1 - k) * pow(k, 3) * 255);
		rgb[2] = (unsigned char)(144 * pow((1 - k), 2) * pow(k, 2) * 255);
		rgb[3] = (unsigned char)(1 * pow((1 - k), 3) * k * 255);
		return (*(int *)rgb);
	}
}
