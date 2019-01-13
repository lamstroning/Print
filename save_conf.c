/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:24:50 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/10 19:25:52 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec	*conf_create(t_spec *conf, char *str)
{
	int		len;

	if (!(conf = malloc(sizeof(t_spec))))
		exit(1);
	len = ft_strlen(str) - 1;
	conf->flags = save_flags(str);
	conf->width = save_width(str);
	conf->size = save_size(str);
	conf->type = str[len];
	if ((str = ft_strrchr(str, '.')) == NULL)
		conf->prec = 0;
	else
		conf->prec = ft_atoi(++str);
	return (conf);
}

char	*save_flags(char *str)
{
	int		i;
	int		j;
	char	*flags;

	flags = (char*)malloc(sizeof(char) * 6);
	j = -1;
	i = 0;
	while (str[++j])
	{
		if (str[j] == '-' || str[j] == '+' || str[j] == ' ' || str[j] == '#')
		{
			if (ft_strchr(flags, str[j]) == NULL)
				flags[i++] = str[j];
		}
		 if (str[j] == '0' && (!ft_isdigit(str[j - 1]) && str[j - 1] != '.'))
		{
			if (ft_strchr(flags, '0') == NULL)
				flags[i++] = str[j];
		}
	}
	if (flags == NULL)
		free(flags);
	flags[i] = '\0';
	return (flags);
}

int		save_width(char *str)
{
	int		width;
	int		i;

	i = 0;
	width = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			while (ft_isdigit(str[++i]));
		else if (ft_isdigit(str[i]) && !ft_isdigit(str[i - 1]))
			width = ft_atoi(&str[i]);
		i++;
	}
	return (width);
}

char	save_size(char *str)
{
	int		i;
	char	sym;


	sym = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == 'l' && str[i - 1] == 'l')
			sym = 'w';
		else if (str[i] == 'h' && str[i - 1] == 'h')
			sym = 'H';
		else if (str[i] == 'l' || str[i] == 'h' || str[i] == 'j' ||
			str[i] == 'z' || str[i] == 't' || str[i] == 'L')
			sym = str[i];
	}
	return (sym);
}
