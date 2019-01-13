/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:23:56 by tdontos-          #+#    #+#             */
/*   Updated: 2019/01/08 12:33:26 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(char const *format, ...)
{
	va_list ap;
	int i;

	i = -1;
	if (format == NULL)
		return ;
	va_start(ap, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
			spec_format(&format[i + 1], ap);
	}
	va_end(ap);
}

int main (void)
{
	ft_printf("%c\n%d\n%x\n%X\n%s", 'c', 123123123123, 123, 123, "qwertyuio");
	printf("%c\n%ld\n%x\n%X\n%s", 'c', 123123123123, 123, 123, "qwertyuio");
	return (0);
}