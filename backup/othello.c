#ifndef FOO_H
#define FOO_H

#include"othello.h"

#endif
int main(void){
	int map[MAP_SIZE_X][MAP_SIZE_Y];

	int turn=0;
	init_map(map);
	for(turn=0; turn<60;turn++){
		draw_map(map);
		put(turn%2+1,map);
	}

	return 0;
}

//マップの初期化
void init_map(int map[][MAP_SIZE_Y]){
	int i,j;
	for(i=0; i<MAP_SIZE_Y; i++){
		for(j=0; j<MAP_SIZE_X; j++){
			map[j][i] = 0;
		}
	}
	map[3][4] = map[4][3] = BLACK;
	map[3][3] = map[4][4] = WHITE;
}

//マップの表示
void draw_map(int map[][MAP_SIZE_Y]){
	int i,j;
	puts("  0 1 2 3 4 5 6 7");
	for(i=0; i<MAP_SIZE_Y; i++){
		printf("%d",i);
		for(j=0; j<MAP_SIZE_X; j++){
			printf("%2d",map[j][i]);
		}
		putchar('\n');
	}
}

//コマをおく場所
//もともと置かれていたらもう一度
void put(int color, int map[][MAP_SIZE_Y]){
	int x,y;
	do{
		printf("x,y :");
		scanf("%d,%d",&x,&y);
	}while(map[x][y] != 0 || change(x, y, color, map) == 0);


	map[x][y] = color;
}

int change(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int flg=0;

	flg += u( x, y, color,map);
	flg += d( x, y, color,map);
	flg += l( x, y, color,map);
	flg += r( x, y, color,map);

	flg += ul( x, y, color,map);
	flg += dr( x, y, color,map);
	flg += ur( x, y, color,map);
	flg += dl( x, y, color,map);

	return flg;
}


