#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
//30 
bool possible(vector<int> input){
    if (accumulate(input.begin(),input.end(),0)%3==0 && //3의 배수인가?
    find(input.begin(),input.end(),0)!=input.end()) //10의 배수인가?
        return 1;
    return 0;
}

int main(){
    string N;
    cin>>N;
    vector<int> input;

    //입력. 각 자리수별 숫자 vector에 집어넣기.
    for(int i=0;i<N.size();i++){
        input.push_back(N[i]-'0');
    }

    if (!possible(input)){//조건 충족 불가 input이라면
        cout<<-1; return 0;//끝내기
    }

    sort(input.begin(),input.end(),greater<int>());//sort하면 0이 알아서 끝으로 감 & 제일 큰 수 만들어짐
    
    for(int i=0;i<N.size();i++){
        cout<< input[i];
    }
    

    return 0;
}