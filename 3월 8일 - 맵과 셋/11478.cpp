#include <iostream>
#include <set>

using namespace std;

//부분 문자열 - 출력값 정확하나 백준틀림
void setSubstring(string S, set<string> &sub_string){
    int length = S.length();

     for(int i=0;i<S.length();i++){ //string length i+1개짜리
        for (int k=0; k<length; k++){//시작 지점 k
            sub_string.insert(S.substr(k,k+i));
        }
        length--;
     }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    set<string> sub_string;
    string S;
    cin>>S;
    //연산
    setSubstring(S,sub_string);

    //출력
    cout<< sub_string.size();
    return 0;
}