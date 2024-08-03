#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int is_prime(int n){
	for(int i=2;i<n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	vector <int> prime;	
	vector <int> out;
	for(int i=2;i<=32767;i++){
		if(is_prime(i)){
			prime.push_back(i);
		}
	}
	string s;
	int value=0,sum,flag=1,p,c;
	while(getline(cin,s)&&s!="0"){
	    value=0;
		sum=1;
		flag=1;
		for(int i=0;i<s.length();i++){
			if(s[i]==' '){
				if(flag){
					p = value;
					flag = 0;
				}
				else{
					c = value;
					flag = 1;
					sum *= pow(p,c);
				}
				value = 0; 
			}
			else{
				value = value*10+s[i]-'0';
			}
		}
		c = value;
		sum *= pow(p,c);
		//以上處理完getline轉成數字並加總 
		int i=0,target=sum-1,count=0,flag2=1;
		while(target!=1){
			if(target%prime[i]==0){
				if(flag2) out.push_back(prime[i]);
				count++;
				target /=prime[i];
				flag2=0;
			}
			else{
				if(count) out.push_back(count);
				i++;
				flag2=1;
				count=0;
			}
		}
		if(count) out.push_back(count);
		for(int j=out.size()-1;j>=0;j--){
			if(j%2){
				cout<<out[j-1]<<" ";	
			}
			else if(j==0){
				cout<<out[j+1];	
			}
			else{
				cout<<out[j+1]<<" ";
			}
		}
		out.clear();
		cout<<"\n";
	}
	return 0;
} 
