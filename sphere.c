/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:17:44 by mobaz             #+#    #+#             */
/*   Updated: 2019/12/21 15:03:14 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

float	dot(int a[], int b[])
{
	float c;
	DOTVP(c, a, b);
	return (c);
}

int		ray_intersect(const int orig[], const int dir[], t_sphere sphere, int *t0)
{
	int L[3];
	float tca;
	float d2;
	float thc;
	float t1;

	SUBV(L, sphere.center, orig);
	DOTVP(tca, L, dir);
	d2 = dot(L, L) - tca*tca;
//	printf("L*L	:%f\nL*dir	:%f\n", dot(L, dir), tca*tca);
	if (d2 < 0)
		return (0);
	if (d2 > sphere.radius * sphere.radius)
		return (0);
	thc = sqrt(sphere.radius * sphere.radius - d2);
	*t0 = tca - thc;
	t1 = tca + thc;
	printf("L	:%d,%d,%d\ntca	:%f\nthc	:%f\nd2	:%f\nL*L	:%f", L[0], L[1], L[2], tca, thc, d2, dot(L, L));
	if (t0 < 0)
		*t0 = t1;
	if (*t0 < 0)
		return (0);
	return (1);
}

void	fill_window(void *mlx_ptr, void *win_ptr)
{
	int		j;
	int		i;

	i = 500;
	j = 500;
	while (j)
	{
		i = 500;
		while (i)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xADD8E6);
			i--;
		}
		j--;
	}
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int i;
	int j;

	i = 30;
	j = 30;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Sphere");
	//fill_window(mlx_ptr, win_ptr);
	t_sphere sphere;
	int dir[3] = {0, 0, 1};
	int orig[3] = {0, 0, 0};
	int t0;
	sphere.center[0] = 0;
	sphere.center[1] = 0;
	sphere.center[2] = 5;
	sphere.radius = 2;
	while (j)
	{
		i = 0;
		while (i)
		{
			dir[0] = i;
			dir[1] = j;
			dir[2] = i;
			if(ray_intersect(orig, dir, sphere, &t0))
				mlx_pixel_put(mlx_ptr, win_ptr, dir[i], dir[j], 200);
			//write(1, "INTERFUCKINGSECTION", 20);
			i++;	
		}
		j++;
	}
	printf("%d", t0);
	mlx_loop(mlx_ptr);
	return (0);
}
