/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:45:11 by rmarni            #+#    #+#             */
/*   Updated: 2020/03/10 13:29:08 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_initial(const char *format)
{
	pf_struct.format = (char *)format;
	pf_struct.num_elen = 0;
	pf_struct.i = 0;
	pf_struct.g = 0;
	pf_struct.conv_mask = "cspdiouxXf%";
	pf_struct.flag_mask = "#+-0 ";
	pf_struct.mod_mask = "hlL";
	pf_struct.type_flag_extra = 'q';
	pf_struct.type_flag = 'q';
	pf_struct.flag_error = 0;
	pf_struct.spaces = 0;
	pf_struct.count_ou = 0;
	pf_struct.precision = -1;
	pf_struct.type_mod[0] = '0';
}
