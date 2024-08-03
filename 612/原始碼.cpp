#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <sstream>
using namespace std;

int main(){
    int M, n, m; 
    vector<string> DNA;
    string input;
    vector<pair<int, int> > sort_number; 
    int ACGT[4] = {0}, count;
    cin >> M;
    std::ostringstream oss; // 移至外部定義
    for(int t = 0; t < M; t++){
        cin >> n >> m;
        DNA.clear();
        sort_number.clear(); 
        for(int i = 0; i < m; i++){
            cin >> input;
            DNA.push_back(input);
            count = 0;
            fill(ACGT, ACGT + 4, 0);
            for(int j = 0; j < input.length(); j++){
                if(input[j] == 'A'){
                    ACGT[0]++;
                    if(ACGT[1]) count += ACGT[1];
                    if(ACGT[2]) count += ACGT[2];
                    if(ACGT[3]) count += ACGT[3];
                }
                else if(input[j] == 'C'){
                    ACGT[1]++;
                    if(ACGT[2]) count += ACGT[2];
                    if(ACGT[3]) count += ACGT[3];
                }
                else if(input[j] == 'G'){
                    ACGT[2]++;
                    if(ACGT[3]) count += ACGT[3];
                }
                else if(input[j] == 'T'){
                    ACGT[3]++;
                }
            }
            sort_number.push_back(make_pair(count, i)); 
        }
        sort(sort_number.begin(), sort_number.end());
        for(int i = 0; i < m; i++){
            oss << DNA[sort_number[i].second] << "\n"; 
        }
        if(M!=1&&t!=M-1)oss << "\n";
    }
    std::cout << oss.str();
    return 0;
}

