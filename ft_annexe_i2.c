/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe_i2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:30:58 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/16 21:32:50 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_minus_zero(int w, t_flags *data, int len, int nbr)
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
		ft_treat_prec_i(len, nbr, data);
	while (tmp-- > 0)
		ft_putchar(' ');
}

void	ft_width_minus_nozero(int w, t_flags *data, int len, int nbr)
{
	int tmp;

	if (data->sign != 0)
	{
		if (data->sign == 1)
			ft_putchar('-');
		else if (data->sign == 2)
			ft_putchar('+');
		data->count++;
	}
	tmp = w - len;
	if (data->sign != 0)
		tmp--; // attention  : a priori il ne faut pas tjrs baisser en cas de sign != 0 > il faudrait une autre condition
	if (tmp > 0)
		data->count += tmp;
	data->sign = 0;
	if (nbr == 0)
		ft_special_argz_prec(len, data);
	else
		ft_treat_prec_i(len, nbr, data);
	while (tmp-- > 0)
		ft_putchar(' ');
}

void	ft_special_argz(int len, t_flags *data, int nbr)
{
	if (data->precision > 0 && (data->width == 0 ||
					data->width <= data->precision))
		ft_special_argz_prec(len, data);
	else if (data->width > 0)
		ft_treat_width_i(len, nbr, data);
	else if (data->precision == 0)
		return ;
	else
	{
		ft_putchar('0');
		data->count++;
	}
}

void	ft_special_argz_prec(int len, t_flags *data)
{
	if (data->precision == -1)
	{
		ft_putchar('0');
		if (data->width == 0)
			data->count++;
	}
	else if (data->precision == len)
	{
		while (len-- > 0)
			ft_putchar('0');
		data->count += data->precision;
	}
	else if (len == 0)
		return ;
}
