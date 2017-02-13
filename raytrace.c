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
	float sphere;
	sfVector3f position;

	position.x = eye_pos.x + scal_vector(dir_vector.x, radius);
	position.y = eye_pos.y + scal_vector(dir_vector.y, radius);
	position.z = eye_pos.z + scal_vector(dir_vector.z, radius);
	sphere = sqrtf(position.x * position.x + position.y * position.y + position.z * position.z);
}