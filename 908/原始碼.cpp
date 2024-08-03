#include<iostream>
#include<vector>
#include<algorithm>
#include <limits.h>
using namespace std;

vector <vector<int> > map;
vector <vector<int> > temp;
vector <int> check;
int newcost,n,tempsize=0,sum_check;
void mark(int start){
	for(int i=0;i<map.size();i++){
		if(map[i][1]-1 ==start &&check[map[i][2]-1]==0){
			temp[tempsize].push_back(map[i][0]);
			temp[tempsize].push_back(map[i][1]);
			temp[tempsize++].push_back(map[i][2]);
		}
		else if(map[i][2]-1 ==start &&check[map[i][1]-1]==0){
			temp[tempsize].push_back(map[i][0]);
			temp[tempsize].push_back(map[i][1]);
			temp[tempsize++].push_back(map[i][2]);
		}
	}
	int mmin =INT_MAX,mmin_index1,mmin_index2,index;
	for(int i=0;i<tempsize;i++){
		if(temp[i][0]<mmin && (check[temp[i][1]-1]==0||check[temp[i][2]-1]==0)){
			mmin = temp[i][0];
			mmin_index1= temp[i][1];
			mmin_index2= temp[i][2];
			index = i;	
		}
	}
	newcost += mmin;
	temp.erase(temp.begin()+index);
	tempsize--;
	if(check[mmin_index1-1]==1){
		check[mmin_index2-1]=1;
		sum_check++;
		if(sum_check == n){
			return;
		}
		mark(mmin_index2-1);
	}
	else{
		check[mmin_index1-1]=1;
		sum_check++;
		if(sum_check == n){
			return;
		}
		mark(mmin_index1-1);
	}
}

int main(){
	int k,m,cp1,cp2,cost,mincost,casenumber =0;
	while(cin>>n){
		map.clear();
		check.clear();
		if(casenumber++) cout<<"\n"; 
		mincost = 0;
		map.resize(n-1);
		check.resize(n);
		for(int i=0;i<n;i++){
			check[i]=0;	
		}
		for(int i=0;i<n-1;i++){
			cin>>cp1>>cp2>>cost;
			mincost+=cost;
		}
		cin>>k;
		map.resize(k);
		for(int i=0;i<k;i++){
			cin>>cp1>>cp2>>cost;
			map[i].push_back(cost);
			map[i].push_back(cp1);
			map[i].push_back(cp2);
		}
		cin>>m;
		map.resize(k+m);
		for(int i=0;i<m;i++){
			cin>>cp1>>cp2>>cost;
			map[k+i].push_back(cost);
			map[k+i].push_back(cp1);
			map[k+i].push_back(cp2);
		}
		//for(int i=0;i<map.size();i++){
		//	cout<<map[i][0]<<map[i][1]<<map[i][2]<<"\n";
		//}
		check[map[0][1]-1]=1;
		newcost = 0;
		sum_check =1;
		tempsize=0;
		temp.clear();
		temp.resize(map.size());
		mark(map[0][1]-1);
		//for(int i=0;i<check.size();i++){
		//	cout<<check[i]<<endl;
		//}
		cout<<mincost<<"\n"<<newcost<<"\n";
	}
	return 0;
}
