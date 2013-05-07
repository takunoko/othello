#ifndef FOO_H
#define FOO_H

#include"othello.h"

#endif

int main(void){
	//int map[MAP_SIZE_X][MAP_SIZE_Y];
	//init_map(map);
	
	int map[8][8]={
		{1,0,1,2,1,2,2,2},
		{2,1,1,1,2,0,1,2},
		{2,1,0,2,1,2,2,1},
		{2,2,1,1,2,1,2,2},
		{0,2,2,0,1,2,2,2},
		{1,1,0,2,1,2,0,1},
		{2,2,1,1,0,2,1,2},
		{2,2,1,1,1,2,2,1}};
	
	int color=0;
	int turn=0;
	for(turn=0; turn<60;turn++){
		color=turn%2+1;
		printf("----your turn(%d)-----\n",color);
		draw_map(map);
		put(color,map);
		//aiの思考
		if(color==1){
			//next_map(turn,2,map);
			put_top(2,map);
		}else{
			//next_map(turn,1,map);
			put_top(1,map);
		}	
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
			if(map[j][i]==1){
				printf("○ ");
			}else if(map[j][i]==2){
				printf("● ");
			}else{
				printf("　");
			}
			//printf("%2d",map[j][i]);
		}
		putchar('\n');
	}
}

//コマをおく場所
void put(int color, int map[][MAP_SIZE_Y]){
	int x,y;
	do{
		printf("x,y :");
		scanf("%d,%d",&x,&y);
	}while(change(x, y, color, map) == 0);

	map[x][y] = color;
}

//反転できるか。
int change(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int flg=0;
	if(map[x][y] != 0) return 0;

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

int winner(int map[][MAP_SIZE_Y]){
	int i,j;
	int black=0,white=0;
	for(i=0;i<MAP_SIZE_Y;i++){
		for (j = 0; j < MAP_SIZE_X; j++) {
			if(map[j][i] == WHITE){
				white++;
			}else if(map[j][i] == BLACK){
				black++;
			}else{
			}
		}
	}

	if(white<black){
		return BLACK;
	}else if(white > black){
		return WHITE;
	}else{
		return 0;
	}
}
