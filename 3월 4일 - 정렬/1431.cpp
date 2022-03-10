#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//시리얼 번호 : ※dictionary 힌트 주신 걸로 compare함수 써봤더니 BAAAA ACAAA 안되던 정렬 잘 돌아가지만..
//                 여전히 백준에서 틀리다고 나옵니다 ㅠ

int addNum(const string &a){//자리 수 합
    int result=0;
    for(int i=0;i<a.length();i++){
        if (isdigit(a[i])) result+=(a[i]-'0');}//숫자일 경우에만 더하기
    return result;
}

bool comp (const string &a, string const&b){
    if (a.length()!=b.length()) return a.length()<b.length();//길이
    if (addNum(a)!=addNum(b)) return addNum(a)<addNum(b);//자리 수 합
    else return a<b;//사전순
}

int main(){
    int n; 
    cin>>n;
    vector<string> guitar(n);

    //입력
    for (int i=0;i<n;i++){ 
        cin>> guitar[i];
    }
    //연산
    sort(guitar.begin(),guitar.end(),comp);

    //출력
    for (int i=0; i<n; i++){
        cout<< guitar[i]<<"\n";
    }

    return 0;
}
//자주 했던 실수 : ~.함수()에서 자꾸 함수인거 까먹고 () 안 쓰게 됨. 