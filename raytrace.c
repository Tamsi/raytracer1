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

sfVector3f raytrace(sfVector2i screenSize, sfVector2i screenPos)
{
  sfVector3f direction;

  direction.x = screenSize.x;
  direction.y = (WIDTH / 2) - screenPos.x;
  direction.z = (HEIGHT / 2) - screenPos.y;
  return (direction);
}

float intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector, float radius)
{
  float a;
  float b;
  float c;
  float disc;
  float res;

  a = dir_vector.x * dir_vector.x + dir_vector.y * dir_vector.y + dir_vector.z * dir_vector.z;
  b = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y + eye_pos.z * dir_vector.z);
  c = eye_pos.x * eye_pos.x + eye_pos.y * eye_pos.y + eye_pos.z * eye_pos.z + radius * radius;
  disc = b * b + 4 * a * c;
  if (disc < 0)
    res = 0.0;
  else if (disc == 0)
    res = -b / (2 * a);
  else
    res = (-b + sqrtf(disc)) / (2 * a);
  printf("float = %f\n", res);
  return (res);
}

void raytrace_scene(t_my_framebuffer *framebuffer)
{
  float radius;
  float distance;
  sfVector3f eye_pos;
  sfVector3f direction;
  sfVector2i screenSize;
  sfVector2i screenPos;

  eye_pos.x = -200;
  eye_pos.y = 0;
  eye_pos.z = 0;
  radius = 50.0;

  screenSize.x = framebuffer->width;
  screenSize.y = framebuffer->height;

  screenPos.y = 0;
  while (screenPos.y < screenSize.y)
  {
    screenPos.x = 0;
    while (screenPos.x < screenSize.x)
    {
      direction = raytrace(screenSize, screenPos);
      distance = intersect_sphere(eye_pos, direction, radius);
      if (distance > 0.0)
        my_put_pixel(framebuffer, screenPos.x, screenPos.y, sfRed);
      screenPos.x++;
    }
    screenPos.y++;
  }
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

int main()
{
  sfVideoMode mode = {FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT, 32};
  sfRenderWindow *window;
  sfTexture *texture;
  sfSprite *sprite;
  t_my_framebuffer *framebuffer;

  window = sfRenderWindow_create(mode, "Ma fenetre Raytrace", sfResize | sfClose, NULL);
  if (!window)
    return (EXIT_FAILURE);
  texture = sfTexture_create(FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT);
  if (!texture)
    return (EXIT_FAILURE);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  framebuffer = create_pixel_buffer(FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT);
  process_game_loop(window, sprite);
  raytrace_scene(framebuffer);
  sfTexture_updateFromPixels(texture, framebuffer->pixels, framebuffer->width, framebuffer->height, 0, 0);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
  sfRenderWindow_destroy(window);
  return (EXIT_SUCCESS);
}