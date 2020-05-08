/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:03:11 by seukim            #+#    #+#             */
/*   Updated: 2020/05/08 17:16:11 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_number(char c, int *printlen)
{
	write(1, &c, 1);
	*printlen += 1;
}

int		ft_putstr(char *str, int *printlen)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		ft_putchar(str[i], printlen);
		i++;
	}
	return (0);
}

int		itoa_length(int long n)
{
	int		len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa_sub(char *p1)
{
	p1[0] = '0';
	return (p1);
}

char	*ft_itoa(int long n)
{
	char	*p1;
	int		len;

	len = itoa_length(n);
	p1 = (char *)malloc(sizeof(p1) * len + 1);
	p1[itoa_length(n)] = '\0';
	if (n == 0)
		return (ft_itoa_sub(p1));
	if (n < 0)
	{
		if (n == -2147483648)
		{
			p1[len-- - 1] = '8';
			n = n / 10;
		}
		n = -n;
	}
	while (n != 0 && len >= 0)
	{
		p1[len-- - 1] = n % 10 + 48;
		n = n / 10;
	}
	return (p1);
}
