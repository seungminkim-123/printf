/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:09:07 by seukim            #+#    #+#             */
/*   Updated: 2020/05/06 15:08:48 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex_width(int width, int minus, int *printlen,
	t_flag_info *flaginfo)
{
	while (width - minus > 0)
	{
		if (flaginfo->zero)
			ft_putchar('0', printlen);
		else
			ft_putchar(' ', printlen);
		width--;
	}
}

int		ft_specifier_hexa(t_flag_info *flaginfo, int *printlen)
{
	unsigned long long	number;
	char				*p1;

	ft_check_widthstar(flaginfo);
	ft_check_precisionstar(flaginfo);
	number = va_arg(flaginfo->args, unsigned int);
	p1 = ft_count_hex(number, number);
	if ((flaginfo->precision - ft_strlen(p1)) > 0)
		p1 = ft_printf_strjoin(p1, flaginfo->precision - ft_strlen(p1));
	if (flaginfo->precision == 0 && number == 0 && flaginfo->dot)
	{
		while (flaginfo->width--)
			ft_putchar(' ', printlen);
		return (1);
	}
	if (flaginfo->minus)
		ft_putstr(p1, printlen);
	ft_hex_width(flaginfo->width, ft_strlen(p1), printlen, flaginfo);
	if (!(flaginfo->minus))
		ft_putstr(p1, printlen);
	return (1);
}
