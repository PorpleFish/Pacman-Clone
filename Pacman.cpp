#include "GameInstance.h"

int main()
{
    GameInstance game = GameInstance();
    if (game.setup(false, false)) {
        game.run();
    }
    return 0;
}