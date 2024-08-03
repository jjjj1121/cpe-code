#include<iostream>

using namespace std;

bool is_prime(int n){
	for(int i=2;i<n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int prime[33000];
	prime[0]=0;
	prime[1]=0;
	for(int i=2;i<33000;i++){
		prime[i]=is_prime(i);
	}
	int input;
	while(cin>>input&&input!=0){
		int count =0;
		for(int i=1;i<=input/2;i++){
			if(prime[i] && prime[input-i]){
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
