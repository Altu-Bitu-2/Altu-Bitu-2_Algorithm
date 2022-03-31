#include <iostream>
#include <vector>
#include <map>

//과제 - N과 M(9)
using namespace std;

const int SIZE =8;
int n, m;
map <int,bool> checked;
vector <int> seq(SIZE);//수열


void backtracking(int cnt){
    if (cnt==m) {
        for(int i=0; i<cnt;i++){
            cout<<seq[i] << ' ';
        }
        cout <<'\n';
        return;
    }
    
    for (auto i:checked){
        if (i.second) continue;//만약 checked되어 있다면 가지치기... 가 목표였으나 제대로 가지치기가 안 되는 것 같음. 
        seq[cnt]=i.first;
        i.second=true;
        backtracking(cnt+1);
        i.second=false;
    }
}

int main(){
    int input;
    cin>> n >> m;
    while(n--){
        cin>>input;
        checked[input]=false;
    }

    backtracking(0);
    return 0;
}