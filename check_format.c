/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:02:58 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/08 15:03:45 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		spec_format(char const *check, va_list ap)
{
	t_spec 	*conf;
	char	*tmp;

	if ((tmp = search_border(check)) == NULL)
		return (0);
	conf = conf_create(conf, tmp);
	read_conf(conf, ap);
	return (0);
}

char	*search_border(char const *check)
{
	char	*tmp;
	char	*end;
	int		i;
	int		j;

	j = 0;
	i = 0;
	end = "dioucsSxXeEgGaApfFn";
	while (check[j] != '\0')
	{
		if (check[j] == '%')
			return ((tmp = "%"));
		while (end[i] != '\0')
		{
			if (check[j] == end[i++])
			{
				tmp = ft_strnew(0);
				tmp = ft_strncpy(tmp, check, ++j);
				return (tmp);
			}
		}
		i = 0;
		j++;
	}
	return (NULL);
}

char	*read_conf(t_spec *conf, va_list ap)
{
	char	*spec;
	int		pos;

	spec = "dioucsSxXeEgGaApfFn";
	pos = ft_strchr(spec, conf->type) - spec + 1;
	if (pos <= 5)
		is_num(conf, ap);
	else if (pos <= 10)
		is_str(conf, ap);
	return (write_arg(pos, conf));
	// else if (pos <= 16)
		// is_other_num(pos, conf, ap);
	// else if (pos <= 18)
		// is_float(conf, ap);
	// else if (pos == 19)
		// if_adress(conf, ap);
}

char	*write_arg(int pos, t_spec *conf)
{
	char	*str;
	int		i;

	if (pos <= 4)
		str = ft_itoa((int)conf->arg);
	else if (conf->type == 'c')
	{
		printf("%c\n",conf->type );
		return ("qwe");
	}
	else
		str = conf->arg;
		printf("%s\n",str );
	return (str);
}