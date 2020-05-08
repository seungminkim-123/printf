/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:26:39 by seukim            #+#    #+#             */
/*   Updated: 2020/05/08 18:21:18 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_number_sub(t_flag_info *flaginfo, char *p1, int number,
			int *printlen)
{
	if (flaginfo->minus && number < 0)
		ft_putchar('-', printlen);
	if (flaginfo->zero && number < 0)
	{
		ft_putchar('-', printlen);
		flaginfo->width--;
		if (flaginfo->width - ft_strlen(p1) == 1)
			ft_putchar('0', printlen);
	}
}

void	ft_print_number_sub1(t_flag_info *flaginfo, char *p1, int number,
			int *printlen)
{
	while (flaginfo->width - ft_strlen(p1) > 1)
	{
		if (flaginfo->zero)
			ft_putchar('0', printlen);
		else
			ft_putchar(' ', printlen);
		if ((flaginfo->width - ft_strlen(p1)) == 2)
		{
			if (number < 0 && !(flaginfo->zero))
			{
				ft_putchar('-', printlen);
				flaginfo->width--;
			}
			else
			{
				if (flaginfo->zero)
					ft_putchar('0', printlen);
				else
					ft_putchar(' ', printlen);
				flaginfo->width--;
			}
		}
		flaginfo->width--;
	}
}

void	ft_print_number(t_flag_info *flaginfo, char *p1, int number,
			int *printlen)
{
	ft_print_number_sub(flaginfo, p1, number, printlen);
	ft_print_number_sub1(flaginfo, p1, number, printlen);
	ft_putstr(p1, printlen);
}

int		ft_specifier_number_sub(t_flag_info *flaginfo, int *printlen,
			int number, char *p1)
{
	if (!(flaginfo->minus) && flaginfo->width > ft_strlen(p1) + 1)
		ft_print_number(flaginfo, p1, number, printlen);
	else
	{
		if ((flaginfo->width - ft_strlen(p1)) == 1 && number >= 0)
		{
			if (flaginfo->zero)
				ft_putchar('0', printlen);
			else
				ft_putchar(' ', printlen);
		}
		if (number < 0)
			ft_putchar('-', printlen);
		ft_putstr(p1, printlen);
	}
	free(p1);
	return (1);
}

int		ft_specifier_number(t_flag_info *flaginfo, int *printlen)
{
	int		number;
	char	*p1;

	ft_check_widthstar(flaginfo);
	ft_check_precisionstar(flaginfo);
	number = va_arg(flaginfo->args, int);
	p1 = ft_itoa(number);
	if ((flaginfo->precision - ft_strlen(p1)) > 0)
		p1 = ft_printf_strjoin(p1, flaginfo->precision - ft_strlen(p1));
	if (flaginfo->precision == 0 && number == 0 && flaginfo->dot)
	{
		while (flaginfo->width--)
			ft_putchar(' ', printlen);
		return (1);
	}
	if (flaginfo->minus)
	{
		if (number < 0)
			ft_putchar('-', printlen);
		ft_putstr(p1, printlen);
		if (flaginfo->width)
			ft_number_width(flaginfo->width, ft_strlen(p1), number, printlen);
		return (1);
	}
	return (ft_specifier_number_sub(flaginfo, printlen, number, p1));
}
