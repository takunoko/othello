#include"othello.h"
#include"reversed.h"
//$BH?E>F0:n$K$D$$$F$N=hM}$r=q$/%U%!%$%k(B

int u( int x, int y, int color, int map[][MAP_SIZE_Y]){
	//py$B$,CV$3$&$H$7$F$$$k>l=j(B
	int py=y;

	//$B<+J,$NH?BP?'(B
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}

	//$B<+J,$h$j>e$N$^$9$,#2$D0J>e(Bor$B<+J,$N>e$,<+J,$H(B
	//$B0c$&?'$8$c$J$$>l9g$OB(%5%h%J%i!<(B
	if(y<=1 || map[x][y-1]!=not_color){
		return 0;
	}

	//$B<+J,$N#2$D>e0J>e$rD4$Y$k(B
	for(y-=2;y>=0;y--){
		if(map[x][y]==color){
			for(;py>=y;py--){
				map[x][py]=color;
			}
			//$BH?E>$G$-$?>l9g$@$1(B1$B$rLa$9(B
			return 1;
		}
	}
	return 0;
}

int d(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int py=y;

	//$B<+J,$NH?BP?'(B
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}


	if(y>=MAP_SIZE_Y-2 || map[x][y+1]!=not_color){
		return 0;
	}

	//$B<+J,$N#2$D>e0J>e$rD4$Y$k(B
	for(y+=2;y<=MAP_SIZE_Y-1;y++){
		if(map[x][y]==color){
			for(;py<=y;py++){
				map[x][py]=color;
			}
			//$BH?E>$G$-$?>l9g$@$1(B1$B$rLa$9(B
			return 1;
		}
	}
	return 0;
}

int l(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int px=x;

	//$B<+J,$NH?BP?'(B
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}

	if(x<=1 || map[x-1][y]!=not_color){
		return 0;
	}

	//$B<+J,$N#2$D>e0J>e$rD4$Y$k(B
	for(x-=2; x>=0; x--){
		if(map[x][y]==color){
			for(;px>=x;px--){
				map[px][y]=color;
			}
			//$BH?E>$G$-$?>l9g$@$1(B1$B$rLa$9(B
			return 1;
		}
	}
	return 0;
}

int r(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int px=x;

	//$B<+J,$NH?BP?'(B
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}

	if(x>=MAP_SIZE_X-2 || map[x+1][y]!=not_color){
		return 0;
	}

	//$B<+J,$N#2$D>e0J>e$rD4$Y$k(B
	for(x+=2;x<=MAP_SIZE_X-1;x++){
		if(map[x][y]==color){
			for(;px<=x;px++){
				map[px][y]=color;
			}
			//$BH?E>$G$-$?>l9g$@$1(B1$B$rLa$9(B
			return 1;
		}
	}
	return 0;
}

int ul(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int px=x;
	int py=y;

	//$B<+J,$NH?BP?'(B
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}

	if(x<=1 || y<=1 || map[x-1][y-1]!=not_color){
		return 0;
	}

	//$B<+J,$N#2$D>e0J>e$rD4$Y$k(B
	for(x-=2, y-=2; x>=0 && y>=0; x--, y--){
		if(map[x][y]==color){
			for(;px>=x;px--,py--){
				map[px][py]=color;
			}
			//$BH?E>$G$-$?>l9g$@$1(B1$B$rLa$9(B
			return 1;
		}
	}
	return 0;
}

int dr(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int px=x;
	int py=y;

	//$B<+J,$NH?BP?'(B
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}

	if(x>=MAP_SIZE_X-2 || y>=MAP_SIZE_Y-2 || map[x+1][y+1]!=not_color){
		return 0;
	}

	//$B<+J,$N#2$D>e0J>e$rD4$Y$k(B
	for(x+=2, y+=2; x<=MAP_SIZE_X-1 && y<=MAP_SIZE_Y-1; x++, y++){
		if(map[x][y]==color){
			for(; px<=x; px++, py++){
				map[px][py]=color;
			}
			//$BH?E>$G$-$?>l9g$@$1(B1$B$rLa$9(B
			return 1;
		}
	}
	return 0;
}

int ur(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int px=x;
	int py=y;

	//$B<+J,$NH?BP?'(B
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}

	if(x>=MAP_SIZE_X-2 || y<=1 || map[x+1][y-1]!=not_color){
		return 0;
	}

	//$B<+J,$N#2$D>e0J>e$rD4$Y$k(B
	for(x+=2, y-=2; x<=MAP_SIZE_X-1 && y>=0; x++, y--){
		if(map[x][y]==color){
			for(; px<=x; px++, py--){
				map[px][py]=color;
			}
			//$BH?E>$G$-$?>l9g$@$1(B1$B$rLa$9(B
			return 1;
		}
	}
	return 0;
}

int dl(int x, int y, int color, int map[][MAP_SIZE_Y]){
	int px=x;
	int py=y;

	//$B<+J,$NH?BP?'(B
	int not_color=0;
	if(color==1){
		not_color=2;
	}else{
		not_color=1;
	}

	if(x<=1 || y>=MAP_SIZE_Y-2 || map[x-1][y+1]!=not_color){
		return 0;
	}

	//$B<+J,$N#2$D>e0J>e$rD4$Y$k(B
	for(x-=2, y+=2; x>=0 && y<=MAP_SIZE_Y-1; x--, y++){
		if(map[x][y]==color){
			for(; py<=y; px--, py++){
				map[px][py]=color;
			}
			//$BH?E>$G$-$?>l9g$@$1(B1$B$rLa$9(B
			return 1;
		}
	}
	return 0;
}
