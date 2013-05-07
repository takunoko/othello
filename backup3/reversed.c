#include"othello.h"
#include"reversed.h"
//反転動作についての処理を書くファイル

int u( int x, int y, int color, int map[][MAP_SIZE_Y]){
	//pyが置こうとしている場所
	int py=y;

	//自分の反対色
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}

	//自分より上のますが２つ以上or自分の上が自分と
	//違う色じゃない場合は即サヨナラー
	if(y<=1 || map[x][y-1]!=not_color){
		return 0;
	}

	//自分の２つ上以上を調べる
	for(y-=2;y>=0;y--){
		if(map[x][y]==color){
			for(;py>=y;py--){
				map[x][py]=color;
			}
			//反転できた場合だけ1を戻す
			return 1;
		}
	}
	return 0;
}

int d(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int py=y;

	//自分の反対色
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}


	if(y>=MAP_SIZE_Y-2 || map[x][y+1]!=not_color){
		return 0;
	}

	//自分の２つ上以上を調べる
	for(y+=2;y<=MAP_SIZE_Y-1;y++){
		if(map[x][y]==color){
			for(;py<=y;py++){
				map[x][py]=color;
			}
			//反転できた場合だけ1を戻す
			return 1;
		}
	}
	return 0;
}

int l(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int px=x;

	//自分の反対色
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}

	if(x<=1 || map[x-1][y]!=not_color){
		return 0;
	}

	//自分の２つ上以上を調べる
	for(x-=2; x>=0; x--){
		if(map[x][y]==color){
			for(;px>=x;px--){
				map[px][y]=color;
			}
			//反転できた場合だけ1を戻す
			return 1;
		}
	}
	return 0;
}

int r(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int px=x;

	//自分の反対色
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}

	if(x>=MAP_SIZE_X-2 || map[x+1][y]!=not_color){
		return 0;
	}

	//自分の２つ上以上を調べる
	for(x+=2;x<=MAP_SIZE_X-1;x++){
		if(map[x][y]==color){
			for(;px<=x;px++){
				map[px][y]=color;
			}
			//反転できた場合だけ1を戻す
			return 1;
		}
	}
	return 0;
}

int ul(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int px=x;
	int py=y;

	//自分の反対色
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}

	if(x<=1 || y<=1 || map[x-1][y-1]!=not_color){
		return 0;
	}

	//自分の２つ上以上を調べる
	for(x-=2, y-=2; x>=0 && y>=0; x--, y--){
		if(map[x][y]==color){
			for(;px>=x;px--,py--){
				map[px][py]=color;
			}
			//反転できた場合だけ1を戻す
			return 1;
		}
	}
	return 0;
}

int dr(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int px=x;
	int py=y;

	//自分の反対色
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}

	if(x>=MAP_SIZE_X-2 || y>=MAP_SIZE_Y-2 || map[x+1][y+1]!=not_color){
		return 0;
	}

	//自分の２つ上以上を調べる
	for(x+=2, y+=2; x<=MAP_SIZE_X-1 && y<=MAP_SIZE_Y-1; x++, y++){
		if(map[x][y]==color){
			for(; px<=x; px++, py++){
				map[px][py]=color;
			}
			//反転できた場合だけ1を戻す
			return 1;
		}
	}
	return 0;
}

int ur(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int px=x;
	int py=y;

	//自分の反対色
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}

	if(x>=MAP_SIZE_X-2 || y<=1 || map[x+1][y-1]!=not_color){
		return 0;
	}

	//自分の２つ上以上を調べる
	for(x+=2, y-=2; x<=MAP_SIZE_X-1 && y>=0; x++, y--){
		if(map[x][y]==color){
			for(; px<=x; px++, py--){
				map[px][py]=color;
			}
			//反転できた場合だけ1を戻す
			return 1;
		}
	}
	return 0;
}

int dl(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int px=x;
	int py=y;

	//自分の反対色
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}

	if(x<=1 || y>=MAP_SIZE_Y-2 || map[x-1][y+1]!=not_color){
		return 0;
	}

	//自分の２つ上以上を調べる
	for(x-=2, y+=2; x>=0 && y<=MAP_SIZE_Y-1; x--, y++){
		if(map[x][y]==color){
			for(; py<=y; px--, py++){
				map[px][py]=color;
			}
			//反転できた場合だけ1を戻す
			return 1;
		}
	}
	return 0;
}
