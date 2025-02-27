/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:24:38 by vicalons          #+#    #+#             */
/*   Updated: 2025/01/30 09:06:37 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

// Library varidic
# include <stdarg.h>

// Library libft
# include "libft.h"

# define HEX_UPP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"
# define DECIMAL "0123456789"

int		ft_printf(const char *str, ...);
size_t	ft_printspecial(const char c, va_list va);
size_t	ft_printchar(const int c);
size_t	ft_printstr(const char *str);
size_t	ft_printnbr(int nbr, const char *base, int len_base);
size_t	ft_printunsgn(unsigned long long nbr, const char *base, int len_base);
size_t	ft_printptr(void *ptr);

#endif
