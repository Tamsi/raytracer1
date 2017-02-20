/*
** raytrace.c for  in /home/tbesson/projet_graph/raytracer1
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Wed Feb  8 16:24:24 2017 Tamsi Besson
** Last update Fri Feb 17 13:05:12 2017 Tamsi Besson
*/

#include "inc/my.h"

sfVector3f raytrace(sfVector2i screenSize, sfVector2i screenPos)
{
  sfVector3f direction;

  direction.y = (WIDTH / 2) - screenPos.x;
  direction.z = (HEIGHT / 2) - screenPos.y;
  return (direction);
}

float intersectRaySphere(sfVector3f eye_pos, sfVector3f dir_vector, float radius)
{
	sfVector3f equation;
	float k;
	float disc;

	equation.x = dir_vector.x * dir_vector.x + dir_vector.y * dir_vector.y + dir_vector.z * dir_vector.z;
	equation.y = 2 * eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y + eye_pos.z * dir_vector.z;
	equation.z = eye_pos.x * eye_pos.x + eye_pos.y * eye_pos.y + eye_pos.z * eye_pos.z - radius * radius;
	disc = equation.y * equation.y - 4 * equation.x * equation.y;
	if (disc < 0)
		return (0.0);
	else if (disc == 0)
		k = -(equation.y)/(2 * equation.x);
	else
  {
    if ((-1 * equation.y + sqrtf(disc)) / (2 * equation.x) 
      < (-1 * equation.y - sqrtf(disc)) / (2 * equation.x))
		  k = (-1 * equation.y + sqrtf(disc)) / (2 * equation.x);
    else
      k = (-1 * equation.y - sqrtf(disc)) / (2 * equation.x);
  }
	return (k);
}

t_my_framebuffer *create_pixel_buffer(int width, int height)
{
  int i;
  sfUint8* pixels;
  t_my_framebuffer *pixelbuffer;

  pixels = malloc(width * height * 4 * sizeof(*pixels));
  pixelbuffer = malloc(width * height * 4 * sizeof(*pixelbuffer));
  if (pixels == NULL)
    exit(EXIT_FAILURE);
  i = 0;
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i = i + 1;
    }
  pixelbuffer->pixels = pixels;
  pixelbuffer->height = height;
  pixelbuffer->width = width;
  return (pixelbuffer);
}

int process_game_loop(sfRenderWindow *window, sfSprite *sprite)
{
  sfEvent event;

  while (sfRenderWindow_isOpen(window))
  {
    while (sfRenderWindow_pollEvent(window, &event))
    {
  	  if (event.type == sfEvtClosed)
  	    sfRenderWindow_close(window);
    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
  }
}

void raytrace_scene(t_my_framebuffer *framebuffer)
{
  t_sphere sphere;
  sfVector3f eye;
  sfVector3f direction;
  sfVector2i screenSize;
  sfVector2i screenPos;

  sphere.pos.x = 0;
  sphere.pos.y = 0;
  sphere.pos.z = 0;
  sphere.rayon = 50.0;
  eye.x = 0;
  eye.y = 0;
  eye.z = -200;

  screenPos.y = 0;
  while (screenPos.y < WIDTH)
  {
    screenPos.x = 0;
    while (screenPos.x < HEIGHT)
    {
      direction = raytrace(screenSize, screenPos);
      if (intersectRaySphere(eye, direction, sphere.rayon) != 0)
        my_put_pixel(framebuffer, screenPos.x, screenPos.y, sfRed);
      screenPos.x++;
    }
    screenPos.y++;
  }
}

int main()
{
  sfVideoMode mode = {FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT, 32};
  sfRenderWindow *window;
  sfTexture *texture;
  sfSprite *sprite;
  t_my_framebuffer *framebuffer;

  window = sfRenderWindow_create(mode, "Bootstrap Raytracer 1",
         sfResize | sfClose, NULL);
  framebuffer = create_pixel_buffer(FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT);
  if (!window)
    return (EXIT_FAILURE);
  texture = sfTexture_create(FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT);
  if (!texture)
    return (EXIT_FAILURE);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  raytrace_scene(framebuffer);
  sfTexture_updateFromPixels(texture, framebuffer->pixels,
           framebuffer->width, framebuffer->height,
           0,0);
  process_game_loop(window, sprite);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
  sfRenderWindow_destroy(window);
  return (EXIT_SUCCESS);
}