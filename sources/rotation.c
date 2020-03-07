

#include "fdf.h"

t_point		rotate_x(double angle, t_point dot)
{
	t_point d;

	d = dot;
	d.x = dot.x;
	d.y = dot.y * cos(angle) + dot.z * sin(angle);
	d.z = dot.z * cos(angle) - dot.y * sin(angle);
	return (d);
}

t_point		rotate_y(double angle, t_point dot)
{
	t_point d;

	d = dot;
	d.x = dot.x * cos(angle) + dot.z * sin(angle);
	d.z = -dot.x * sin(angle) + dot.z * cos(angle);
	return (d);
}
