#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
#include<set>

using namespace std;
string start,eend;
int n,r,tempsize,target_min;
string map[19901][3];
vector <vector <string> >temp;
set <string> check;
set <string> mark_ornot;

void mark(string startcity){
	if(!mark_ornot.count(startcity)){
		for(int i=0;i<r;i++){
			if(map[i][0] == startcity && check.count(map[i][1])==0){
				//cout<<startcity<<" "<<map[i][1]<<" "<<map[i][2]<<"\n";
				temp[tempsize].push_back(map[i][1]);
				temp[tempsize++].push_back(map[i][2]);
			}
			else if(map[i][1] == startcity && check.count(map[i][0])==0){
				//cout<<startcity<<" "<<map[i][0]<<" "<<map[i][2]<<"\n";
				temp[tempsize].push_back(map[i][0]);
				temp[tempsize++].push_back(map[i][2]);
			}
		}
		mark_ornot.insert(startcity);	
	}
	int mmax = 0,max_index;
	string nextcity;
	for(int i=0;i<tempsize;i++){
		int value = 0;
		for(int j=0;j<temp[i][1].length();j++){
			value = value *10 + temp[i][1][j]-'0';
		}
		if(value>mmax){
			mmax = value;
			max_index = i;
			nextcity = temp[i][0];
		}
	}
	target_min = min(target_min,mmax);
	if(nextcity==eend){
		return ;
	}
	//cout<<nextcity<<"\n";
	check.insert(nextcity);
	temp.erase(temp.begin()+max_index);
	tempsize--;
	mark(nextcity);
}

int main(){
	string city1,city2,weight;
	int casenumber =1;
	while(cin>>n>>r&&n&&r){
		for(int i=0;i<r;i++){
			cin>>city1>>city2>>weight;
			map[i][0] = city1;
			map[i][1] = city2;
			map[i][2] = weight;
		}
		cin>>start>>eend;
		check.clear();
		temp.clear();
		mark_ornot.clear();
		temp.resize(r);
		tempsize = 0;
		check.insert(start);
		target_min = INT_MAX;
		mark(start);
		cout<<"Scenario #"<<casenumber++<<"\n"<<target_min<<" tons\n\n";
	}
	return 0;
} 
