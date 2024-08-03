#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
int w,h,c;
int picture[51][51];
int sub[51][51];
int subcheck[51][51];
pair<int,int> check[51][51];
vector <int> dot;

void dfs_dice(int i,int j){
	int dir[5][2] ={ {0,-1},
			{-1,0},{0,0},{1,0},
			{0,1}
	};
	//i+dir[d][0]
	//j+dir[d][1]
	for(int d=0;d<5;d++){
		if(i+dir[d][0]>=0&&i+dir[d][0]<h&&j+dir[d][1]>=0&&j+dir[d][1]<w&&picture[i+dir[d][0]][j+dir[d][1]]
		&&check[i+dir[d][0]][j+dir[d][1]].first==1&&check[i+dir[d][0]][j+dir[d][1]].second==0){
			check[i+dir[d][0]][j+dir[d][1]]=make_pair(1,1);
			sub[i+dir[d][0]][j+dir[d][1]] = 1 ;
			subcheck[i+dir[d][0]][j+dir[d][1]] = 0;
			dfs_dice(i+dir[d][0],j+dir[d][1]);
		}
		else if(i+dir[d][0]>=0&&i+dir[d][0]<h&&j+dir[d][1]>=0&&j+dir[d][1]<w&&picture[i+dir[d][0]][j+dir[d][1]]
		&&check[i+dir[d][0]][j+dir[d][1]].first==2&&check[i+dir[d][0]][j+dir[d][1]].second==0){
			check[i+dir[d][0]][j+dir[d][1]]=make_pair(2,1);
			sub[i+dir[d][0]][j+dir[d][1]] = 2 ;
			subcheck[i+dir[d][0]][j+dir[d][1]] = 0;
			dfs_dice(i+dir[d][0],j+dir[d][1]);
			
		}
	}
	return ;
}
void sub_dfs(int i,int j){
	int dir[5][2] ={ {0,-1},
			{-1,0},{0,0},{1,0},
			{0,1}
	};
	for(int d=0;d<5;d++){
		if(i+dir[d][0]>=0&&i+dir[d][0]<h&&j+dir[d][1]>=0&&j+dir[d][1]<w&&picture[i+dir[d][0]][j+dir[d][1]]
		&&sub[i+dir[d][0]][j+dir[d][1]]==2&&subcheck[i+dir[d][0]][j+dir[d][1]]==0){
			subcheck[i+dir[d][0]][j+dir[d][1]]=1;
			sub_dfs(i+dir[d][0],j+dir[d][1]);
		}
	}
	return ;
}
int main(){
	int case_number=1;
	char input;
	while(cin>>w>>h&&w!=0&&h!=0){
		fill(&picture[0][0], &picture[0][0]+51*51,0);
		for(int i = 0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>input;
				if(input=='.'){
					picture[i][j]=0;
					check[i][j] = make_pair(0,0);
				}
				else if(input=='*'){
					picture[i][j]=1;
					check[i][j] = make_pair(1,0);
				}
				else if(input=='X'){
					picture[i][j]=2;
					check[i][j] = make_pair(2,0);
				}
			}
		}	
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(picture[i][j]==1&&check[i][j].first==1&&check[i][j].second==0){
					check[i][j]=make_pair(1,1);
					fill(&sub[0][0], &sub[0][0]+51*51,0);
					fill(&subcheck[0][0], &subcheck[0][0]+51*51,0);
					dfs_dice(i,j);
					c=0;
					for(int i=0;i<h;i++){
						for(int j=0;j<w;j++){
							if(sub[i][j]==2&&subcheck[i][j]==0){
								subcheck[i][j]=1;
								sub_dfs(i,j);
								c++;	
							}
						}
					}
					dot.push_back(c);
				}
			}
		}
		sort(dot.begin(),dot.end());
		cout<<"Throw "<<case_number<<"\n";
		case_number++;
		for(int i=0;i<dot.size();i++){
			if(i!=dot.size()-1)cout<<dot[i]<<" ";
			else cout<<dot[i]<<"\n";
		}
		cout<<"\n";
		dot.clear();
	}
	return 0;
}
