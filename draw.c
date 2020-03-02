/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcohen <alcohen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:34:51 by alcohen           #+#    #+#             */
/*   Updated: 2020/03/02 17:20:09 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

double	scale(int in_range[2], double out_range[2])
{
	double	slope;

	slope = 1.0 * (out_range[1] - out_range[0]) / (in_range[1] - in_range[0]);
	return (slope);
}

static void		pixel_to_image(t_image *image, int x, int y, int color)
{
	image->image[x * 4 + y * image->size_line] = color;
	image->image[x * 4 + y * image->size_line + 1] = color;
	image->image[x * 4 + y * image->size_line + 2] = color;
}

void			handle_drawing(t_mlx *mlx)
{
	//if type == mandelbrot
	mandelbrot(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->image->img_ptr, 0, 0);
}

void	mandelbrot(t_mlx *mlx, int px, int py)
{
	double	xy_scaled[2];
	int		iter;
	double	x_temp;
	int		xy_loop[2];
	double	x;
	double	y;
	double	slope[2];
	int color = 0xFFFFFF;
	double x2;
	double y2;

	px += 0;
	py += 0;
	xy_loop[0] = 0;
	xy_loop[1] = 0;
	slope[0] = scale((int[2]){0, WINDOW_WIDTH}, (double[2]){-2, 1});
	slope[1] = scale((int[2]){0, WINDOW_HEIGHT}, (double[2]){-1, 1});
	while (xy_loop[0] < px)
	{
		xy_loop[1] = 0;
		// y loop
		while (xy_loop[1] < py)
		{
			x = 0.0;
			y = 0.0;
			// x loop
			xy_scaled[0] = mlx->zoom * -3 + slope[0] * (xy_loop[0] - 0);
			xy_scaled[1] = -1 + slope[1] * (xy_loop[1] - 0);
			//printf("%f, %f\n", xy_scaled[0], xy_scaled[1]);
			x2 = 0.0;
			y2 = 0.0;
			iter = 0;
			while (x*x + y*y <= 4 && iter < mlx->iter)
			{
				x_temp = (x*x - y*y + xy_scaled[0]) * mlx->zooming;
				y = (2*x*y + xy_scaled[1]) * mlx->zooming;
				x = x_temp;
				iter++;
			}
			if (iter == mlx->iter)
				color = 0;
			else
				color = (0x00F0F * iter);
			pixel_to_image(mlx->image, xy_loop[0], xy_loop[1], color);
			//mlx_pixel_put(mlx, mlx->window, xy_loop[0], xy_loop[1], color);
			xy_loop[1]++;
		}
		xy_loop[0]++;
	}
}
