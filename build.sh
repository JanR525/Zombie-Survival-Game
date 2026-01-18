#!/bin/bash
set -e

g++ -I. -Icore -Irender -Igame -Iraylib/include main.cpp core/map.cpp render/tileRender.cpp game/player.cpp game/entity.cpp game/zombie.cpp -o SpinutOfTheDead -Lraylib/lib/linux -lraylib -lGL -lm -lpthread -ldl -lrt -lX11