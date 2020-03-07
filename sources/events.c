
#include "fdf.h"

int		escape_handle(int key)
{
	if (key == kVK_Escape)
		exit(0);
	return (0);
}

void	projection(int key, t_mlx *win)
{
	static int	p;

	p = win->opt.axis;
	if (key == kVK_ANSI_A)
		p = -1;
	else if (key == kVK_ANSI_D)
		p = 1;
	win->opt.axis = p;
}
