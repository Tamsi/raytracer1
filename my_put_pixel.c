/*
** my_put_pixel.c for  in /home/tbesson/raytest/raycasting
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Tue Jan  3 14:42:33 2017 Tamsi Besson
** Last update Sat Jan 14 14:25:42 2017 Tamsi Besson
*/

#include "inc/my.h"

void    my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
	  framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
	  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
	  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
	  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
	}
}
