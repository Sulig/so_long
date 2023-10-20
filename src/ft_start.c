/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:25:03 by sadoming          #+#    #+#             */
/*   Updated: 2023/10/20 13:03:58 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_data	ft_new_window(t_map *map, t_objs obj)
{
	t_data	data;

	data.size = map->size * obj.img_y;
	data.len = map->len * obj.img_x;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.len, data.size, "Dungeons");
	data.wimg = mlx_new_image(data.mlx, data.len, data.size);
	data.adr = mlx_get_data_addr(data.wimg, &data.btpx, &data.ln, &data.end);
	return (data);
}

static void	ft_start_player(t_player *player)
{
	player->act.x = player->map->start.x;
	player->act.y = player->map->start.y;
	player->rem = player->map->coins;
	player->steps = 0;
	player->win = 0;
}
/*
static t_objs	ft_init_corners(t_data data, t_objs obj)
{
	char	*path;

	path = "./sprites/xpm/Walls/Up_Wall.xpm";
	obj.wl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Floor/Tile.xpm";
	obj.fl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Player/Triangle_Pl.xpm";
	obj.pl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Collect/Key_demo.xpm";
	obj.cl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Exit/Exit_v0.xpm";
	obj.ex = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Exit/PlayerinExit_v0.xpm";
	obj.ep = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Exit/Exit_v0.xpm";
	obj.wn = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	return (obj);
}
*/
static t_objs	ft_init_objs(t_data data, t_objs obj)
{
	char	*path;

	path = "./sprites/xpm/Walls/Up_Wall.xpm";
	obj.wu = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Floor/Tile.xpm";
	obj.fl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Player/Triangle_Pl.xpm";
	obj.pl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Collect/Key_demo.xpm";
	obj.cl = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Exit/Exit_v0.xpm";
	obj.ex = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Exit/PlayerinExit_v0.xpm";
	obj.ep = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	path = "./sprites/xpm/Exit/Exit_v0.xpm";
	obj.wn = mlx_xpm_file_to_image(data.mlx, path, &obj.img_x, &obj.img_y);
	return (obj);
}

void	ft_start(t_map *map)
{
	t_data		data;
	t_objs		objs;
	t_player	player;

	objs.img_x = 100;
	objs.img_y = 100;
	data = ft_new_window(map, objs);
	//objs = ft_init_cornners(data, objs);
	objs = ft_init_objs(data, objs);
	player.map = map;
	player.data = data;
	player.objs = objs;
	ft_start_player(&player);
	ft_style_map(&player);
	ft_update(player);
}
