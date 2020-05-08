/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 15:10:51 by seukim            #+#    #+#             */
/*   Updated: 2020/05/08 15:13:02 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *printlen)
{
	write(1, &c, 1);
	*printlen += 1;
}

int		ft_strlen(const char *src)
{
	int		len;

	if (src == NULL)
		return (0);
	len = 0;
	while (*src++ != '\0')
		len++;
	return (len);
}

int		ft_atoi(char *str)
{
	int		i;
	int		value;
	int		result;

	value = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			value = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)result * value);
}

char	*ft_substr(char const *str1, unsigned int start, int len)
{
	unsigned int		str1_len;
	int					i;
	char				*p1;

	i = -1;
	str1_len = ft_strlen(str1);
	if ((str1_len < start) || len == 0)
	{
		if (!(p1 = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		p1[0] = '\0';
		return (p1);
	}
	if (!(p1 = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (len > 0 && str1[start] != '\0')
	{
		p1[++i] = str1[start++];
		len--;
	}
	p1[++i] = '\0';
	return (p1);
}

char	*ft_strchr(const char *str, int c)
{
	char	*p1;
	char	sym;

	sym = (char)c;
	p1 = (char*)str;
	while (*p1 != '\0')
	{
		if (*p1 == sym)
			return (p1);
		p1++;
	}
	if (*p1 == sym)
		return (p1);
	return (0);
}
