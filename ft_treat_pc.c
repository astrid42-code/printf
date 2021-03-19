/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:15:48 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/19 11:16:00 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_pc(t_flags *data)
{
	if (data->width <= 0)
	{
		if (data->zero == 1)
			data->zero = 0;
	}
	if (data->width > 0)
	{
		if (data->minus == 0)
			ft_treat_width_minus_pc(data);
		else if (data->minus == 1)
			ft_treat_width_nominus_pc(data);
	}
	else
	{
		ft_putchar('%');
		data->count++;
	}
}

void	ft_treat_width_minus_pc(t_flags *data)
{
	int len;

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
	data->count += data->width;
}

void	ft_treat_width_nominus_pc(t_flags *data)
{
	int len;

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
	data->count += data->width;
}
