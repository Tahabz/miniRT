#include <stdio.h>
#include "mlx.h"
#include  <unistd.h>
#include <math.h>
#include <stdlib.h>

void	draw_circle();
void	ft_putnbr(int n);
void	drc(int x0, int y0, int radius, void *mlx_ptr, void *win_ptr);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	drc(int x0, int y0, int radius, void *mlx_ptr, void *win_ptr)
{
	int x = radius;
	int y = 0;
	int err = 0;
	while (radius)
	{
		while (x >= y)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x0 + x, y0 + y, 125200);
			mlx_pixel_put(mlx_ptr, win_ptr, x0 + y, y0 + x, 125200);
			mlx_pixel_put(mlx_ptr, win_ptr, x0 - y, y0 + x, 125200);
			mlx_pixel_put(mlx_ptr, win_ptr, x0 - x, y0 + y, 125200);
			mlx_pixel_put(mlx_ptr, win_ptr, x0 - x, y0 - y, 125200);
			mlx_pixel_put(mlx_ptr, win_ptr, x0 - y, y0 - x, 125200);
			mlx_pixel_put(mlx_ptr, win_ptr, x0 + y, y0 - x, 125200);
			mlx_pixel_put(mlx_ptr, win_ptr, x0 + x, y0 - y, 125200);
			printf("(1, HELO, 4)");
			if (err <= 0)
			{
				y += 1;
				err += 2*y + 1;
			}

			if (err > 0)
			{
				x -= 1;
				err -= 2*x + 1;
			}
		}
		err = 0;
		radius--;
		x = radius;
		y = 0;
	}
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;
	int		x;
	int		y;
	int		r;
	int		j;

	j = 0;
	r = 20;
	y = 300;
	i = 0;
	x = 150;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Hello World");
	/*	while (i < r*2)
		{
		while (j < r*2)
		{
		double distance = sqrt((double)(i-r)*(i-r) + (j-r)*(j-r));
		if (distance>r-0.5 && distance<r+0.5)
		{
		write(1, "h", 1);
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 200);
		}
		else
		x++;
		j++;
		}
		y++;
		i++;
		}*/
	drc(500, 500, 300, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}


void	draw_circle()
{
	int loc[2];
	int radius;
	int center;
	int	i;
	int	j;
	int x;
	int y;
	void	*mlx_ptr;
	void	*win_ptr;
	int a = 20;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Circle");
	i = 0;
	radius = 50;
	center = 225;
	loc[1] = radius + center;
	while (i < radius*2)
	{
		loc[0] = center - radius;
		j = 0;
		while (j < radius*2)
		{
			if ((loc[0] - center)*(loc[0] - center) + (loc[1] - center)*(loc[1] - center) == (center - radius)*(center - radius))
			{
				if (a)
				{ft_putnbr(loc[0]);
					ft_putchar('\n');
					ft_putnbr(loc[1]);
					ft_putchar('\n');
					a--;
				}mlx_pixel_put(mlx_ptr, win_ptr, loc[0], loc[1], 200);
			}
			loc[0] = loc[0] + 1;
			j++;
		}
		loc[1] = loc[1] + 1;
		i++;
	}
	mlx_loop(mlx_ptr);
}
