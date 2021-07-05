#include "../headers/StateMachine.hpp"

StateMachine::StateMachine()
{
    al_init();
    al_install_keyboard();
    display = al_create_display(320, 200);
    actual = PlayState();
    actual.run(display);
}

StateMachine::~StateMachine()
{
    al_destroy_display(display);
}
