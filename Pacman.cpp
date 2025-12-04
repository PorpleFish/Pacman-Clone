#include "GameInstance.h"

int main()
{
    GameInstance game = GameInstance();
    if (game.setup(true, false)) {
        game.run();
    }
    return 0;
}