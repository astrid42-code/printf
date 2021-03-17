/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct_prec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:38:44 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/17 09:13:56 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_prec_struct(t_flags *data, const char *format)
{
	if (data->precision != -1)
		data->precision = -1;
	if (ft_check_type(format[data->i]) == 1)
		data->precision = 0;
}

void	ft_struct_prec_zero(t_flags *data, const char *format)
{
	if (ft_check_type(format[data->i + 1]) == 1)
	{
		data->precision = 0;
		data->i++;
	}
	else if (format[data->i] == '0')
	{
		while (format[data->i] == '0')
			data->i++;
		if (ft_check_type(format[data->i]) == 1)
			data->precision = 0;
		else if (format[data->i] >= '1' && format[data->i] <= '9')
		{
			data->precision = 0;
			while (format[data->i] >= '0' && format[data->i] <= '9')
			{
				data->precision = (data->precision * 10) +
											(format[data->i] - 48);
				data->i++;
			}
		}
	}
	else if (format[data->i + 1] >= '1' && format[data->i + 1] <= '9')
		ft_struct_prec_zero_annexe(data, format);
}

void	ft_struct_prec_zero_annexe(t_flags *data, const char *format)
{
	data->i++;
	data->precision = 0;
	while (format[data->i] >= '0' && format[data->i] <= '9')
	{
		data->precision = (data->precision * 10) + (format[data->i] - 48);
		data->i++;
	}
}

void	ft_struct_prec(t_flags *data, va_list arg, const char *format)
{
	if (format[data->i] == '.')
	{
		data->i++;
		ft_check_prec_struct(data, format);
		if (format[data->i] == '0')
			ft_struct_prec_zero(data, format);
		else if (format[data->i] == '*')
		{
			data->precision = va_arg(arg, int);
			if (data->precision < -1)
				data->precision = -1;
			data->i++;
		}
		else if (format[data->i] >= '0' && format[data->i] <= '9')
		{
			data->precision = 0;
			while (format[data->i] >= '0' && format[data->i] <= '9')
			{
				data->precision = (data->precision * 10) +
											(format[data->i] - 48);
				data->i++;
			}
		}
	}
}
