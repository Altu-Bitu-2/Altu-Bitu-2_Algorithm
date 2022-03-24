#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

//스트라이크, 볼
//가능한 모든 세자리 수 집합에서, 주어진 조건 일치하지 않는 경우 delete
//구현ing
set<string> candidate;

void ruleOut(string hint, int strike, int ball){
    int num_strike=0, num_ball=0;
    //strike 갯수 세기
    for (auto c:candidate){
        for(int i=0; i<3;i++){
            if (hint[i]==c[i]) num_strike++;
        }
        for(int i=0; i<3;i++){
            if (c.find(hint[i])) num_ball++;
        }
        if (num_strike!=strike || num_ball!=ball) candidate.erase(c);
    }
}

int main(){

    //가능한 모든 세자리수들의 집합 만들기
    for (int i=100;i<1000;i++){
        candidate.insert(to_string(i));
    }

    //입력
    int N, strike, ball; string hint;
    cin>>N;
    while(N--){
        cin>> hint >> strike >> ball;
        ruleOut(hint,strike,ball);//조건불일치 원소들 소거
    }

    cout<< candidate.size();
    return 0;
}