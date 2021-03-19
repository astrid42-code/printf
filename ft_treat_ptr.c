/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:16:28 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/19 14:31:53 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_ptr(t_flags *data)
{
	unsigned long long		ptr;
	int						tmp;
	int						len;

	ptr = (unsigned long long)data->arg;
	len = ft_itoasize_ptr(ptr) + 2;
	if (data->width >= len)
	{
		tmp = data->width - len;
		if (data->precision == 0 && data->minus != 1 && ptr == 0)
			tmp++;
		if (data->minus == 0)
			ft_treat_minus_ptr(tmp, data, ptr);
		else if (data->minus == 1)
			ft_treat_nominus_ptr(tmp, data, ptr);
	}
	else
		ft_nowidth_ptr(ptr, data, len);
}

void	ft_treat_minus_ptr(int tmp, t_flags *data,
							unsigned long long ptr)
{
	while (tmp-- > 0)
		ft_putchar(' ');
	write(1, "0x", 2);
	if (ptr == 0)
	{
		if (data->precision != 0)
			ft_putchar('0');
		else if (data->precision == 0)
			tmp++;
	}
	else
		ft_convert_hexa_ptr(data, ptr);
	data->count += data->width;
}

void	ft_treat_nominus_ptr(int tmp, t_flags *data,
							unsigned long long ptr)
{
	write(1, "0x", 2);
	if (ptr == 0)
	{
		if (data->precision != 0)
			ft_putchar('0');
		else if (data->precision == 0)
			tmp++;
	}
	else
		ft_convert_hexa_ptr(data, ptr);
	while (tmp-- > 0)
		ft_putchar(' ');
	data->count += data->width;
}

void	ft_nowidth_ptr(unsigned long long ptr, t_flags *data, int len)
{
	write(1, "0x", 2);
	if (ptr == 0)
	{
		data->count += 2;
		if (data->precision != 0)
		{
			ft_putchar('0');
			data->count++;
		}
	}
	else
	{
		ft_convert_hexa_ptr(data, ptr);
		data->count += len;
	}
}
