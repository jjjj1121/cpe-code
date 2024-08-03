#include<iostream>

using namespace std;
int grid[101][101];
int map[101][101];
int m,n;
void move(int i,int j){
	int dir[9][2] = {
    {-1,-1}, {0,-1}, {1,-1},
    {-1,0}, {0,0}, {1,0},
    {-1,1}, {0,1}, {1,1}
	};
	for(int t=0;t<9;t++){
		if(i+dir[t][0]>=0&&j+dir[t][1]>=0&&i+dir[t][0]<m&&j+dir[t][1]<n&&grid[i+dir[t][0]][j+dir[t][1]]==2&&map[i+dir[t][0]][j+dir[t][1]]==0){
			map[i+dir[t][0]][j+dir[t][1]]=1;
			move(i+dir[t][0],j+dir[t][1]);
		}
	}
	return ;
}

int main(){
	int count;
	char input;
	while(cin>>m>>n&&m!=0&&n!=0){
		grid[101][101]={0};
		count=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>input;
				if(input=='@'){
					grid[i][j]=2;
				}
				else{
					grid[i][j]=1;
				}
				map[i][j]=0;
			}
		}
		
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j]==2&&map[i][j]==0){
					map[i][j]=1;
					move(i,j);
					count++;	
				}
			}
		}
		cout<<count<<"\n";
	}
} 
