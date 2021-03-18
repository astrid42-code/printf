/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:23:46 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/15 16:07:21 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_struct(void)
{
	t_flags		data;

	data.zero = 0;
	data.minus = 0;
	data.width = 0;
	data.precision = -1;
	data.sign = 0;
	data.count = 0;
	data.i = 0;
	return (data);
}

void	ft_data_struct(t_flags *data, const char *format, va_list arg)
{
	ft_struct_zero(data, format);
	ft_struct_minus(data, format);
	ft_struct_width(data, arg, format);
	if (data->precision != -1)
		data->precision = -1;
	ft_struct_prec(data, arg, format);
	if (ft_check_type(format[data->i]) == 1)
		data->type = format[data->i];
}

void	ft_struct_zero(t_flags *data, const char *format)
{
	if (data->zero != 0)
		data->zero = 0;
	if (format[data->i] == '0')
	{
		data->zero = 1;
		data->i++;
	}
}

void	ft_struct_minus(t_flags *data, const char *format)
{
	if (data->minus != 0)
		data->minus = 0;
	if (format[data->i] == '-')
	{
		data->minus = 1;
		data->i++;
	}
	else if(format[data->i] == '+')
	{
		data->sign = 2;
		data->i++;
	}
	if (data->minus == 1 && data->zero == 1)
		data->zero = 0;
}

void	ft_struct_width(t_flags *data, va_list arg, const char *format)
{
	if (data->width != 0)
		data->width = 0;
	if (format[data->i] == '-' || format[data->i] == '0')
		data->i++;
	if (format[data->i] == '*')
	{
		data->width = va_arg(arg, int);
		data->i++;
	}
	else if (format[data->i] >= '0' && format[data->i] <= '9')
	{
		while (format[data->i] >= '0' && format[data->i] <= '9')
		{
			data->width = (data->width * 10) + (format[data->i] - 48);
			data->i++;
		}
	}
	if (data->width < 0)
	{
		data->width *= -1;
		data->minus = 1;
		if (data->minus == 1 && data->zero == 1)
			data->zero = 0;
	}
}
