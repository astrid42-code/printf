/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_argz.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:08:51 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/19 14:47:00 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_special_argz(int len, t_flags *data)
{
	if (data->precision > 0 && (data->width == 0 ||
					data->width <= data->precision))
	{
		ft_special_argz_prec(len, data);
	}
	else if (data->width == 0 && data->precision == -1)
	{
		ft_putchar('0');
		data->count++;
	}
	else if (data->width > data->precision)
	{
		ft_treat_argz_width(len, data);
	}
	else if (data->precision == 0)
		return ;
}

void	ft_special_argz_prec(int len, t_flags *data)
{
	if (data->precision == -1)
	{
		ft_putchar('0');
		data->count++;
	}
	else if (data->precision >= len)
	{
		while (len-- > 0)
			ft_putchar('0');
		data->count += data->precision;
	}
	else if (len == 0)
		return ;
}

void	ft_treat_argz_width(int len, t_flags *data)
{
	int tmp;

	if (data->minus == 1)
	{
		ft_special_argz_prec(len, data);
		tmp = data->width - len;
		data->count += tmp;
		ft_special_argz_width2(tmp, data);
	}
	else if (data->minus == 0)
	{
		tmp = data->width - len;
		data->count += tmp;
		ft_special_argz_width2(tmp, data);
		ft_special_argz_prec(len, data);
	}
}

void	ft_special_argz_width2(int tmp, t_flags *data)
{
	if (data->zero == 0)
	{
		while (tmp-- > 0)
			ft_putchar(' ');
	}
	else if (data->zero == 1)
	{
		while (tmp-- > 0)
			ft_putchar('0');
	}
}
