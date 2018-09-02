#include "asteroid.h"
#include "utils.h"
#include "spaceship.h"

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>


int main()
{
  bool done = false;
  bool draw = true;
  int FPS = 60;
  int state = -1;
  enum KEYS { UP, LEFT, RIGHT, DOWN, SPACE };
  bool keys[5] = { false, false, false, false, false };
  
  
  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
  ALLEGRO_TIMER* timer = NULL;
  
  if (!al_init())
  {
    fprintf(stderr, "failed to initialize allegro!\n");
    return -1;
  }

  display = al_create_display(screenWidth, screenHeight);

  if (!display)
  {
    fprintf(stderr, "failed to create display!\n");
    return -1;
  }

  al_install_keyboard();

  timer = al_create_timer(1.0 / FPS);
  event_queue = al_create_event_queue();

  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_display_event_source(display));

  al_start_timer(timer);
  
  Spaceship *a = malloc(sizeof(Spaceship));
  a->sx = screenWidth / 2.0;
  a->sy = screenHeight / 2.0;
  a->heading = 4;
  a->speed = 1;
  a->color = al_map_rgb(0, 255, 0);

   
  
  while (!done)
  {
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);

    if (ev.type == ALLEGRO_EVENT_TIMER)
    {
      draw = true;
      if (keys[DOWN])
        decrease_spaceship_speed(a);
      if (keys[UP])
        increase_spaceship_speed(a);
      if (keys[RIGHT])
        turn_spaceship_right(a);
      if (keys[LEFT])
        turn_spaceship_left(a);
    }

    else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
    {
      switch (ev.keyboard.keycode)
      {
      case ALLEGRO_KEY_DOWN:
        keys[DOWN] = true;
        break;
      case ALLEGRO_KEY_LEFT:
        keys[LEFT] = true;
        break;
      case ALLEGRO_KEY_RIGHT:
        keys[RIGHT] = true;
        break;
      case ALLEGRO_KEY_UP:
        keys[UP] = true;
        break;
      case ALLEGRO_KEY_ESCAPE:
        done = true;
        break;
      case ALLEGRO_KEY_SPACE:
        keys[SPACE] = true;
        break;
      }
    }
    else if (ev.type == ALLEGRO_EVENT_KEY_UP)
    {
      switch (ev.keyboard.keycode)
      {
      case ALLEGRO_KEY_DOWN:
        keys[DOWN] = false;
        break;
      case ALLEGRO_KEY_LEFT:
        keys[LEFT] = false;
        break;
      case ALLEGRO_KEY_RIGHT:
        keys[RIGHT] = false;
        break;
      case ALLEGRO_KEY_UP:
        keys[UP] = false;
        break;
      case ALLEGRO_KEY_SPACE:
        keys[SPACE] = false;
        break;
      }
    }
    else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
      done = true;
    }

    if (draw && al_is_event_queue_empty(event_queue))
    {
      draw = false;
      draw_asteroids();
      draw_spaceship(a);
      al_flip_display();
      al_clear_to_color(al_map_rgb(0, 0, 0));
    }
  }

  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
  al_destroy_timer(timer);


  return 0;

}                
