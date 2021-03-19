/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:21:48 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/19 11:26:44 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_convert_hexa(t_flags *data, unsigned int nbr)
{
	int		tmp;
	char	*base1;
	char	*base2;

	base1 = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	tmp = (nbr - (nbr / 16) * 16);
	if (nbr >= 16 && data->type == 'x')
	{
		ft_convert_hexa(data, nbr / 16);
		ft_putchar(base1[tmp]);
	}
	if (nbr >= 16 && data->type == 'X')
	{
		ft_convert_hexa(data, nbr / 16);
		ft_putchar(base2[tmp]);
	}
	if (nbr < 16 && data->type == 'x')
		ft_putchar(base1[tmp]);
	if (nbr < 16 && data->type == 'X')
		ft_putchar(base2[tmp]);
}

int			ft_itoasize(unsigned int nbr)
{
	int i;

	i = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

void		ft_convert_hexa_ptr(t_flags *data,
							unsigned long long nbr)
{
	int		tmp;
	char	*base1;
	char	*base2;

	base1 = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	tmp = (nbr - (nbr / 16) * 16);
	if (nbr >= 16 && data->type == 'p')
	{
		ft_convert_hexa_ptr(data, nbr / 16);
		ft_putchar(base1[tmp]);
	}
	if (nbr < 16 && data->type == 'p')
		ft_putchar(base1[tmp]);
}

int			ft_itoasize_ptr(unsigned long long nbr)
{
	int i;

	i = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}
