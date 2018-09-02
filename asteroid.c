#include "asteroid.h"
#include "utils.h"

// 12 asteroids to begin with
#define ASTEROID_NUM 12

Outline outline = {-20, 20,
                   -25,  5,
                   -25,-10,
                    -5,-10,
                   -10,-20,
                     5,-20,
                    20,-10,
                    20, -5,
                     0,  0,
                    20, 10,
                    10,20,
                     0,15 };

typedef struct listnode {
  Asteroid* astPtr;
  struct listnode* next;
} AsteroidNode;

AsteroidNode* head = NULL;

void draw_asteroid(AsteroidNode *aNode){

  Asteroid* a = aNode->astPtr;

  float vx = a->speed * sin(radians_from_degree(a->heading));
  float vy = a->speed * cos(radians_from_degree(a->heading));
  
  // current location
  float sx = a->sx + vx >= (screenWidth) ? 0.0 : a->sx + vx;
  float sy = a->sy + vy >= (screenHeight) ? 0.0 : a->sy + vy;
  
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

  // current angel
  float sangel = a->twist + a->rot_velocity;
  a->twist = sangel;
  
  ALLEGRO_TRANSFORM transform;
  al_identity_transform(&transform);
  al_rotate_transform(&transform, radians_from_degree(sangel));
  al_translate_transform(&transform, sx, sy);
  al_use_transform(&transform);
  
  float x0 = outline.x0;
  float y0 = outline.y0;
  float x1 = outline.x1;
  float y1 = outline.y1;
  float x2 = outline.x2;
  float y2 = outline.y2;
  float x3 = outline.x3;
  float y3 = outline.y3;
  float x4 = outline.x4;
  float y4 = outline.y4;
  float x5 = outline.x5;
  float y5 = outline.y5;
  float x6 = outline.x6;
  float y6 = outline.y6;
  float x7 = outline.x7;
  float y7 = outline.y7;
  float x8 = outline.x8;
  float y8 = outline.y8;
  float x9 = outline.x9;
  float y9 = outline.y9;
  float x10 = outline.x10;
  float y10 = outline.y10;
  float x11 = outline.x11;
  float y11 = outline.y11;


  al_draw_line(x0, y0, x1, y1, a->color, 2.0f);
  al_draw_line(x1, y1, x2, y2, a->color, 2.0f);
  al_draw_line(x2, y2, x3, y3, a->color, 2.0f);
  al_draw_line(x3, y3, x4, y4, a->color, 2.0f);
  al_draw_line(x4, y4, x5, y5, a->color, 2.0f);
  al_draw_line(x5, y5, x6, y6, a->color, 2.0f);
  al_draw_line(x6, y6, x7, y7, a->color, 2.0f);
  al_draw_line(x7, y7, x8, y8, a->color, 2.0f);
  al_draw_line(x8, y8, x9, y9, a->color, 2.0f);
  al_draw_line(x9, y9, x10, y10, a->color, 2.0f);
  al_draw_line(x10, y10, x11, y11, a->color, 2.0f);
  al_draw_line(x11, y11, x0, y0, a->color, 2.0f);


}

void draw_asteroids(){
  if (head == NULL){
    init_asteroids();
  } else {

    AsteroidNode* cur;
    cur = head;
    for(cur = head; cur; cur = cur->next)
     draw_asteroid(cur);
  }
}

void init_asteroids(){

  srand((unsigned int)time(NULL));

  for(int i = 0; i < ASTEROID_NUM; i++){

    AsteroidNode *aNode = malloc(sizeof(AsteroidNode));
    aNode->astPtr = malloc(sizeof(Asteroid));

    // set random location & speed
    aNode->astPtr->sx = screenWidth * ((float)rand())/RAND_MAX;
    aNode->astPtr->sy = screenHeight * ((float)rand())/RAND_MAX;
    aNode->astPtr->heading = 360 * ((float)rand())/RAND_MAX;
    aNode->astPtr->twist = 360 * ((float)rand())/RAND_MAX;
    aNode->astPtr->speed = 3.0 * ((float)rand())/RAND_MAX;
    aNode->astPtr->rot_velocity = ((float)rand())/RAND_MAX;
    aNode->astPtr->scale = 4;
    aNode->astPtr->gone = 0;
    aNode->astPtr->color = al_map_rgb(255, 255, 255);
    aNode->next = NULL;

    if(head == NULL)
      head = aNode;
    else
    {
      aNode->next = head->next;
      head->next = aNode;
    }
  }
}
