
#include "fdf.h"


t_point		draw_dots_isometric(t_mlx win, t_point dot)
{
	float		x;
	float		y;
	const int	zoom = win.scale;
	t_point		res;

	dot.x = (dot.x - win.map.x / 2) * zoom;
	dot.y = (dot.y - win.map.y / 2) * zoom;

	x = win.mid[X] + (dot.x - dot.y) * cos(PI / 6);
	y = win.mid[Y] - dot.z + (dot.x + dot.y) * cos(PI / 3);
	res = set_dot_c(x, y, dot.hue.hex_color);
	return (res);
}

t_point		draw_dots_parallel(t_mlx win, t_point dot)
{
	float		x;
	float		y;
	const int	zoom = win.scale;
	t_point		res;

	dot.x = (dot.x - win.map.x / 2) * zoom;
	dot.y = (dot.y - win.map.y / 2) * zoom;

	x = win.mid[X] + dot.x;
	y = win.mid[Y] + dot.y;
	res = set_dot_c(x, y, dot.hue.hex_color);
	return (res);
}
