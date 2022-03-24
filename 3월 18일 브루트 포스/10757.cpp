#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//큰 수 더하기 A+B
//결과값 맞는데 왜 틀렸는지 모르겠음. 

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B, R1, R2;
    cin>>A>>B;
    //자릿수 맞춰주기

    string R = "";

    int result=0, carry=0; //각 자릿수 합 10 넘어갈때 올림
    for (int i=max(A.size(), B.size())-1; i>=-1;i--){
        result+= carry; carry=0;//초기화
        if (i<A.size()) result+=A[i]-'0';
        if (i<B.size()) result+=B[i]-'0';
        //자릿수 합이 10 넘어갈때
        if (result>=10) carry++;
        R=to_string(result%10)+R;
        result=0;//초기화
    }


    cout<< R;


    return 0;
}