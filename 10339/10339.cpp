#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){
	int k,m;
	while(cin>>k>>m){
		double day = 60*60*12*1.0/ abs(k-m);
		long long total_second = (long long)((86400-k) * day);
		int second = total_second % 60;
		int min = total_second /60;
		if(second  >=30) min++; 
		int h = min/60;
		min%=60;
		h%=12;
		if(h==0) h=12;
		cout<<k<<" "<<m<<" "<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<min<<endl;
	}
	return 0;
} 
