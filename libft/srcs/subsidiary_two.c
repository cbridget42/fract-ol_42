/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsidiary_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:19:09 by cbridget          #+#    #+#             */
/*   Updated: 2021/11/30 17:07:32 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_itoa_base(unsigned long numb, int base, char *line, int i)
{
	if (numb % base > 9)
		line[i++] = numb % base - 10 + 'a';
	else
		line[i++] = numb % base + '0';
	if (numb / base)
		ft_itoa_base(numb / base, base, line, i);
	else
		line[i++] = '\0';
}

char	*reverse(char *s)
{
	char	letter;
	char	*line;
	char	*tmp;
	int		i;

	i = ft_strlen(s);
	tmp = s + i - 1;
	line = s;
	while (i / 2)
	{
		letter = *line;
		*line = *tmp;
		*tmp = letter;
		line++;
		tmp--;
		i -= 2;
	}
	return (s);
}

void	change_case(char *line)
{
	while (*line)
	{
		if (!ft_isdigit(*line))
			*line = ft_toupper(*line);
		line++;
	}
}
