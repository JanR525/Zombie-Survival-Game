#include <raylib.h>
#include "map.h"
#include "player.h"
#include "zombie.h"
#include <vector>

int main(){
    InitWindow(1024, 764, "TestWin");
    SetTargetFPS(60);

    Map map(400, 300, 16);
    map.Generate();
    map.makeRectangle(2, 3, 10, 14, TileType::Wall);
    map.makeRectangle(3, 4, 8, 12, TileType::Water);
    map.makeCircle(10, 15, 8, TileType::Wall);

    Player player({400, 400});
    std::vector<Zombie> zombies;

    zombies.emplace_back(Vector2{300, 400});
    zombies.emplace_back(Vector2{400, 500});

    while(WindowShouldClose() == false)
    {
        float dt = GetFrameTime();
        player.update(dt, map);
        for (auto& z : zombies)
            z.update(dt, player.position, zombies, map);

        BeginDrawing();
        
        map.Draw();
        player.draw();
        for(auto& z : zombies)
            z.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
