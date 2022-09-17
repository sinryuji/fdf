/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:24:32 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/17 16:40:34 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "error.h"
# include <stdio.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;	
}	t_mlx;

typedef struct s_dot
{
	int				value;
	int				color;
}	t_dot;

typedef struct s_map
{
	int				width;
	int				height;
	struct s_dot	*map;
}	t_map;

/* map.c */
t_map	*read_map(char *file_addr);
void	map_free(t_map *map, int err_code);

/* mlx.c */
void	mlx_img_init(t_mlx *mlx, t_data *img);

#endif
