#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

//스트라이크, 볼
//가능한 모든 세자리 수 집합에서, 주어진 조건 일치하지 않는 경우 delete
//구현ing

map<string, bool> candidate;

void ruleOut(string hint, int strike, int ball){

    //strike 갯수 세기
    for (auto c:candidate){
        int num_strike=0, num_ball=0;
        for(int i=0; i<3;i++){
            if (hint[i]==c.first[i]) num_strike++;
            if (c.first.find(hint[i])!=c.first.npos && c.first.find(hint[i])!=i) num_ball++;
        }
        if (num_strike!=strike || num_ball!=ball) c.second = false;//
    }
}

int main(){

    //가능한 모든 세자리수들의 집합 만들기
    for (int i=100;i<1000;i++){
        candidate[to_string(i)]=true;
    }

    //입력
    int N, strike, ball; string hint;
    cin>>N;
    while(N--){
        cin>> hint >> strike >> ball;
        ruleOut(hint,strike,ball);//조건불일치 원소들 소거
    }
    int cnt;

    for (auto i:candidate){
        if (i.second==true) cnt++;
    }

    cout<< cnt;
    return 0;
}