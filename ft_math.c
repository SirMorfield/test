/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_math.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: joppe <joppe@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/15 21:16:11 by joppe         #+#    #+#                 */
/*   Updated: 2020/08/15 22:27:27 by joppe         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef float					float32_t;
typedef double					float64_t;
typedef long double				float80_t;

typedef signed char				int8_t;
typedef short int				int16_t;
typedef int						int32_t;
typedef long long int			int64_t;
#define int128_t  __int128_t

typedef unsigned char			uint8_t;
typedef unsigned short int		uint16_t;
typedef unsigned int			uint32_t;
typedef unsigned long long int	uint64_t;
#define uint128_t unsigned __int128_t

typedef enum { false, true }	bool;
#define true 1
#define false 0

typedef char					char
typedef void					void
#define NULL ((void *)0)
