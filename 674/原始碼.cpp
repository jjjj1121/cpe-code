#include<iostream>

using namespace std;

int main(){
	int array[5] = {1,5,10,25,50};
	int target,ans[7489+1];
	fill(ans,ans+7490,0);
	ans[0] =1;
	for(int i=0;i<5;i++){
		for(int j=0;j<=7489;j++){
			if( j + array[i] > 7489 ) break;
			ans[ j + array[i] ] = ans[ j + array[i] ] + ans[j];
		}
	}
	while(cin>>target){
		cout<<ans[target]<<endl;
	}
	return 0;
} 
