/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_w.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <kvignau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:44:58 by kvignau           #+#    #+#             */
/*   Updated: 2016/02/09 11:26:40 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_nbrlen_w(wchar_t n, size_t base)
{
	size_t		i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static void		ft_base_w(size_t len, char **str, size_t base,
		wchar_t nb)
{
	while (nb != 0)
	{
		len--;
		if (base >= 10 && nb % base >= 10)
		{
			(*str)[len] = (nb % base) + 87;
		}
		else
		{
			(*str)[len] = (nb % base) + 48;
		}
		nb = nb / base;
	}
}

char			*ft_itoa_base_w(wchar_t n, size_t base)
{
	char		*str;
	size_t		len;

	len = ft_nbrlen_w(n, base);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (base == 10 && n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len] = '\0';
	if (n == 0)
		str[--len] = '0';
	else
	{
		ft_base_w(len, &str, base, n);
	}
	return (str);
}
