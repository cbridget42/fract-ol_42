/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:37:59 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/29 14:48:24 by cbridget         ###   ########.fr       */
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
		rgb[1] = (unsigned char)(floor(cl * env_f->flags.clrs1)) % env_f->flags.cof_c1;
		rgb[2] = (unsigned char)(floor(cl * env_f->flags.clrs2)) % env_f->flags.cof_c2;
		rgb[3] = (unsigned char)(floor(cl * env_f->flags.clrs3)) % env_f->flags.cof_c3;
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
		k = (double)i / (double)env_f->coords.max_it;
		rgb[0] = (unsigned char)0x0;
		rgb[1] = (unsigned char)(18 * (1 - k) * pow(k, 3) * env_f->flags.cof_c1);
		rgb[2] = (unsigned char)(144 * pow((1 - k), 2) * pow(k, 2) * env_f->flags.cof_c2);
		rgb[3] = (unsigned char)(env_f->flags.clrs2 * pow((1 - k), 3) * k * env_f->flags.cof_c3);
		return (*(int *)rgb);
	}
}

int	drawing_three(unsigned int i, t_envf *env_f)
{
	if (i == env_f->coords.max_it)
		return (0x0);
	else
		return (env_f->flags.seed);
}

int	ft_do_rand(int *ctx)
{
	long hi, lo, x;

	if (*ctx == 0)
		*ctx = 123459876;
	hi = *ctx / 127773;
	lo = *ctx % 127773;
	x = 16807 * lo - 2836 * hi;
	if (x < 0)
		x += 0x7fffffff;
	return ((*ctx = x) % ((unsigned long)RAND_MAX + 1));
}

int ft_rand_r(int *ctx)
{
	int val = (unsigned long) *ctx;
	int r = ft_do_rand(&val);
	*ctx = (unsigned int) val;
	return (r);
}
