#include <iostream>
#include <memory>
#include "geventhandler.cpp"
#include "prephase.cpp"
#include "helper.cpp"
#include "visual.cpp"
#include "logic.cpp"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/system.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>


using namespace std;


int main() {


std::unique_ptr<int> v3 = std::make_unique<int>(5);

WorldObject world;

if(!al_init())
    {  print_error("init error");  }

    if(!al_install_keyboard())
    {  print_error("keyboard error");  }

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    if(!timer)
    {  print_error("timer error");  }

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    if(!queue)
    {  print_error("queue error");  }

    ALLEGRO_DISPLAY* disp = al_create_display(640, 480);
    if(!disp)
    {  print_error("display error");  }

    ALLEGRO_FONT* font = al_create_builtin_font();
    if(!font)
    {  print_error("font error");  }

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

	al_start_timer(timer);
    while(1)
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                // game logic goes here.
                redraw = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");
			al_draw_filled_rectangle(50.0,50.0, 150.0, 150.0, al_map_rgb(150,200,150));
            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

cout << "END" << endl;
	return 0;
}
