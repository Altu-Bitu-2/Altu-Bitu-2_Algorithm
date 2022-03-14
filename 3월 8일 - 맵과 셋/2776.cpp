#include <iostream>
#include <vector>
#include <set>

using namespace std;
//암기왕 문제 = 시간 초과 해결법 모르겠음
void correspond (set<int> &note1, vector<int> &note2){
    bool e;
    for(auto iter2:note2){
        e=0;//해당정수의 존재여부
        for (auto iter1:note1){
            if (iter2==iter1) {e=1; cout<<e<<'\n';break;}
        }
        if (e==0){cout<<e<<'\n';}
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N, M, input;
    set<int> note1; vector<int> note2;
    //입력
    cin>>T;
    while(T--){
    cin>>N;
    while(N--){
        cin>> input;
        note1.insert(input);
    }
    cin>>M;
    while(M--){
        cin>>input;
        note2.push_back(input);
    }
    //연산 및 출력
    correspond(note1, note2);
    }
}