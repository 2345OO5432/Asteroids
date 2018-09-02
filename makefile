gcc blasteroids.c asteroid.h asteroid.c -o game `pkg-config --libs allegro-5.0 allegro_primitives-5.0 allegro_color-5.0 allegro_image-5.0` -lm


gcc example1.c asteroid.h asteroid.c -o game `pkg-config --libs allegro-5.0 allegro_primitives-5.0 allegro_color-5.0 allegro_image-5.0` -lm
