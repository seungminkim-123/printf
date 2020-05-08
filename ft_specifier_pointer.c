/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 16:14:55 by seukim            #+#    #+#             */
/*   Updated: 2020/05/06 17:53:50 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_specifier_hex(unsigned long long number, int count, char *p1)
{
	int		ret;

	count = count - 1;
	ret = 0;
	while (count >= 0)
	{
		ret = number % 16;
		if (ret < 10)
			p1[count] = 48 + ret;
		else if (ret > 9)
			p1[count] = 97 + (ret - 10);
		number = number / 16;
		count--;
	}
	return (p1);
}

char	*ft_count_hex(unsigned long long number, unsigned long long number2)
{
	int		count;
	char	*p1;

	count = 0;
	if (number == 0)
	{
		if (!(p1 = (char*)malloc(sizeof(char) * count + 2)))
			return (NULL);
		p1[0] = '0';
		p1[1] = '\0';
		return (p1);
	}
	while (1)
	{
		if (number == 0)
			break ;
		number = number / 16;
		count++;
	}
	if (!(p1 = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	ft_specifier_hex(number2, count, p1);
	p1[count] = '\0';
	return (p1);
}

char	*ft_count_pointer(unsigned long long number, unsigned long long number2)
{
	int		count;
	char	*p1;

	count = 0;
	if (number == 0)
	{
		if (!(p1 = (char*)malloc(sizeof(char) * count + 1)))
			return (NULL);
		p1[0] = '\0';
		return (p1);
	}
	while (1)
	{
		if (number == 0)
			break ;
		number = number / 16;
		count++;
	}
	if (!(p1 = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	ft_specifier_hex(number2, count, p1);
	p1[count] = '\0';
	return (p1);
}

int		ft_specifier_pointer(t_flag_info *flaginfo, int *printlen)
{
	char			*p1;
	unsigned long	number;

	ft_check_widthstar(flaginfo);
	ft_check_precisionstar(flaginfo);
	number = va_arg(flaginfo->args, unsigned long);
	if (flaginfo->dot == 1 || number != 0)
		p1 = ft_count_pointer(number, number);
	else
		p1 = ft_strdup("0");
	if (flaginfo->precision > ft_strlen(p1))
		p1 = ft_printf_strjoin(p1, flaginfo->precision - ft_strlen(p1));
	if (flaginfo->minus)
	{
		ft_putstr("0x", printlen);
		ft_putstr(p1, printlen);
	}
	ft_width(flaginfo->width, ft_strlen(p1) + 2, 0, printlen);
	if (!(flaginfo->minus))
	{
		ft_putstr("0x", printlen);
		ft_putstr(p1, printlen);
	}
	return (1);
}
