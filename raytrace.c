/*
** raytrace.c for  in /home/tbesson/projet_graph/raytracer1
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Wed Feb  8 16:24:24 2017 Tamsi Besson
** Last update Wed Feb  8 16:25:31 2017 Tamsi Besson
*/

#include "inc/my.h"

sfVector3f raytrace(sfVector2i screenSize, sfVector2i screenPos)
{
  sfVector3f direction
  direction.x = (WIDTH / 2) - screenPos.x;
  direction.y = (HEIGHT / 2) - screenPos.y;
  return (direction);
}

float intersectRaySphere(sfVector3f eye_pos, sfVector3f dir_vector, float radius)
{
	sfVector3f equation;
	float k;
	float disc;

	equation.x = (dir_vector.x * dir_vector.x) + (dir_vector.y * dir_vector.y) + (dir_vector.z * dir_vector.z);
	equation.y = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y + eye_pos.z * dir_vector.z);
	equation.z = (eye_pos.x * eye_pos.x) + (eye_pos.y * eye_pos.y) + (eye_pos.z * eye_pos.z) - (radius * radius);
	disc = (equation.y * equation.y) - 4 * equation.x * equation.y;
	if (disc < 0)
		return (0.0);
	else if (disc == 0)
		k = -(equation.y)/(2 * equation.x);
	else
		k = (-1 * equation.y + sqrtf(disc)) / (2 * equation.x);
	return (k);
}

int main(int ac, char **av)
{
	t_sphere sphere;
	sfVector3f eye;

	screenSize.x = WIDTH;
	screenSize.y = HEIGHT;
	sphere.pos.x = 0;
	sphere.pos.y = 0;
	sphere.pos.z = 0;
	sphere.radius = 50;

	eye.x = -200;
	eye.x = 0;
	eye.x = 0;
	intersectRaySphere(eye, sphere.pos, sphere.rayon);
	raytrace(screenSize, ...);
}