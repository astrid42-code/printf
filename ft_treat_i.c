/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:08:03 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/19 14:28:29 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_struct_i(t_flags *data)
{
	if (data->zero == 1 && data->precision > -1)
		data->zero = 0;
}

void	ft_treat_i(t_flags *data)
{
	int	nbr;
	int	len;

	nbr = (int)data->arg;
	len = 0;
	if (nbr < 0)
	{
		data->sign = 1;
		nbr *= -1;
	}
	len = ft_treat_len_i(data, len, nbr);
	ft_check_struct_i(data);
	if (nbr == 0)
		ft_special_argz(len, data);
	else
		ft_print_nbr(data, len, nbr);
	if (data->sign != 0)
		data->sign = 0;
}

void	ft_print_nbr(t_flags *data, int len, int nbr)
{
	if (data->precision > 0 && (data->width == 0 ||
					data->width <= data->precision))
		ft_treat_prec_i(len, nbr, data);
	else if (data->width > 0)
		ft_treat_width_i(len, nbr, data);
	else
	{
		if (nbr == -2147483648)
		{
			write(1, "-2147483648", 11);
			data->count += 11;
		}
		else
		{
			if (data->sign == 1)
			{
				ft_putchar('-');
				data->count++;
			}
			ft_putnbr(nbr);
			data->count += len;
		}
	}
}

void	ft_treat_prec_i(int len, int nbr, t_flags *data)
{
	int	prec;
	int tmp;

	prec = data->precision;
	tmp = 0;
	if (data->precision >= len)
		ft_prec_sup(data, prec, nbr);
	else if (data->precision < len)
	{
		if (nbr == -2147483648)
			ft_intmin_i(data, len);
		else
		{
			if (data->sign == 1)
			{
				ft_putchar('-');
				data->count++;
			}
			ft_putnbr(nbr);
		}
		data->count += len;
	}
}

void	ft_intmin_i(t_flags *data, int len)
{
	if (data->width <= len || data->width <= data->precision)
		ft_putchar('-');
	write(1, "2147483648", 10);
	data->count++;
}
