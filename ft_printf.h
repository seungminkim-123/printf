/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 21:11:36 by seukim            #+#    #+#             */
/*   Updated: 2020/05/09 05:08:53 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONVERSION "cspdiuxX%"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>

typedef struct	s_flag_info
{
	va_list		args;
	char		flag;
	int			zero;
	int			minus;
	int			width;
	int			dot;
	int			precision;
	int			starwidth;
	int			starprecision;
	char		specifier;
}				t_flag_info;

int				ft_printf(const char *format, ...);
int				ft_flag_parse(const char *format, int i, t_flag_info *flaginfo,
					int *printlen);
int				ft_combine_option(t_flag_info *flaginfo, int *printlen);
void			set_flag_option(t_flag_info *flaginfo, char *save);
void			flag_parse_precision(t_flag_info *flaginfo, char *save, int i);
void			flag_parse_specifier(t_flag_info *flaginfo, char *save, int i);
void			reset_flag(t_flag_info	*flaginfo);
int				find_parse_length(const char *format, int i,
					t_flag_info *flaginfo);
char			*ft_strchr(const char *str, int c);
char			*ft_substr(char const *str1, unsigned int start, int len);
int				ft_atoi(char *str);
int				ft_strlen(const char *src);
void			ft_putchar(char c, int *printlen);
char			*ft_specifier_bighex(unsigned long long number, int count,
					char *p1);
char			*ft_count_bighex(unsigned long long number,
					unsigned long long number2);
int				ft_specifier_bighexa(t_flag_info *flaginfo, int *printlen);
void			ft_check_widthstar(t_flag_info *flaginfo);
void			ft_width(int width, int minus, int zero, int *printlen);
int				ft_specifier_char(t_flag_info *flaginfo, int *printlen);
int				ft_specifier_hexa(t_flag_info *flaginfo, int *printlen);
void			ft_hex_width(int width, int minus, int *printlen,
					t_flag_info *flaginfo);
int				ft_specifier_number(t_flag_info	*flaginfo, int *printlen);
void			ft_print_number(t_flag_info *flaginfo, char *p1, int number,
					int *printlen);
void			ft_number_width(int width, int minus,
					int number, int *printlen);
int				ft_check_precisionstar(t_flag_info *flaginfo);
char			*ft_printf_strjoin(char *str, int i);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int long n);
char			*ft_itoa_sub(char *p1);
int				itoa_length(int long n);
int				ft_putstr(char *str, int *printlen);
void			ft_putchar_number(char c, int *printlen);
int				ft_specifier_persentage(t_flag_info *flaginfo, int *printlen);
int				ft_specifier_pointer(t_flag_info *flaginfo, int *printlen);
char			*ft_count_hex(unsigned long long number,
					unsigned long long number2);
char			*ft_specifier_hex(unsigned long long number, int count,
					char *p1);
int				ft_specifier_string(t_flag_info	*flaginfo, int *printlen);
char			*ft_set_stringprecision(t_flag_info *flaginfo, char *p1);
char			*ft_strdup(const char *str1);
int				ft_specifier_unint(t_flag_info *flaginfo, int *printlen);
char			*ft_count_pointer(unsigned long long number,
					unsigned long long number2);
int				ft_specifier_unint_sub(t_flag_info *flaginfo, int *printlen,
					unsigned int number, char *p1);
void			ft_print_number_sub(t_flag_info *flaginfo, char *p1, int number,
					int *printlen);
void			ft_print_number_sub1(t_flag_info *flaginfo, char *p1,
					int number, int *printlen);
int				ft_specifier_number_sub(t_flag_info *flaginfo, int *printlen,
					int number, char *p1);
char			*ft_set_stringpre_sub(t_flag_info *flaginfo, char *p1);

#endif
