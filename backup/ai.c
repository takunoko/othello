#include "othello.h"

void next_map(int color,int map[][MAP_SIZE_Y]){
	int i,j;
	int d_map[MAP_SIZE_X][MAP_SIZE_Y];
	
	//作業用マップ配列にコピー
	for(i=0; i<MAP_SIZE_Y; i++){
		for (j = 0; j < MAP_SIZE_X; j++) {
			d_map[j][i] = map[j][i];
		}
	}

	for(i=0; i<MAP_SIZE_Y; i++){
		for (j = 0; j < MAP_SIZE_X; j++) {
			if(change(j,i,color,d_map)!=0){
				draw_map(d_map);
			}		
		}
	}
}
