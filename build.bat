@echo off
setlocal

g++ -I. -Icore -Irender -Igame -Iraylib\include ^
  main.cpp core\map.cpp render\tileRender.cpp ^
  game\player.cpp game\entity.cpp game\zombie.cpp ^
  -Lraylib\lib\windows ^
  -o SpinutOfTheDead.exe ^
  -lraylib -lopengl32 -lgdi32 -lwinmm

if %errorlevel% neq 0 (
  echo Build failed.
  exit /b %errorlevel%
)

echo Build successful.
