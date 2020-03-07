
#include "fdf.h"

#define DEFAULT_ROTATION 0.1

int		key(int key)
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
//	else if (key == kVK_ANSI_S)
//		p = 0;
	else if (key == kVK_ANSI_D)
		p = 1;
	else if (key == kVK_ANSI_Keypad0)
		p++;
	if (p >= 1)
		p = -1;
	win->opt.axis = p;
}

//void	coloring(int key, t_mlx *win)
//{
//	if (key == kVK_ANSI_L)
//		win->opt.grad = (!win->opt.grad) ? (1) : (0);
//	else if (key == kVK_ANSI_M && win->opt.grad)
//	{
//		win->opt.grad++;
//		if (win->opt.grad > 3)
//			win->opt.grad = 1;
//		if (win->opt.grad == 1)
//		{
//			win->low.hex_color = RED;
//			win->high.hex_color = WHITE;
//		}
//		else if (win->opt.grad == 2)
//		{
//			win->low.hex_color = BLUE;
//			win->high.hex_color = RED;
//		}
//		else if (win->opt.grad == 3)
//		{
//			win->low.hex_color = BLUE;
//			win->high.hex_color = 0xFFA500;
//		}
//	}
//}

void	rotate(int key, t_mlx *win)
{
	if (key == kVK_ANSI_Keypad5)
	{
		win->rotx = 0;
		win->roty = 0;
//		win->rotz = 0;
	}
}

void	color(int key, t_mlx *win)
{
	if (key == kVK_ANSI_H)
		win->opt.color = !win->opt.color ? 1 : 0;
	else if (key == kVK_ANSI_N && win->opt.color)
	{
		win->opt.color++;
		if (win->opt.color > 2)
			win->opt.color = 1;
		else if (win->opt.color == 1)
			win->opt.hue.hex_color = RED;
		else if (win->opt.color == 2)
			win->opt.hue.hex_color = GREEN;
		else if (win->opt.color == 3)
			win->opt.hue.hex_color = BLUE;
		else if (win->opt.color == 4)
			win->opt.hue.hex_color = LIME;
		else if (win->opt.color == 5)
			win->opt.hue.hex_color = YELLOW;
		else if (win->opt.color == 6)
			win->opt.hue.hex_color = GRAY;
		else if (win->opt.color == 7)
			win->opt.hue.hex_color = SILVER;
		else if (win->opt.color == 8)
			win->opt.hue.hex_color = PURPLE;
	}
}
