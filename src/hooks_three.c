/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:35:28 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/30 17:36:13 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	arrow_m(t_envf *env_f, int kc)
{
	new_img(env_f);
	if (kc == 125)
		env_f->coords.c_y += (double)SHIFT / env_f->coords.scale;
	else if (kc == 126)
		env_f->coords.c_y -= (double)SHIFT / env_f->coords.scale;
	else if (kc == 123)
		env_f->coords.c_x -= (double)SHIFT / env_f->coords.scale;
	else
		env_f->coords.c_x += (double)SHIFT / env_f->coords.scale;
	ft_fractals(env_f);
}
