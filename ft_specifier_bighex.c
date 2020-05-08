/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_bighex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:21:34 by seukim            #+#    #+#             */
/*   Updated: 2020/05/06 15:09:10 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_specifier_bighex(unsigned long long number, int count, char *p1)
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
			p1[count] = 65 + (ret - 10);
		number = number / 16;
		count--;
	}
	return (p1);
}

char	*ft_count_bighex(unsigned long long number, unsigned long long number2)
{
	int		count;
	char	*p1;

	count = 0;
	if (number == 0)
	{
		if (!(p1 = (char*)malloc(sizeof(char) * count + 1)))
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
	ft_specifier_bighex(number2, count, p1);
	p1[count] = '\0';
	return (p1);
}

int		ft_specifier_bighexa(t_flag_info *flaginfo, int *printlen)
{
	unsigned long long	number;
	char				*p1;

	ft_check_widthstar(flaginfo);
	ft_check_precisionstar(flaginfo);
	number = va_arg(flaginfo->args, unsigned int);
	p1 = ft_count_bighex(number, number);
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
