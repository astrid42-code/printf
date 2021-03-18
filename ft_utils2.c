/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:49:04 by asgaulti          #+#    #+#             */
/*   Updated: 2021/03/16 14:03:46 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrsize(int nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
	{
		count++;
		return (count);
	}
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int		ft_nbrsize_long(long nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
	{
		count++;
		return (count);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int		ft_nbrsize_u(unsigned long int nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
	{
		count++;
		return (count);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
