#include "spaceship.h"

Spaceship_outline soutline = {-8,   9,
                               0, -11,
                               8,   9,
                              -6,   4,
                              -1,   4,
                               6,   4,
                               1,   4};


void draw_spaceship(Spaceship *a){

  float vx = a->speed * sin(radians_from_degree(a->heading));
  float vy = a->speed * cos(radians_from_degree(a->heading));
  
  // current location
  float sx = a->sx + vx ;
  float sy = a->sy - vy ;
  
  if (sx > screenWidth)
    sx = 0;
  if (sx < 0)
    sx = screenWidth;
  if (sy > screenHeight)
    sy = 0;
  if (sy < 0)
    sy = screenHeight;

  // also update current location
  a->sx = sx;
  a->sy = sy;
  
  ALLEGRO_TRANSFORM transform;
  al_identity_transform(&transform);
  al_rotate_transform(&transform, radians_from_degree(a->heading));
  al_translate_transform(&transform, sx, sy);
  al_use_transform(&transform);
  
  
  float x0 = soutline.x0;
  float y0 = soutline.y0;
  float x1 = soutline.x1;
  float y1 = soutline.y1;
  float x2 = soutline.x2;
  float y2 = soutline.y2;	
  float x3 = soutline.x3;
  float y3 = soutline.y3;
  float x4 = soutline.x4;
  float y4 = soutline.y4;
  float x5 = soutline.x5;
  float y5 = soutline.y5;
  float x6 = soutline.x6;
  float y6 = soutline.y6;

  al_draw_line(x0, y0, x1, y1, a->color, 2.0f);
  al_draw_line(x1, y1, x2, y2, a->color, 2.0f);
  al_draw_line(x3, y3, x4, y4, a->color, 2.0f);
  al_draw_line(x5, y5, x6, y6, a->color, 2.0f);

}

void turn_spaceship_left(Spaceship* a){
  if(a->heading == 0)
    a->heading = 360;
  a->heading -= 4;
}


void turn_spaceship_right(Spaceship *a){
  if (a->heading == 360)
    a->heading = 0;
  a->heading += 4;
}

void increase_spaceship_speed(Spaceship *a){
  a->speed = a->speed < 5.0 ? a->speed + 0.1 : 5.0;
}

void decrease_spaceship_speed(Spaceship *a){ 
  a->speed = a->speed > 0.5 ? a->speed - 0.1 : 0.5;
}
