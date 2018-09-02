#ifndef ASTEROID_H
#define ASTEROID_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
  float sx;
  float sy;
  float heading;
  float twist;
  float speed;
  float rot_velocity;
  float scale;
  int gone;
  ALLEGRO_COLOR color;
} Asteroid;

typedef struct{
  float x0, y0, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7;
  float x8, y8, x9, y9, x10, y10, x11, y11;
} Outline;

void init_asteroids();
void draw_asteroids();

#endif
