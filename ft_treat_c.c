/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:23:17 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/15 16:04:26 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero_c(t_flags *data)
{
	int tmp;

	tmp = data->width - 1;
	while (tmp > 0)
	{
		ft_putchar('0');
		tmp--;
	}
	ft_putchar((int)data->arg);
	data->count += data->width;
}

void	ft_minus_c(t_flags *data)
{
	int tmp;

	ft_putchar((int)data->arg);
	tmp = data->width - 1;
	while (tmp != 0)
	{
		ft_putchar(' ');
		tmp--;
	}
}

void	ft_nominus_c(t_flags *data)
{
	int tmp;

	tmp = data->width - 1;
	while (tmp != 0)
	{
		ft_putchar(' ');
		tmp--;
	}
	ft_putchar((int)data->arg);
}

void	ft_treat_c(t_flags *data)
{
	if (data->zero == 1)
		ft_zero_c(data);
	else if (data->width > 0)
	{
		if (data->minus == 1)
			ft_minus_c(data);
		else
			ft_nominus_c(data);
		data->count += data->width;
	}
	else
	{
		ft_putchar((int)data->arg);
		data->count++;
	}
}
