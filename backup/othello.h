#include <stdio.h>

#define MAP_SIZE_X 8
#define MAP_SIZE_Y 8

#define NO_DATE 0
#define BLACK 1
#define WHITE 2

#include "reversed.h"
#include "ai.h"

void init_map(int map[][MAP_SIZE_Y]);
void draw_map(int map[][MAP_SIZE_Y]);
void put(int ,int map[][MAP_SIZE_Y]);
int change(int, int, int, int map[][MAP_SIZE_Y]);
