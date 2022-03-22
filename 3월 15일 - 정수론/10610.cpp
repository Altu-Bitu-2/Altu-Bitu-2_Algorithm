#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
//30 
bool possible(string N){ //조언해주신대로 굳이vecor<int> 안 쓰고, 
    //string만으로 연산되도록 고쳐보았습니다! 다만, acclmulate 함수 쓸때, 
    //각 자리 char형태인 숫자들이 int로 기능되도록 '0'을 그만큼 빼줬는데,
                                //여기가 가독성이 떨어지진 않는지 걱정됩니다. 
    if ((accumulate(N.begin(),N.end(),-'0'*N.size()))%3==0 && //3의 배수인가?
    find(N.begin(),N.end(),'0')!=N.end()) //10의 배수인가?
        return 1;
    return 0;
}

int main(){
    string N;
    cin>>N;

    if (!possible(N)){//조건 충족 불가 N이라면
        cout<<-1; return 0;//끝내기
    }

    sort(N.begin(),N.end(),greater<int>());//sort하면 0이 알아서 끝으로 감 & 제일 큰 수 만들어짐
    
    cout<< N;

    return 0;
}