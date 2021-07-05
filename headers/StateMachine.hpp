#include "../src/PlayState.cpp"

class StateMachine
{
private:
    ALLEGRO_DISPLAY* display;
    PlayState actual;
public:
    StateMachine();
    ~StateMachine();
};
