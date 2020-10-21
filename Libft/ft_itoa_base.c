/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 00:13:33 by yalona           #+#    #+#             */
/*   Updated: 2019/09/17 13:42:07 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_base_print(int n)
{
	int		i;
	char	*hex;

	if (!(hex = (char *)malloc(sizeof(char) * 17)))
		return (0);
	hex = "0123456789abcdef";
	i = 0;
	while (hex[i] != '\0')
	{
		if (i == n)
			return (hex[i]);
		i++;
	}
	return (0);
}

static char	*ft_fill_result(int sign, int i, int n, int base)
{
	char *result;

	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i] = '\0';
	while (i >= 1)
	{
		result[i - 1] = ft_base_print((n % base) * sign);
		n = n / base;
		i--;
	}
	if (sign == -1 && base == 10)
		result[i] = '-';
	return (result);
}

char		*ft_itoa_base(int n, int base)
{
	char	*result;
	int		i;
	int		a;
	int		sign;

	i = 1;
	sign = 1;
	if (n < 0)
	{
		if (base == 10)
			i++;
		sign = -1;
	}
	a = n;
	while (a / base >= 1 || a / base <= -1)
	{
		i++;
		a = a / base;
	}
	result = ft_fill_result(sign, i, n, base);
	return (result);
}
