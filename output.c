/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confput.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:59:52 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/11 16:59:53 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_num(t_spec *conf, va_list ap)
{
	if (conf->type == 'D')
		conf->arg = va_arg(ap, long long unsigned int*);
	if (conf->type == 'u')
	{
		if (conf->size == 0)
			conf->arg = va_arg(ap, unsigned int*);
		if (conf->size == 'l')
			conf->arg = va_arg(ap, long unsigned int*);
		if (conf->size == 'w')
			conf->arg = va_arg(ap, long long unsigned int*);
	}
	if (conf->type == 'd' || conf->type == 'i' || conf->type == 'c')
	{
		if (conf->size == 0)
			conf->arg = va_arg(ap, int*);
		if (conf->size == 'l')
			conf->arg = va_arg(ap, long int*);
		if (conf->size == 'w')
			conf->arg = va_arg(ap, long long int*);
	}
}

void	is_str(t_spec *conf,va_list ap)
{
	if (conf->type == 's')
			conf->arg = va_arg(ap, char *);
	if (conf->type == 'c')
			conf->arg = va_arg(ap, int*);
	if (conf->type == 'x' || conf->type == 'X')
		conf->arg = ft_hex(va_arg(ap, unsigned long long int), conf->type - 'X');
		return ;
 }

void	is_other_num(t_spec *conf,va_list ap)
{
	if (conf->type == 'o')
			conf->arg = va_arg(ap, char *);
	return ;
}

// void	is_float(va_list ap)
// {
// 	float	fnum;

// 	fnum = va_arg(ap, float);
// 	return (fnum);
// }

// void	*if_adress(conf, ap)
// {
// 	void	adress;

// 	return (adress);
// }
