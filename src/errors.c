/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:49:20 by cbridget          #+#    #+#             */
/*   Updated: 2022/03/31 16:50:36 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"

void	error_m(int err)
{
	if (err == 5)
		ft_printf("error: wrong number of arguments\n");
	else if (err == 55)
		ft_printf("error: first arg is invalid\n");
	else
		ft_printf("error: wrong number for Julia\n");
	ft_printf("first arg: type of fractal (Mandelbrot \
	or Julia or Burning_ship)\n");
	ft_printf("fot Julia you can enter real and \
	imaginary parts (format like 0.05)\n");
	exit(err);
}
