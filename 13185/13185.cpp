#include <iostream>

using namespace std;

int main(){
	int t,n,sum;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		sum=0;
		for(int j=1;j<=n/2;j++){
			if(n%j==0){
				sum+=j;
			}
		}
		if(sum<n) cout<<"deficient\n";
		else if(sum==n) cout<<"perfect\n";
		else cout<<"abundant\n";
	}
	return 0;
} 
