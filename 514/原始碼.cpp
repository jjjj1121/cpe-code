#include<iostream>
#include<vector>

using namespace std;

int main(){
	int N,x;
	vector <int> B;
	vector <int> temp;
	while(cin>>N&&N!=0){
		while(cin>>x&&x!=0){
			B.push_back(x);
			for(int i=1;i<N;i++){
				cin>>x;
				B.push_back(x);
			}
			int nowAnumber=1;
			while(B.size()){
				if(B[0]==nowAnumber){
					B.erase(B.begin());
					while(temp.size()){
						if(B[0]==temp[temp.size()-1]){
							B.erase(B.begin());
							temp.pop_back();
						}
						else{
							break;
						}
					}
				}
				else{
					temp.push_back(nowAnumber); 
				}
				nowAnumber++;
				if(nowAnumber>N){
					break;
				}
			}
			while(temp.size()){
				if(B[0]==temp[temp.size()-1]){
					B.erase(B.begin());
					temp.pop_back();
				}
				else{
					break;
				}
			}
			if(!temp.size()) cout<<"Yes"<<"\n";
			else cout<<"No"<<"\n";
			temp.clear();
			B.clear();
	 	}
	 	cout<<"\n";
	}
	return 0;
}
