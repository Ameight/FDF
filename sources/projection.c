
#include "fdf.h"


t_point		draw_dots_isometric(t_mlx win, t_point dot)
{
	float		x;
	float		y;
	const int	zoom = win.scale;
	t_point		res;

	if (win.opt.bit)
	{
		dot.x = (int)(dot.x - win.map.x / 2) << zoom;
		dot.y = (int)(dot.y - win.map.y / 2) << zoom;
		dot.z = (int)dot.z << zoom;
	}
	else
	{
		dot.x = (dot.x - win.map.x / 2) * zoom;
		dot.y = (dot.y - win.map.y / 2) * zoom;
		dot.z *= zoom;
	}
	dot = rotate_x(win.rotx, dot);
	dot = rotate_y(win.roty, dot);
	x = win.mid[X] + (dot.x - dot.y) * cos(PI / 6) + win.opt.left_right;
	y = win.mid[Y] - dot.z + (dot.x + dot.y) * cos(PI / 3) - win.opt.up_down;
	res = set_dot_c(x, y, dot.hue.hex_color);
	return (res);
}

t_point		draw_dots_parallel(t_mlx win, t_point dot)
{
	float		x;
	float		y;
	const int	zoom = win.scale;
	t_point		res;

	if (win.opt.bit)
	{
		dot.x = (int)(dot.x - win.map.x / 2) << zoom;
		dot.y = (int)(dot.y - win.map.y / 2) << zoom;
		dot.z = (int)dot.z << zoom;
	}
	else
	{
		dot.x = (dot.x - win.map.x / 2) * zoom;
		dot.y = (dot.y - win.map.y / 2) * zoom;
		dot.z *= zoom;
	}
	dot = rotate_x(win.rotx, dot);
	dot = rotate_y(win.roty, dot);
	x = win.mid[X] + dot.x + win.opt.left_right;
	y = win.mid[Y] + dot.y - win.opt.up_down;
	res = set_dot_c(x, y, dot.hue.hex_color);
	return (res);
}
