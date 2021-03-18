/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:41:08 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/18 14:00:37 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_len_u(t_flags *data, int len,	unsigned int nbr)
{
	if (nbr == 0)
	{
		if (data->precision >= 1)
			len = data->precision;
		else if (data->precision == 0)
			len = 0;
		else if (data->precision <= -1)
			len = 1;
	}
	else if (data->precision >= ft_nbrsize_u(nbr))
		len = data->precision;
	else if (data->precision < ft_nbrsize_u(nbr) || data->precision == -1)
		len = ft_nbrsize_u(nbr);
	else if (data->precision == 0)
		len = 0;
	return (len);
}

void	ft_treat_u(t_flags *data)
{
	unsigned int	nbr;
	int				len;

	nbr = (unsigned int)data->arg;
	len = 0;
	len = ft_treat_len_u(data, len, nbr);
	ft_check_struct_i(data);
	if (nbr == 0)
		ft_special_argz(len, data);
	else
		ft_print_nbr_u(data, len, nbr);
	if (data->sign != 0)
		data->sign = 0;
}

void	ft_print_nbr_u(t_flags *data, int len, unsigned int nbr)
{
	if (data->precision > 0 && (data->width == 0 ||
							data->width <= data->precision))
		ft_treat_prec_u(len, nbr, data);
	else if (data->width > 0)
		ft_treat_width_u(len, nbr, data);
	else
	{
		if (data->sign == 2)
		{
			ft_putchar('+');
			data->count++;
		}
		ft_putnbr_u(nbr);
		data->count += len;
	}
}

void	ft_treat_prec_u(int len, unsigned int nbr, t_flags *data)
{
	int	prec;
	int tmp;

	prec = data->precision;
	tmp = 0;
	if (data->precision >= len)
		ft_prec_sup_u(data, prec, nbr);
	else if (data->precision < len)
	{
		if (data->sign != 0)
		{
			if (data->sign == 1)
				ft_putchar('-');
			else if (data->sign == 2)
				ft_putchar('+');
			data->count++;
		}
		ft_putnbr_u(nbr);
		data->count += len;
	}
}

void	ft_prec_sup_u(t_flags *data, int prec, unsigned int nbr)
{
	int tmp;

	tmp = 0;
	if (data->sign != 0 && data->width <= data->precision)
	{
		if (data->sign == 2)
			ft_putchar('+');
		data->count++;
	}
	tmp = prec - ft_nbrsize_u(nbr);
	while (tmp-- > 0)
		ft_putchar('0');
	ft_putnbr_u(nbr);
	data->count += data->precision;
}
