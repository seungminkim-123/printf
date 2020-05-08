/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parse_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 15:19:12 by seukim            #+#    #+#             */
/*   Updated: 2020/05/08 15:26:37 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_parse_length(const char *format, int i, t_flag_info *flaginfo)
{
	int length;

	length = 0;
	while (1)
	{
		if (format[i] == '%')
			break ;
		if (ft_strchr(CONVERSION, format[i]))
		{
			flaginfo->specifier = format[i];
			break ;
		}
		i++;
		length++;
	}
	return (length);
}

void	reset_flag(t_flag_info *flaginfo)
{
	flaginfo->flag = 0;
	flaginfo->minus = 0;
	flaginfo->width = 0;
	flaginfo->dot = 0;
	flaginfo->precision = 0;
	flaginfo->specifier = 0;
	flaginfo->zero = 0;
	flaginfo->starwidth = 0;
	flaginfo->starprecision = 0;
}

int		ft_combine_option(t_flag_info *flaginfo, int *printlen)
{
	int i;

	i = 0;
	if (flaginfo->specifier == 'c')
		return (ft_specifier_char(flaginfo, printlen));
	if (flaginfo->specifier == 'd' || flaginfo->specifier == 'i')
		return (ft_specifier_number(flaginfo, printlen));
	if (flaginfo->specifier == 's')
		return (ft_specifier_string(flaginfo, printlen));
	if (flaginfo->specifier == 'p')
		return (ft_specifier_pointer(flaginfo, printlen));
	if (flaginfo->specifier == 'x')
		return (ft_specifier_hexa(flaginfo, printlen));
	if (flaginfo->specifier == 'X')
		return (ft_specifier_bighexa(flaginfo, printlen));
	if (flaginfo->specifier == 'u')
		return (ft_specifier_unint(flaginfo, printlen));
	if (flaginfo->specifier == '%')
		return (ft_specifier_persentage(flaginfo, printlen));
	return (0);
}
