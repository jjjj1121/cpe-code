#include<iostream>

using namespace std;

int is_prime(int n) {
    if(n <= 2) return 1;
    for(int i=2; i<n; ++i) 
        if(n % i == 0)
            return 0;
    return 1;
}

int main(){
	int N ,C,prime[1001];
	prime[1]=1;
	for(int i=2;i<=1000;i++){
		prime[i]=is_prime(i);
		//cout<<i<<" "<<prime[i]<<endl;	
	}
	while(cin>>N>>C){
		cout<<N<<" "<<C<<":";
		int sum=0,center,start;
		for(int i=1;i<=N;i++){
			sum+=prime[i];
		}
		if(sum%2){//2C-1
			center = sum/2+1;
			start=center-(2*C-1)/2;
			int count=1;
			for(int j=1;j<=N;j++){
				if(prime[j])count++;
				if(count>start&&prime[j]){
					cout<<" "<<j;
				}
				if(count>=start+2*C-1)break; 
			}
		}
		else{//2C
			center = sum/2;
			start=center-((2*C)/2-1);
			int count=1;
			for(int j=1;j<=N;j++){
				if(prime[j])count++;
				if(count>start&&prime[j]){
					cout<<" "<<j;
				}
				if(count>=start+2*C)break; 
			}
		}
		cout<<endl<<endl;
	}
	return 0;
}
