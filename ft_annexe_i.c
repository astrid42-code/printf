/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:28:40 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/16 11:28:40 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_len_i(t_flags *data, int len, int nbr)
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
	else if (nbr == -2147483648)
	{
		len = ft_nbrsize_long(nbr) - 1;
		data->sign = 1;
	}
	else if (data->precision >= ft_nbrsize(nbr))
		len = data->precision;
	else if (data->precision < ft_nbrsize(nbr) || data->precision == -1)
		len = ft_nbrsize(nbr);
	else if (data->precision == 0)
		len = 0;
	return (len);
}

void		ft_prec_sup(t_flags *data, int prec, int nbr)
{
	int tmp;

	tmp = 0;
	if (data->sign != 0 && data->width <= data->precision)
	{
		if (data->sign == 1)
			ft_putchar('-');
		else if (data->sign == 2)
			ft_putchar('+');
		data->count++;
	}
	if (nbr == -2147483648)
		tmp = prec - ft_nbrsize_long(nbr);
	else
		tmp = prec - ft_nbrsize(nbr);
	while (tmp-- > 0)
			ft_putchar('0');
	if (nbr == -2147483648)
		write(1, "2147483648", 10);
	else
		ft_putnbr(nbr);
	data->count += data->precision;
	//printf("c = %d\n", data->count);
}

void	ft_treat_width_i(int len, int nbr, t_flags *data)
{
	int	w;
	int tmp;

	w = data->width;
	tmp = 0;
	if (w <= len || w <= data->precision/* && data->precision == 0*/)
		ft_treat_prec_i(len, nbr, data);
	else if (w > len && data->minus == 0)
	{
		if (w >= data->precision && data->zero == 1)
			ft_width_nominus_zero(w, data, len, nbr);
		else if (w >= data->precision && data->zero == 0)
			ft_width_nominus_nozero(w, data, len, nbr);
	}
	else if (w > len && data->minus == 1)
	{
		if (w >= data->precision && data->zero == 1)
			ft_width_minus_zero(w, data, len, nbr);
		else if (w >= data->precision && data->zero == 0)
			ft_width_minus_nozero(w, data, len, nbr);
	}
}

void	ft_width_nominus_zero(int w, t_flags *data, int len, int nbr)
{
	int	tmp;
//a verif pour sign
	if (data->sign != 0)
	{
		if (data->sign == 1)
			ft_putchar('-');
		else if (data->sign == 2)
			ft_putchar('+');
		w--;
		data->count++;
	}
	if (data->sign != 0)
		data->sign = 0;
	tmp = w - len;
	if (tmp > 0)
		data->count += tmp;
	while (tmp-- > 0)
		ft_putchar('0');
	if (nbr == 0)
		ft_special_argz_prec(len, data);
	else
		ft_treat_prec_i(len, nbr, data);
}

void	ft_width_nominus_nozero(int w, t_flags *data, int len, int nbr)
{
	int tmp;

	if (data->precision >= len && data->precision < data->width)
		tmp = w - data->precision;
	else
		tmp = w - len;
	data->count += tmp;
	if (data->sign != 0)
	{
		//if (tmp < 1) // plus nécessaire puisque quand w = len ce n'est pas ici
		//	data->count++;
		tmp--;
	}
	while (tmp-- > 0)
		ft_putchar(' ');
	if (data->sign == 1)
		ft_putchar('-');
	else if (data->sign == 2)
		ft_putchar('+');
	//if (data->sign != 0)
	//{
		data->sign = 0;
	//}
	if (nbr == 0)
		ft_special_argz_prec(len, data);
	else
		ft_treat_prec_i(len, nbr, data);
}
