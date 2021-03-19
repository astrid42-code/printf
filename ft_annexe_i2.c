/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe_i2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:09:40 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/19 15:03:51 by asgaulti         ###   ########.fr       */
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
		data->count++;
	}
	data->sign = 0;
	if (nbr == 0)
		ft_special_argz_prec(len, data);
	else
		ft_treat_prec_i(len, nbr, data);
	while (tmp-- > 0)
		ft_putchar(' ');
}
