/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:43:46 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/28 17:05:25 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_envf *env_f)
{
	mlx_clear_window(env_f->mlx, env_f->win);
	mlx_destroy_window(env_f->mlx, env_f->win);
	free(env_f->mlx);
	exit(0);
}

int	m_mouse(int x, int y, t_envf *env_f)
{
	env_f->coords.x = x;
	env_f->coords.y = y;
	return (0);
}

void	change_dr(t_envf *env_f)
{
	new_img(env_f);
	env_f->flags.drw = 1;
	ft_fractals(env_f);
}
