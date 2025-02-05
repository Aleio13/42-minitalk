/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:49:23 by almatsch          #+#    #+#             */
/*   Updated: 2024/10/25 02:58:46 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "unistd.h"
# include "stdlib.h"
# include "stdarg.h"
# include "stdio.h"

void	ft_putchar_count(char c, int *count);
void	ft_putnbr_count(int n, int *count);
void	ft_putstr_count(char *str, int *count);
void	ft_putunbr_count(unsigned int n, int *count);
void	ft_puthex_count(size_t n, int *count, char *base);
int		ft_printf(const char *format, ...);

#endif
