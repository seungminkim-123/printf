/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 03:41:35 by seukim            #+#    #+#             */
/*   Updated: 2020/05/09 05:14:53 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup(const char *str1)
{
	int		str1_len;
	char	*p1;
	int		i;

	i = 0;
	str1_len = ft_strlen(str1) + 1;
	p1 = (char*)malloc(sizeof(char) * str1_len);
	if (p1 == 0)
		return (NULL);
	while (str1_len > 1)
	{
		p1[i] = str1[i];
		i++;
		str1_len--;
	}
	p1[i] = '\0';
	return (p1);
}

char		*ft_set_stringpre_sub(t_flag_info *flaginfo, char *p1)
{
	char	*tmp;

	p1 = ft_strdup("(null)");
	if (flaginfo->precision < 0)
		flaginfo->precision = 6;
	if (flaginfo->dot)
	{
		tmp = ft_substr(p1, 0, flaginfo->precision);
		p1 = tmp;
	}
	return (p1);
}

char		*ft_set_stringprecision(t_flag_info *flaginfo, char *p1)
{
	char	*tmp;

	if (flaginfo->precision < 0 && p1 != NULL)
		flaginfo->precision = ft_strlen(p1);
	if (p1 == NULL)
		return (ft_set_stringpre_sub(flaginfo, p1));
	if (flaginfo->dot && flaginfo->precision == 0)
	{
		p1 = NULL;
		return (p1);
	}
	if ((ft_strlen(p1) - flaginfo->precision) > 0)
	{
		tmp = ft_substr(p1, 0, flaginfo->precision);
		p1 = tmp;
	}
	return (p1);
}

int			ft_specifier_string(t_flag_info *flaginfo, int *printlen)
{
	char	*p1;
	int		i;

	i = 0;
	ft_check_widthstar(flaginfo);
	if (flaginfo->starprecision)
		flaginfo->precision = va_arg(flaginfo->args, int);
	p1 = va_arg(flaginfo->args, char*);
	if (flaginfo->dot || p1 == NULL)
		p1 = ft_set_stringprecision(flaginfo, p1);
	if (flaginfo->minus)
	{
		ft_putstr(p1, printlen);
		flaginfo->zero = 0;
	}
	ft_width(flaginfo->width, ft_strlen(p1), flaginfo->zero, printlen);
	if (!(flaginfo->minus))
		ft_putstr(p1, printlen);
	return (1);
}
