#include<iostream>
#include<string>

using namespace std;

int main(){
	string HaabMonth[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
	string Tzolkin[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};

	int n,intday,intmonth,year,totalday,totalmonth;
	string day,month;
	cin>>n;
	cout<<n<<endl;
	for(int i=0;i<n;i++){
		cin>>day>>month>>year;
		intday=0;
		for(int j=0;j<day.length()-1;j++){
			intday=intday*10+day[j]-48;
		}
		for(int j=0;j<19;j++){
			if(month == HaabMonth[j]){
				intmonth =j;
				break;
			}
		}
		totalday = 20*intmonth+intday+year*365;
		cout<<(totalday%260)%13+1<<" "<<Tzolkin[(totalday%260)%20]<<" "<<totalday/260<<endl;	
	}
	return 0;
} 	
