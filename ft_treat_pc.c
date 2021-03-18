/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:43:00 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/18 14:55:18 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_pc(t_flags *data)
{
	if (data->width < 0)
	{
		if (data->zero == 1)
			data->zero = 0;
	}
	if (data->width > 0)
		ft_treat_width_pc(data);
	else
	{
		ft_putchar('%');
		data->count++;
	}
}

void	ft_treat_width_pc(t_flags *data)
{
	int len;

	if (data->minus == 0)
	{
		if (data->zero == 1)
		{
			len = data->width - 1;
			while (len-- != 0)
				ft_putchar('0');
		}
		else
		{
			len = data->width - 1;
			while (len-- != 0)
				ft_putchar(' ');
		}
		ft_putchar('%');
	}
	else if (data->minus == 1)
	{
		ft_putchar('%');
		if (data->zero == 1)
		{
			len = data->width - 1;
			while (len-- != 0)
				ft_putchar('0');
		}
		else
		{
			len = data->width - 1;
			while (len-- != 0)
				ft_putchar(' ');
		}
	}
	data->count += data->width;
}
