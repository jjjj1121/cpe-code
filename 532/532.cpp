#include<iostream>

using namespace std;
int L,R,C;
int map[31][31][31];
int dp[31][31][31];
int finish;
int endx,endy,endz;

void dfs(int z,int y,int x){
	int dir[6][3] = {{0,-1,0},{0,1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0}};
	for(int i=0;i<6;i++){
		int nextz = z + dir[i][0];
		int nexty = y + dir[i][1];
		int nextx = x + dir[i][2];
		if(nextz>=0&&nextz<L&&nexty>=0&&nexty<R&&nextx>=0&&nextx<C&&(map[nextz][nexty][nextx] == 0||map[nextz][nexty][nextx] == 2)&&dp[z][y][x]+1<dp[nextz][nexty][nextx]){
			if(map[nextz][nexty][nextx] == 2){
				finish = 1;
			}
			dp[nextz][nexty][nextx] = dp[z][y][x]+1;
			dfs(nextz,nexty,nextx);
		}
	}
}

int main(){
	char input;
	int startx,starty,startz;
	while(cin>>L>>R>>C&&L&&R&&C){
		finish = 0;
		for(int z=0;z<L;z++){
			for(int y=0;y<R;y++){
				for(int x=0;x<C;x++){
					map[z][y][x] = 0;
					dp[z][y][x] = 1000;
				}
			}
		}
		for(int z=0;z<L;z++){
			for(int y=0;y<R;y++){
				for(int x=0;x<C;x++){
					cin>>input;
					if(input == 'S'){
						map[z][y][x] = 3;
						startx=x;
						starty=y;
						startz=z;
					}
					else if(input == 'E'){
						map[z][y][x] = 2;
						endx=x;
						endy=y;
						endz=z;
					}
					else if(input == '#'){
						map[z][y][x] = 1;
					}
					else if(input == '.'){
						map[z][y][x] = 0;
					}
				}
			}
		}
		dp[startz][starty][startx] =0;
		dfs(startz,starty,startx);
		if(finish){
			cout<<"Escaped in "<<dp[endz][endy][endx]<<" minute(s).\n"; 
		}
		else{
			cout<<"Trapped!\n";
		}
	}
	return 0;
} 
