#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
	int test,n,countdigit=0;
	char input1;
	int input2,input3;
	vector <set <int> > myset;
	vector <int> union_index;
	cin>>test;
	int suc=0,fail=0;
	for(int t=0;t<test;t++){
		if(t) cout<<"\n"; 
		suc=0,fail=0;
		if(t==0) cin>>n;
		while(cin>>input1){
			if(isdigit(input1)){
				countdigit++;
				if(countdigit==1){
					cout<<suc<<","<<fail<<"\n";
					myset.clear();
					break;	
				}
			}
			else{
				countdigit=0;
			}
			if(input1 =='c'){
				cin>>input2>>input3;
				if(myset.size()==0){
					set <int> s;
					s.insert(input2);
					s.insert(input3);
					myset.push_back(s);	
				}
				else{
					union_index.clear();
					int flag =1;
					for(int i=0;i<myset.size();i++){
						if(myset[i].count(input2) || myset[i].count(input3)){
							myset[i].insert(input2);
							myset[i].insert(input3);
							flag=0;
							union_index.push_back(i);
						} 
					}
					if(flag){
						set <int> s;
						s.insert(input2);
						s.insert(input3);
						myset.push_back(s);		
					}
				}
				if(union_index.size()>1){
					set<int> s ;
					for(int i=0;i<union_index.size();i++){
						int n = sizeof(myset[union_index[i]]) / sizeof(int);
						s.insert(myset[union_index[i]-i].begin(),myset[union_index[i]-i].end());
						myset.erase(myset.begin()+union_index[i]-i);
					}
					myset.push_back(s);
					union_index.clear();
				}
			}
			else if (input1=='q'){
				cin>>input2>>input3;
				int flag=1;
				if(input2==input3){
					suc++;
					continue;
				}
				for(int i=0;i<myset.size();i++){
					if(myset[i].count(input2) && myset[i].count(input3)){
						suc++;
						flag=0;
						break;
					}
				}
				if(flag) fail ++;
			}
		}
	}
	cout<<suc<<","<<fail<<"\n";
	return 0;
}
