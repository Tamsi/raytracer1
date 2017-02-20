/*
** my.h for   in /home/tbesson/raytest/raycasting
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Mon Jan  2 15:06:34 2017 Tamsi Besson
** Last update Sat Jan 14 15:17:04 2017 Tamsi Besson
*/

#ifndef MY_H
#define MY_H
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector3.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define HEIGHT 600
#define WIDTH 800
#define FRAMEBUFFER_HEIGHT 600
#define FRAMEBUFFER_WIDTH 800

typedef struct s_my_framebuffer
{
  sfUint8 *pixels;
  int width;
  int height;
}t_my_framebuffer;

typedef struct s_ray
{
	sfVector2f pos;
	sfVector2f direction;
}t_ray;

typedef struct s_sphere
{
	float rayon;
	sfVector3f pos;
}t_sphere;

typedef struct s_plan
{
	sfVector2f y;
	sfVector2f x;
}t_plan;

typedef struct s_box
{
	float arete;
	sfVector2f pos;
}t_box;

typedef struct s_cone
{
	sfVector2i height;
	sfVector2f pos;
	sfVector2i rayon_base;
}t_cone;

typedef struct s_cylinder
{
	sfVector2i height;
	sfVector2f pos;
	sfVector2i rayon_base;
}t_cylinder;

void	my_put_pixel(t_my_framebuffer *, int, int, sfColor);
sfVector3f raytrace (sfVector2i, sfVector2i);
#endif //MY_H
