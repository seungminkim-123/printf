/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 17:27:32 by seukim            #+#    #+#             */
/*   Updated: 2020/05/08 18:23:25 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p1;
	char	*p2;

	if (!s1 && !s2)
		return (NULL);
	p1 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p1 == 0)
		return (NULL);
	p2 = p1;
	while (*s1 != '\0')
		*p1++ = *s1++;
	while (*s2 != '\0')
		*p1++ = *s2++;
	*p1 = '\0';
	return (p2);
}

char	*ft_printf_strjoin(char *str, int i)
{
	char	*p1;
	char	*p2;
	int		j;

	j = 0;
	p1 = (char*)malloc(sizeof(char) * i + 1);
	while (i)
	{
		p1[j++] = '0';
		i--;
	}
	p1[j] = '\0';
	p2 = ft_strjoin(p1, str);
	free(p1);
	free(str);
	return (p2);
}

int		ft_check_precisionstar(t_flag_info *flaginfo)
{
	if (flaginfo->starprecision)
	{
		flaginfo->precision = va_arg(flaginfo->args, int);
		if (flaginfo->precision < 0)
		{
			flaginfo->precision = 1;
			return (0);
		}
	}
	if (flaginfo->dot)
	{
		flaginfo->zero = 0;
	}
	return (0);
}

void	ft_number_width(int width, int minus, int number, int *printlen)
{
	if (number < 0)
		width--;
	while (width - minus > 0)
	{
		ft_putchar(' ', printlen);
		width--;
	}
}
