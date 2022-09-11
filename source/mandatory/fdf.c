/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:24:19 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/11 21:51:15 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	pixel_set(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

int	key_hook(int key_code, t_mlx *mlx)
{
	if (key_code == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_mlx	mlx;
	t_data	img;
	int		x;
	int		y;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(mlx.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = -1;
	while (++x < 500)
	{
		y = -1;
		while (++y < 500)
			pixel_set(&img, x, y, 0x00FF0000);
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_key_hook(mlx.win, key_hook, &mlx);
    mlx_loop(mlx.mlx);
	return (0);
}
