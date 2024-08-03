#include<iostream>
#include<vector>
using namespace std;

int main(){
	int board[500][500];
	int W,H,N;
	int x1,x2,y1,y2,temp,sum,empty;
	
	while(cin>>W>>H>>N&&W!=0){
		for(int i=0;i<500;i++)
			for(int j=0;j<500;j++)
				board[i][j] =0;
		sum=0;
		empty=0;
		for(int i=0;i<N;i++){
			cin>>x1>>y1>>x2>>y2;
			if(x1>x2){
				temp=x1;
				x1=x2;
				x2=temp;
				temp=y1;
				y1=y2;
				y2=temp;
			}
			if(y1>y2){
				temp=y1;
				y1=y2;
				y2=temp;
			}
			for(int w=x1;w<=x2;w++){
				for(int h=y1;h<=y2;h++){
					board[w-1][h-1]=1;
				}
			}
		}
		for(int w=0;w<W;w++)
			for(int h=0;h<H;h++)
				sum+=board[w][h];
		
		empty = W*H-sum;
		if(empty==0){
			cout<<"There is no empty spots."<<endl;
		}
		else if(empty==1){
			cout<<"There is one empty spot."<<endl;
		}
		else{
			cout<<"There are "<<empty<<" empty spots."<<endl;
		}	
	}
	return 0;
}
