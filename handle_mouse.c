/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcohen <alcohen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:03:34 by alcohen           #+#    #+#             */
/*   Updated: 2020/03/02 17:14:23 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_event(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (button == 4)
	{
		if (mlx->zooming > 0)
			mlx->zooming -= 0.01;
	}
	if (button == 5)
	{
		mlx->zooming += 0.01;
	}
	handle_drawing(mlx);
	// if (button == 1)
	// {
	// 	mlx->mouse_x = x;
	// 	mlx->mouse_y = y;
	// 	mlx->mouse_pressed = 1;
	// 	mlx_clear_window(mlx->init, mlx->window);
	// 	draw_map(mlx, mlx->s_map);
	// }
	return (0);
}

// int				mouse_release(int button, int x, int y, void *param)
// {
// 	t_mlx	*mlx;

// 	(void)button;
// 	(void)x;
// 	(void)y;
// 	mlx = param;
// 	mlx->mouse_pressed = 0;
// 	mlx_clear_window(mlx->init, mlx->window);
// 	draw_map(mlx, mlx->s_map);
// 	return (0);
// }

// int				mouse_move(int x, int y, void *param)
// {
// 	t_mlx	*mlx;

// 	mlx = param;
// 	if (mlx->mouse_pressed)
// 	{
// 		mlx->x_offset += x - mlx->mouse_x;
// 		mlx->y_offset += y - mlx->mouse_y;
// 	}
// 	mlx->mouse_x = x;
// 	mlx->mouse_y = y;
// 	mlx_clear_window(mlx->init, mlx->window);
// 	draw_map(mlx, mlx->s_map);
// 	return (0);
// }
