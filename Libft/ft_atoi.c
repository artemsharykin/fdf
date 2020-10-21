/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:39:18 by yalona           #+#    #+#             */
/*   Updated: 2019/12/06 17:12:03 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_result(size_t res, int sign, size_t count)
{
	if (count > 19)
		return (sign == -1 ? 0 : -1);
	if (res > 9223372036854775807)
		return (sign == -1 ? 0 : -1);
	return ((int)res * sign);
}

int			ft_atoi(const char *str)
{
	size_t					res;
	int						sign;
	size_t					count;

	res = 0;
	sign = 1;
	count = 0;
	if (!str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
		count++;
	}
	return (ft_get_result(res, sign, count));
}
