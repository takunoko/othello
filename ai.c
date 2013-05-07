#include "othello.h"

int map_case = 0;

double next_map(int my_col,int color,int map[][MAP_SIZE_Y]){
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
	double flg=0.0;

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
				draw_map(d_map);
				win_par += next_map(my_col,next_color,d_map);
				cpy_map(d_map,map);
			}
			if(map[j][i] == 0)	space++;
		}
	}

	//もし、すべてのますが埋まっていたら
	if(space==0){
		printf("End_game ");
		printf("win : %d\n",winner(map));
		if(my_col == winner(map)){
			return 1;
		}else{
			return 0;
		}
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
					draw_map(d_map);
					win_par += next_map(my_col,color,d_map);
					cpy_map(d_map,map);
				}
				if(map[j][i] == 0)	space++;
			}
		}
	}

	//どちらの色もおける場所がない
	if(flg==0){
		printf("space_bat_no_putaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
		if(my_col == winner(map)){
			return 1;
		}else{
			return 0;
		}
	}

	return win_par/flg;
}

//x,yにおいた時の勝率を保存する構造体
struct put_case{
	int x,y;
	double par;
};

void put_top(int color, int map[][MAP_SIZE_Y]){
	int d_map[MAP_SIZE_X][MAP_SIZE_Y];

	int i,j;
	int can_put=0;

	struct put_case *top_p;

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

	printf("can_put = %d\n",can_put);
	
	//can_putの数だけ、勝率を入れるメモリ確保
	top_p = (struct put_case *)calloc(can_put,sizeof(struct put_case));
	
	//それぞれのケースについて勝率を計算
	int n=0;
	for(i=0; i<MAP_SIZE_Y; i++){
		for (j = 0; j < MAP_SIZE_X; j++) {
			if(change(j,i,color,d_map)!=0){
				//colorが２つあるのは、自分の色を渡すため
				printf("put(%d,%d)\n",j,i);
				top_p[n].x = j;
				top_p[n].y = i;
				top_p[n].par = next_map(color, color, d_map);
				printf("win_par = %f",top_p[n].par);
				cpy_map(d_map,map);
				n++;
			}
		}
	}

	printf("my_col = %d\n",color);
	for(i=0;i<can_put;i++){
		printf("map[%d][%d] = %f \n",top_p[i].x,top_p[i].y,top_p[i].par);
	}
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
