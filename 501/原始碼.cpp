#include<iostream>
#include<vector>
#include<sstream>

using namespace std;
int search(int target , vector <int>& sorted){
	int mid ;
	int head=0,tail=sorted.size()-1;
	while(1){
		mid = (head+tail)/2;
		if(sorted[mid]<target && sorted[mid+1]>=target){
				return mid+1;
		}
		else if(sorted[mid]<target){
			if(mid == sorted.size()-1){
				return sorted.size();
			}
			head = mid+1;
		}
		else if(sorted[mid]>=target){
			if(mid == 0){
				return 0;
			}
			tail = mid-1;
		}
	}
	return -1;
}

int main(){
	ostringstream oss;
	int n,N,M,data;
	vector<int> A;
	vector<int> sorted;
	vector<int> u;
	cin>>n;
	for(int t=0;t<n;t++){
		if(t!=0)oss<<"\n";
		int count_add =0,ii=0;
		cin>>N>>M;
		for(int i =0;i<N;i++){
			cin>>data;
			A.push_back(data);
		}
		for(int i =0;i<M;i++){
			cin>>data;
			u.push_back(data);
		}
		for(int i=0;i<u.size();i++){
			while(count_add<u[i]){
				if(sorted.size()==0){
					sorted.push_back(A[count_add]);
				}
				else{
					int position = search(A[count_add],sorted);
					sorted.insert(sorted.begin()+position,A[count_add]);
				}
				count_add++;
			}
			oss<<sorted[ii++]<<"\n";
		}
		A.clear();
		u.clear();
		sorted.clear();
	}
	cout<<oss.str();
	return 0;
} 
