#include "GameInstance.h"

int main()
{
    GameInstance game = GameInstance();
    if (game.setup(true, true)) {
        game.run();
    }
    return 0;
}