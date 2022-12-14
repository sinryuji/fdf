/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:32:21 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/26 20:33:43 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"
#include "../../lib/libft/include/libft.h"

static t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		put_error(ERR_MALLOC);
	map->width = 0;
	map->height = 0;
	map->z_arr = NULL;
	map->color_arr = NULL;
	map->gap = 0;
	map->x_move = 0;
	map->y_move = 0;
	return (map);
}

static void	get_map_data(t_map *map, t_data **data, char **split)
{
	int		i;
	char	**data_str;
	int		width;

	i = 0;
	width = 0;
	while (split[i] && split[i][0] != '\n')
	{
		data_str = ft_split(split[i], ',');
		if (!data_str)
			put_error(ERR_SPLIT);
		if (!data_str[1])
			push(data, ft_atoi(data_str[0]), 0x00FFFFFF);
		else
			push(data, ft_atoi(data_str[0]), ft_atoi_hex(data_str[1]));
		ft_split_free(data_str);
		width++;
		i++;
	}
	if (map->height != 0 && map->width != width)
		put_error(ERR_MAP_SIZE);
	map->width = width;
}

t_map	*read_map(int fd)
{
	char	*read;
	char	**split;
	t_map	*map;
	t_data	*data;

	map = init_map();
	read = get_next_line(fd);
	data = NULL;
	while (read)
	{
		split = ft_split(read, ' ');
		if (!split)
			put_error(ERR_SPLIT);
		get_map_data(map, &data, split);
		map->height++;
		free(read);
		ft_split_free(split);
		read = get_next_line(fd);
	}
	data_to_arr(map, data);
	map->gap = (double)HEIGHT / map->height / 3;
	if (HEIGHT / map->height / 3 > WIDTH / map->width / 3)
		map->gap = (double)WIDTH / map->width / 3;
	return (map);
}
