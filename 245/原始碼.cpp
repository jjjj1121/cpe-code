#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	vector <string> wordlist;
	string n;
	string t;
	int check,value;
	while(getline(cin,n)&& n!="0"){
		for(int i=0;i<n.length();i++){
			if(isalpha(n[i])){
				t="";
				t+=n[i];
				i++;
				while(isalpha(n[i])){
					t+=n[i];
					i++;
				}
				i--;
				wordlist.push_back(t);
				cout<<t;	
			}
			else if(isdigit(n[i])){
				value = 0;
				value= value*10+n[i]-'0';
				i++;
				while(isdigit(n[i])){
					value= value*10+n[i]-'0';
					i++;
				}
				i--;
				t=wordlist[wordlist.size()-value];
				wordlist.erase(wordlist.end()-value);
				wordlist.push_back(t);
				cout<<t;
			}
			else{
				cout<<n[i];
			}
		}
		cout<<endl;
	}
	return 0;
} 
