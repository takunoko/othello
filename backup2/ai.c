#include <unistd.h>
#include "othello.h"

int map_case = 0;

int next_map(int turn, int color,int map[][MAP_SIZE_Y]){
	int i,j;
	int d_map[MAP_SIZE_X][MAP_SIZE_Y];

	map_case++;
	printf("case_n = %d\n",map_case);

	//自分の色から、相手の色を割り出す
	int next_color=0;
	if(color==1){
		next_color=2;
	}else{
		next_color=1;
	}

	cpy_map(d_map,map);

	//おけるところがあるかどうか
	double flg=0;

	//マップ全体のスペースの数
	int space=0;
	//勝率
	double win_par=0;

	//左上から、おけるところを検索
	for(i=0; i<MAP_SIZE_Y; i++){
		for (j = 0; j < MAP_SIZE_X; j++) {
			//おけるところがあったら、置く
			if(change(j,i,color,d_map)!=0){
				flg++;
				printf("AI...(%d,%d)\n",j,i);
				printf("turn=%d\n",turn);
				draw_map(d_map);
				win_par += next_map(turn+1,next_color,d_map);
				cpy_map(d_map,map);
			}
			if(map[j][i] == 0)	space++;
		}
	}

	//もし、すべてのますが埋まっていたら
	if(space==0){
		printf("End_game");
		printf("win : %d\n",winner(map));
		return winner(map);
	}

	//パスが発生した場合
	if(flg==0){
		puts("-----------pass--------------");
		//左上から、おけるところを検索
		for(i=0; i<MAP_SIZE_Y; i++){
			for (j = 0; j < MAP_SIZE_X; j++) {
				//おけるところがあったら、置く
				if(change(j,i,next_color,d_map)!=0){
					flg++;
					printf("AI...(%d,%d)\n",j,i);
					printf("turn=%d\n",turn);
					draw_map(d_map);
					win_par += next_map(turn,color,d_map);
					cpy_map(d_map,map);
				}
				if(map[j][i] == 0)	space++;
			}
		}
	}

	//どちらの色もおける場所がない
	if(flg==0){
		printf("space_bat_no_putaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
		printf("win : %d\n",winner(map));
		return winner(map);
	}

	return win_par/flg;
}

void cpy_map(int map_1[][MAP_SIZE_Y], int map_2[][MAP_SIZE_Y]){
	//作業用マップ配列にコピー
	int i,j;
	for(i=0; i<MAP_SIZE_Y; i++){
		for (j = 0; j < MAP_SIZE_X; j++) {
			map_1[j][i] = map_2[j][i];
		}
	}
}

void put_point(int turn, int color, int map[][MAP_SIZE_Y]){
	int d_map[MAP_SIZE_X][MAP_SIZE_Y];

	int i,j;
	int can_put=0;

	int *top_p;

	cpy_map(d_map,map);

	//現状、何箇所置けるか判断
	for(i=0; i<MAP_SIZE_Y; i++){
		for (j = 0; j < MAP_SIZE_X; j++) {
			if(change(j,i,color,d_map)!=0){
				can_put++;
				cpy_map(d_map,map);
			}
		}
	}

	printf("can_put_n = %d",can_put);
	
	//can_putの数だけ、勝率を入れるメモリ確保
	top_p = (int *)malloc(can_put);

	/*
	//それぞれのケースについて勝率を計算
	int n=0;
	for(i=0; i<MAP_SIZE_Y; i++){
		for (j = 0; j < MAP_SIZE_X; j++) {
			if(change(j,i,color,d_map)!=0){
				top_p[n] = next_map(turn, color, d_map);
				cpy_map(d_map,map);
			}
		}
	}

	for(i=0;i<can_put;i++){
		printf("case[%d] = %f \n",i,top_p[i]);
	}
	*/
	return;
}
