#!/bin/bash
g++ -I. -Icore -Irender -Igame main.cpp core/map.cpp render/tileRender.cpp game/player.cpp game/entity.cpp game/zombie.cpp -o SpinutOfTheDead -lraylib -lGL -lm -lpthread -ldl -lrt -lX11