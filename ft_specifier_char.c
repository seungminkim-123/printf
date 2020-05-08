/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 00:13:05 by seukim            #+#    #+#             */
/*   Updated: 2020/04/28 00:13:05 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_widthstar(t_flag_info *flaginfo)
{
	if (flaginfo->starwidth)
	{
		flaginfo->width = va_arg(flaginfo->args, int);
		if (flaginfo->width < 0)
		{
			flaginfo->width *= -1;
			flaginfo->minus = 1;
		}
	}
}

void	ft_width(int width, int minus, int zero, int *printlen)
{
	while (width - minus > 0)
	{
		if (zero)
			ft_putchar('0', printlen);
		else
			ft_putchar(' ', printlen);
		width--;
	}
}

int		ft_specifier_char(t_flag_info *flaginfo, int *printlen)
{
	char c;

	ft_check_widthstar(flaginfo);
	c = va_arg(flaginfo->args, int);
	if (flaginfo->minus)
		ft_putchar(c, printlen);
	ft_width(flaginfo->width, 1, flaginfo->zero, printlen);
	if (!(flaginfo->minus))
		ft_putchar(c, printlen);
	return (1);
}
