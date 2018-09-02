#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "utils.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <allegro5/allegro_primitives.h>


typedef struct {
  float sx;
  float sy;
  float heading;
  float speed;
  int gone;
  ALLEGRO_COLOR color;
} Spaceship;

typedef struct{
  int x0, y0, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
} Spaceship_outline;

void draw_spaceship(Spaceship *a);
void turn_spaceship_left(Spaceship* a);
void turn_spaceship_right(Spaceship *a);
void increase_spaceship_speed(Spaceship *a);
void decrease_spaceship_speed(Spaceship *a);

#endif
