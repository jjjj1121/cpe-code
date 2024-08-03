#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <set>
using namespace std;

int n,queue_size;
vector <vector<int> > map;
set <int> check;
vector <pair<int,int> > queue;
vector <pair<int,int> > ans;
bool mycompare(pair<int ,int>p1,pair<int,int> p2){
	int p1x=p1.first,p1y=p1.second,p2x=p2.first,p2y=p2.second;
	if(map[p1x][p1y]!=map[p2x][p2y]) return map[p1x][p1y]<map[p2x][p2y];
	else{
		if(p1x!=p2x) return p1x<p2x;
		else return p1y<p2y;
	}  
}
void prim(int start){
	for(int j=0;j<n;j++){
		if(map[start][j]!=0&&check.count(j)!=1){
			queue.push_back(make_pair(start,j));
			queue_size++;
		}			
	}	
	int min= INT_MAX,min_index,minx,miny;
	for(int z=0;z<queue.size();z++){
		int x= queue[z].first;
		int y= queue[z].second;
		if(map[x][y]<min&&check.count(y)!=1){
			min = map[x][y];
			minx=x;
			miny=y;
			min_index = z; 
		}
	}
	ans.push_back(make_pair(minx,miny));
	queue.erase(queue.begin()+min_index);
	queue_size--;
	check.insert(miny);
	if(check.size()==n){
		return;
	}
	prim(miny);
}
int main(){
	int t,input,casenumber=1;
	cin>>t;
	for(int test=0;test<t;test++){
		cin>>n;
		map.clear();
		check.clear();
		map.resize(n);
		ans.clear();
		queue.clear();
		for(int i=0;i<n;i++){
			map[i].resize(n);
			for(int j=0;j<n;j++){
				if(j!=n-1) scanf("%d, ",&input);
				else scanf("%d",&input);
				map[i][j] = input; 
			}
		}
		queue_size=0;
		check.insert(0);
		prim(0);
		for(int z=0;z<ans.size();z++){
			if(ans[z].first>ans[z].second){
				int temp = ans[z].second;
				ans[z].second = ans[z].first;
				ans[z].first = temp;
			}
		}
		sort(ans.begin(),ans.end(),mycompare);
		cout<<"Case "<<casenumber++<<":\n";
		for(int z=0;z<ans.size();z++){
			cout<<char(ans[z].first+65)<<"-"<<char(ans[z].second+65)<<" "<<map[ans[z].first][ans[z].second]<<"\n";
		}
	}
	return 0;
} 
