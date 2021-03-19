/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:07:30 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/19 11:07:40 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_hexa(t_flags *data)
{
	unsigned int	nbr;
	int				len;

	nbr = (unsigned int)data->arg;
	len = ft_itoasize(nbr);
	if (data->zero == 1 && data->precision != -1)
		data->zero = 0;
	if (nbr == 0)
	{
		if (data->precision >= 1)
			len = data->precision;
		else if (data->precision == 0)
			len = 0;
		else if (data->precision <= -1)
			len = 1;
		ft_special_argz(len, data);
	}
	else
		ft_print_nbr_hexa(data, len, nbr);
	if (data->sign != 0)
		data->sign = 0;
}

void	ft_print_nbr_hexa(t_flags *data, int len, unsigned int nbr)
{
	long	nb;

	nb = (long)nbr;
	if (data->precision > 0 && (data->width == 0 ||
							data->width <= data->precision))
		ft_treat_prec_hexa(len, nbr, data);
	else if (data->width > 0)
		ft_treat_width_hexa(len, nbr, data);
	else
	{
		if (data->sign == 2)
		{
			ft_putchar('+');
			data->count++;
		}
		ft_convert_hexa(data, nbr);
		data->count += len;
	}
}

void	ft_treat_prec_hexa(int len, unsigned int nbr, t_flags *data)
{
	int	prec;

	prec = data->precision;
	if (data->precision >= len)
		ft_prec_sup_hexa(data, prec, nbr);
	else if (data->precision < len)
	{
		if (data->sign != 0)
		{
			if (data->sign == 2)
				ft_putchar('+');
			data->count++;
		}
		ft_convert_hexa(data, nbr);
		data->count += len;
	}
}

void	ft_prec_sup_hexa(t_flags *data, int prec, unsigned int nbr)
{
	int tmp;
	int len;

	tmp = 0;
	len = ft_itoasize(nbr);
	if (data->sign != 0 && data->width <= data->precision)
	{
		if (data->sign == 2)
			ft_putchar('+');
		data->count++;
	}
	tmp = prec - len;
	while (tmp-- > 0)
		ft_putchar('0');
	ft_convert_hexa(data, nbr);
	data->count += data->precision;
}
