#include<iostream>
#include<vector>
#include<string>
using namespace std;
int pointer[1001];
vector <int> teamqueue;
vector <vector <int> > team;
vector <int> queue;
int t;
int is_in_team_queue(int x){
	for(int i=0;i<team.size();i++){
		for(int j=0;j<team[i].size();j++){
			if(x==team[i][j]){
				if(pointer[i]==-1){
					teamqueue.push_back(i);
					pointer[i]=queue.size();
					return pointer[i];
				}
				else{
					pointer[i]+=1;
					int flag=0;
					for(int z=0;z<teamqueue.size();z++){
						if(flag&&pointer[teamqueue[z]]!=-1){
							pointer[teamqueue[z]]+=1;
						}
						if(teamqueue[z]==i){
							flag=1;
						}
					}
					return pointer[i];
				}
			}
		}
	}
	return queue.size();
}

int main(){
	int n,teamMember;
	string command;
	int x,s=1;
	while(cin>>t && t!=0){
		team.resize(t);
		for(int z=0;z<t;z++){
			pointer[z]=-1;
		}
		cout<<"Scenario #"<<s<<endl;
		s++;
		for(int i=0;i<t;i++){
			cin>>n;
			for(int j=0;j<n;j++){
				cin>>teamMember;
				team[i].push_back(teamMember);
			}
		}
		while(cin>>command && command != "STOP"){
			if(command == "DEQUEUE" && !queue.empty()){
				cout<<queue[0]<<"\n";
				queue.erase(queue.begin());
				for(int z=0;z<t;z++){
					if(pointer[z]!=-1){
						pointer[z]=pointer[z]-1;
						if(pointer[z]==-1){
							teamqueue.erase(teamqueue.begin());
						}
					}
				}
			}
			else{
				cin>>x;
				queue.insert(queue.begin()+is_in_team_queue(x),x);	
			}
		}
		cout<<endl;
		teamqueue.clear();
		team.clear();
		queue.clear();
	}
	return 0;
} 
