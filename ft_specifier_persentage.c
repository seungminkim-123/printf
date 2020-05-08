/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_persentage.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:42:22 by seukim            #+#    #+#             */
/*   Updated: 2020/05/09 04:51:20 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_specifier_persentage(t_flag_info *flaginfo, int *printlen)
{
	ft_check_widthstar(flaginfo);
	if (flaginfo->minus)
	{
		ft_putchar('%', printlen);
		flaginfo->zero = 0;
	}
	ft_width(flaginfo->width, 1, flaginfo->zero, printlen);
	if (!(flaginfo->minus))
		ft_putchar('%', printlen);
	return (1);
}
