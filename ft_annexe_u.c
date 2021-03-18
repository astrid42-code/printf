/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:01:18 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/18 14:02:31 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_width_u(int len, unsigned int nbr, t_flags *data)
{
	int	w;
	int tmp;

	w = data->width;
	tmp = 0;
	if (w <= len || w <= data->precision/* && data->precision == 0*/)
		ft_treat_prec_u(len, nbr, data);
	else if (w > len && data->minus == 0)
	{
		if (w >= data->precision && data->zero == 1)
			ft_width_nominus_zero_u(w, data, len, nbr);
		else if (w >= data->precision && data->zero == 0)
			ft_width_nominus_nozero_u(w, data, len, nbr);
	}
	else if (w > len && data->minus == 1)
	{
		if (w >= data->precision && data->zero == 1)
			ft_width_minus_zero_u(w, data, len, nbr);
		else if (w >= data->precision && data->zero == 0)
			ft_width_minus_nozero_u(w, data, len, nbr);
	}
}

void	ft_width_nominus_zero_u(int w, t_flags *data, int len, unsigned int nbr)
{
	int	tmp;
//a verif pour sign
	if (data->sign != 0)
	{
		if (data->sign == 1)
			ft_putchar('-');
		else if (data->sign == 2)
			ft_putchar('+');
		w--;
		data->count++;
	}
	if (data->sign != 0)
		data->sign = 0;
	tmp = w - len;
	if (tmp > 0)
		data->count += tmp;
	while (tmp-- > 0)
		ft_putchar('0');
	if (nbr == 0)
		ft_special_argz_prec(len, data);
	else
		ft_treat_prec_u(len, nbr, data);
}

void	ft_width_nominus_nozero_u(int w, t_flags *data, int len, unsigned int nbr)
{
	int tmp;

	if (data->precision >= len && data->precision < data->width)
		tmp = w - data->precision;
	else
		tmp = w - len;
	data->count += tmp;
	if (data->sign != 0)
	{
		//if (tmp < 1) // plus nécessaire puisque quand w = len ce n'est pas ici
		//	data->count++;
		tmp--;
	}
	while (tmp-- > 0)
		ft_putchar(' ');
	if (data->sign == 1)
		ft_putchar('-');
	else if (data->sign == 2)
		ft_putchar('+');
	//if (data->sign != 0)
	//{
		data->sign = 0;
	//}
	if (nbr == 0)
		ft_special_argz_prec(len, data);
	else
		ft_treat_prec_u(len, nbr, data);
}

void	ft_width_minus_zero_u(int w, t_flags *data, int len, unsigned int nbr)
{
	int tmp;

	if (data->sign == 1)
	{
		ft_putchar('-');
		data->count++;
	}
	else if (data->sign == 2)
	{
		ft_putchar('+');
		data->count++;
	}
	tmp = w - len;
	if (data->sign != 0)
		tmp--;
	if (tmp > 0)
		data->count += tmp;
	data->sign = 0;
	if (nbr == 0)
		ft_special_argz_prec(len, data);
	else
		ft_treat_prec_u(len, nbr, data);
	while (tmp-- > 0)
		ft_putchar(' ');
}

void	ft_width_minus_nozero_u(int w, t_flags *data, int len, unsigned int nbr)
{
	int tmp;

	if (data->precision >= len && data->precision < data->width)
		tmp = w - data->precision;
	else
		tmp = w - len;
	if (data->sign != 0)
		tmp--;
	data->count += tmp;
	if (data->sign != 0)
	{
		if (data->sign == 1)
			ft_putchar('-');
		else if (data->sign == 2)
			ft_putchar('+');
		data->count++;
	}
	/*if (data->sign != 0)
		tmp--; // attention  : a priori il ne faut pas tjrs baisser en cas de sign != 0 > il faudrait une autre condition
		data->count += tmp;*/
	data->sign = 0;
	if (nbr == 0)
		ft_special_argz_prec(len, data);
	else
		ft_treat_prec_u(len, nbr, data);
	while (tmp-- > 0)
		ft_putchar(' ');
}
