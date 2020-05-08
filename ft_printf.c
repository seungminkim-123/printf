/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 21:10:47 by seukim            #+#    #+#             */
/*   Updated: 2020/05/08 15:41:31 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_parse_specifier(t_flag_info *flaginfo, char *save, int i)
{
	if (save[i] == '*')
	{
		flaginfo->starprecision = 1;
		i++;
	}
	if (save[i] == '*')
	{
		flaginfo->starprecision = 1;
		i++;
	}
	if (ft_strchr(CONVERSION, save[i]))
	{
		flaginfo->specifier = save[i];
	}
}

void	flag_parse_precision(t_flag_info *flaginfo, char *save, int i)
{
	int j;

	j = 0;
	while (save[i] >= '0' && save[i] <= '9')
	{
		if (j++ == 0)
			flaginfo->width = ft_atoi(&save[i]);
		i++;
	}
	j = 0;
	if (save[i] == '.')
	{
		flaginfo->dot = 1;
		i++;
	}
	while (save[i] >= '0' && save[i] <= '9')
	{
		if (j++ == 0)
			flaginfo->precision = ft_atoi(&save[i]);
		i++;
	}
	flag_parse_specifier(flaginfo, save, i);
}

void	set_flag_option(t_flag_info *flaginfo, char *save)
{
	int		i;

	i = 0;
	while (save[i] == '0' || save[i] == '-')
	{
		while (save[i] == '0')
		{
			flaginfo->zero = 1;
			i++;
		}
		while (save[i] == '-')
		{
			flaginfo->minus = 1;
			i++;
		}
	}
	if (save[i] == '*')
	{
		flaginfo->starwidth = 1;
		i++;
	}
	flag_parse_precision(flaginfo, save, i);
}

int		ft_flag_parse(const char *format, int i,
				t_flag_info *flaginfo, int *printlen)
{
	int				parse_length;
	char			*save;

	reset_flag(flaginfo);
	i += 1;
	parse_length = find_parse_length(format, i, flaginfo);
	if ((save = ft_substr(format, i, parse_length + 1)) > 0)
		set_flag_option(flaginfo, save);
	free(save);
	if (ft_combine_option(flaginfo, printlen))
		return (i + parse_length);
	return (-1);
}

int		ft_printf(const char *format, ...)
{
	int				i;
	t_flag_info		flaginfo;
	int				printlen;

	printlen = 0;
	va_start(flaginfo.args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i], &printlen);
		}
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i = ft_flag_parse(format, i, &flaginfo, &printlen);
			if (i == -1)
				return (-1);
		}
		i++;
	}
	return (printlen);
}
