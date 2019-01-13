/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:05:00 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/08 15:07:07 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
#include <stdio.h>//!WARNING

typedef struct 				s_spec
{
	char					*flags;
	int						width;
	int						prec;
	char					size;
	char					type;
	void					*arg;
}							t_spec;

void						ft_printf(char const *format, ...);

int							spec_format(char const *check, va_list ap);
char						*search_border(char const *check);

char						*save_flags(char *str);
char						save_size(char *str);
int							save_width(char *str);
t_spec						*conf_create(t_spec *conf, char *str);
char						*read_conf(t_spec *conf, va_list ap);

char						*write_arg(int pos, t_spec *conf);
void						is_num(t_spec *conf,va_list ap);
void						is_str(t_spec *conf,va_list ap);
void						is_other_num(t_spec *conf,va_list ap);
// void						is_float(conf, *ap);
// void						if_adress(conf, *ap);

# endif
