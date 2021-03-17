/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:19:59 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/15 20:18:40 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parser(t_flags *data, va_list args)
{
	ft_convert_arg(data, args);
	if (data->type == 'c')
		ft_treat_c(data);
	if (data->type == 's')
		ft_treat_str(data);
	if (data->type == 'i' || data->type == 'd')
		ft_treat_i(data);
/*	if (data->type == 'x' || data->type == 'X')
		ft_treat_x(data);
	if (data->type == 'u')
		ft_treat_u(data);
	if (data->type == 'p')
		ft_treat_ptr(data);
	if (data->type == '%')
		ft_treat_pc(data);*/
}

void	ft_convert_arg(t_flags *data, va_list args)
{
	if (data->type == 'i' || data->type == 'd')
		data->arg = va_arg(args, void *);
	if (data->type == 'u')
		data->arg = va_arg(args, void *);
	if (data->type == 'c')
		data->arg = va_arg(args, void *);
	if (data->type == 's')
	{
		data->arg = va_arg(args, void *);
		if (data->arg == NULL || data->arg == 0)
			data->arg = "(null)";
	}
	if (data->type == 'x' || data->type == 'X')
		data->arg = va_arg(args, void *);
	if (data->type == 'p')
		data->arg = va_arg(args, void *);
}
