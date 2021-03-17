/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:09:58 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/15 17:12:36 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isnotpercent(const char *format, t_flags *data)
{
	ft_putchar(format[data->i]);
	data->count++;
}

void	ft_ispercent(const char *format, t_flags *data, va_list args)
{
	data->i++;
	ft_data_struct(data, format, args);
	//printf("type = %c\nzero = %d\nminus = %d\nw = %d\np = %d\nc = %d\ni = %d\n", data->type, data->zero, data->minus, data->width, data->precision, data->count, data->i);
	ft_parser(data, args);
}

int		ft_check_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
			|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	ft_treat_singlepc(t_flags *data)
{
	ft_putchar('%');
	data->count++;
	data->i++;
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_flags		data;

	va_start(args, format);
	data = ft_init_struct();
	while (format[data.i])
	{
		if (format[data.i] != '%')
			ft_isnotpercent(format, &data);
		if (format[data.i] == '%')
		{
			if (format[data.i + 1] == '\0')
				break ;
			if (format[data.i + 1] == '%')
				ft_treat_singlepc(&data);
			else if (format[data.i + 1] != '%')
				ft_ispercent(format, &data, args);
		}
		data.i++;
	}
	va_end(args);
	return (data.count);
}
