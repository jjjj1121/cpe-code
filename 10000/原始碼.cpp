#include<iostream>
#include<sstream>
using namespace std;

int n;
int map[100][100];
int length[100][100];
void dfs(int a,int b){
	for(int i=0;i<n;i++){
		if(map[b][i]&&length[a][b]+1>length[b][i]){
			length[b][i] =max( length[a][b] +1,length[b][i]);
			dfs(b,i);
		}
	}
	return;
}

int main(){
	ostringstream oss;
	int start;
	int case_number =1;
	while(cin>>n&&n){
		cin>>start;
		for(int i = 0; i < n; i++) {
		    for(int j = 0; j < n; j++) {
		        map[i][j] = 0;
		        length[i][j] = 0;
		    }
		}
		//fill(&map[0][0],&map[0][0]+n*n,0);
		//fill(&length[0][0],&length[0][0]+n*n,0);
		int a,b;
		while(cin>>a>>b&&a&&b){
			map[a-1][b-1] = 1;
		}
		for(int j=0;j<n;j++){
			if(map[start-1][j]){
				length[start-1][j] +=1;
				dfs(start-1,j);
			}
		}
		int max_length=0,finish_point;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				//cout<<length[i][j]<<" ";
				if(max_length<length[i][j]){
					max_length = length[i][j];
					finish_point = j;
				}
				if(max_length==length[i][j]){
					finish_point = min(finish_point,j);
				}
			}
			//cout<<endl;
		}
		if(max_length==0) oss<<"Case "<<case_number<<": The longest path from "<<start<<" has length "<<max_length<<", finishing at "<<start<<".\n\n";
		else oss<<"Case "<<case_number<<": The longest path from "<<start<<" has length "<<max_length<<", finishing at "<<finish_point+1<<".\n\n";
		case_number++;
	}
	cout<<oss.str();
	return 0;
} 
