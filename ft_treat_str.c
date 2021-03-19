/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:17:10 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/19 15:07:19 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_str(t_flags *data)
{
	int		len;
	int		prec;
	int		w;

	len = ft_strlen((char*)data->arg);
	w = 0;
	if (data->zero == 1)
		data->zero = 0;
	prec = ft_treat_prec_str(data, len);
	if (data->width != 0 && data->width >= prec)
		w = data->width - prec;
	ft_print_str(data, prec, w, len);
}

int		ft_treat_prec_str(t_flags *data, int len)
{
	int prec;

	prec = 0;
	if (data->precision > 0 && data->precision < len)
		prec = data->precision;
	else if (data->precision == 0)
		prec = 0;
	else
		prec = len;
	return (prec);
}

void	ft_print_str(t_flags *data, int prec, int w, int len)
{
	char	*tmp;
	int		i;

	tmp = (char*)data->arg;
	i = 0;
	if (w > 0 && data->minus == 0)
		ft_print_nominus_str(data, w, prec, len);
	else if (w > 0 && data->minus == 1)
		ft_print_minus_str(data, w, prec, len);
	else if (prec < len)
	{
		while (i < prec)
		{
			ft_putchar(tmp[i]);
			i++;
		}
		data->count += prec;
	}
	else
	{
		ft_putstr((char*)data->arg);
		data->count += ft_strlen((char*)data->arg);
	}
}

void	ft_print_nominus_str(t_flags *data, int w, int prec, int len)
{
	int		i;
	char	*tmp;

	tmp = (char*)data->arg;
	i = 0;
	while (i++ < w)
		ft_putchar(' ');
	data->count += w;
	i = 0;
	if (prec != 0 && prec < len)
	{
		while (i < prec)
		{
			ft_putchar(tmp[i]);
			i++;
		}
		data->count += prec;
	}
	else if (prec != 0)
	{
		ft_putstr((char*)data->arg);
		data->count += len;
	}
}

void	ft_print_minus_str(t_flags *data, int w, int prec, int len)
{
	int		i;
	char	*tmp;

	tmp = (char*)data->arg;
	i = 0;
	if (prec != 0 && prec < len)
	{
		while (i < prec)
			ft_putchar(tmp[i++]);
		data->count += prec;
	}
	else if (prec != 0)
	{
		ft_putstr((char*)data->arg);
		data->count += len;
	}
	i = 0;
	while (i++ < w)
		ft_putchar(' ');
	data->count += w;
}
