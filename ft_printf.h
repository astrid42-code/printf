/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:12:20 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/19 14:32:13 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_flags
{
	int		type;
	int		zero;
	int		minus;
	int		width;
	int		precision;
	void	*arg;
	int		sign;
	int		count;
	int		i;
}				t_flags;

int				ft_printf(const char *format, ...);

void			ft_isnotpercent(const char *format, t_flags *data);
void			ft_treat_singlepc(t_flags *data);
void			ft_ispercent(const char *format, t_flags *data, va_list args);
int				ft_check_type(char c);

t_flags			ft_init_struct(void);
void			ft_data_struct(t_flags *data, const char *format, va_list arg);
void			ft_struct_zero(t_flags *data, const char *format);
void			ft_struct_minus(t_flags *data, const char *format);
void			ft_struct_width(t_flags *data, va_list arg, const char *format);
void			ft_struct_prec(t_flags *data, va_list arg, const char *format);
void			ft_check_prec_struct(t_flags *data, const char *format);
void			ft_struct_prec_zero(t_flags *data, const char *format);
void			ft_struct_prec_zero_annexe(t_flags *data, const char *format);
void			ft_parser(t_flags *data, va_list args);
void			ft_convert_arg(t_flags *data, va_list args);

void			ft_treat_c(t_flags *data);
void			ft_zero_c(t_flags *data);
void			ft_minus_c(t_flags *data);
void			ft_nominus_c(t_flags *data);

void			ft_treat_str(t_flags *data);
int				ft_treat_prec_str(t_flags *data, int len);
void			ft_print_str(t_flags *data, int prec, int w, int len);
void			ft_print_minus_str(t_flags *data, int w, int prec, int len);
void			ft_print_nominus_str(t_flags *data, int w, int prec, int len);

void			ft_treat_i(t_flags *data);
int				ft_nbr_neg(int nbr, t_flags *data);
void			ft_check_struct_i(t_flags *data);
int				ft_treat_len_i(t_flags *data, int len, int nbr);
void			ft_print_nbr(t_flags *data, int len, int nbr);
void			ft_treat_prec_i(int len, int nbr, t_flags *data);
void			ft_intmin_i(t_flags *data, int len);
void			ft_special_argz(int len, t_flags *data);
void			ft_special_argz_prec(int len, t_flags *data);
void			ft_treat_argz_width(int len, t_flags *data);
void			ft_special_argz_width2(int tmp, t_flags *data);
void			ft_prec_sup(t_flags *data, int prec, int nbr);
void			ft_treat_width_i(int len, int nbr, t_flags *data);
void			ft_width_nominus_zero(int w, t_flags *data, int len, int nbr);
void			ft_width_nominus_nozero(int w, t_flags *data, int len, int nbr);
void			ft_width_minus_zero(int w, t_flags *data, int len, int nbr);
void			ft_width_minus_nozero(int w, t_flags *data, int len, int nbr);

void			ft_treat_u(t_flags *data);
int				ft_treat_len_u(t_flags *data, int len, unsigned int nbr);
void			ft_print_nbr_u(t_flags *data, int len, unsigned int nbr);
void			ft_treat_prec_u(int len, unsigned int nbr, t_flags *data);
void			ft_prec_sup_u(t_flags *data, int prec, unsigned int nbr);
void			ft_treat_width_u(int len, unsigned int nbr, t_flags *data);
void			ft_width_nominus_zero_u(int w, t_flags *data, int len,
											unsigned int nbr);
void			ft_width_nominus_nozero_u(int w, t_flags *data, int len,
											unsigned int nbr);
void			ft_width_minus_zero_u(int w, t_flags *data, int len,
											unsigned int nbr);
void			ft_width_minus_nozero_u(int w, t_flags *data, int len,
											unsigned int nbr);

void			ft_treat_pc(t_flags *data);
void			ft_treat_width_minus_pc(t_flags *data);
void			ft_treat_width_nominus_pc(t_flags *data);

void			ft_treat_hexa(t_flags *data);
void			ft_print_nbr_hexa(t_flags *data, int len, unsigned int nbr);
void			ft_convert_hexa(t_flags *data, unsigned int nbr);
int				ft_itoasize(unsigned int nbr);
void			ft_treat_prec_hexa(int len, unsigned int nbr, t_flags *data);
void			ft_prec_sup_hexa(t_flags *data, int prec, unsigned int nbr);
void			ft_treat_width_hexa(int len, unsigned int nbr, t_flags *data);
void			ft_width_nominus_zero_hexa(int w, t_flags *data, int len,
										unsigned int nbr);
void			ft_width_nominus_nozero_hexa(int w, t_flags *data, int len,
										unsigned int nbr);
void			ft_width_minus_zero_hexa(int w, t_flags *data, int len,
										unsigned int nbr);
void			ft_width_minus_nozero_hexa(int w, t_flags *data, int len,
										unsigned int nbr);

void			ft_treat_ptr(t_flags *data);
int				ft_itoasize_ptr(unsigned long long nbr);
void			ft_treat_minus_ptr(int tmp, t_flags *data,
										unsigned long long ptr);
void			ft_treat_nominus_ptr(int tmp, t_flags *data,
										unsigned long long ptr);
void			ft_convert_hexa_ptr(t_flags *data,
										unsigned long long nbr);
void			ft_nowidth_ptr(unsigned long long ptr, t_flags *data, int len);

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_nbrsize(int nbr);
int				ft_nbrsize_long(long nbr);
void			ft_putnbr(int nb);
void			ft_putnbr_u(unsigned int nb);
int				ft_nbrsize_u(unsigned int nbr);

#endif
