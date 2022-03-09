#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//알바생 강호 - 틀림 : 결과값 다 정확한데 왜 틀렸는지 모르겠음. 
//내림차순으로 정렬

int sumTip(vector<int> arr, int n){ //팁 계산
    int tip=0;
    for (int i=0; i<n; i++){
        if (arr[i]-i>0) {tip+= arr[i]- i;} //받을 팁이 양수일때만 더해주기
    }
    return tip;
}



int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n; cin>>n; vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //내림차순 정렬
    sort(arr.begin(),arr.end(),greater<int>());

    //팁 계산 및 출력
    cout<< "\n" << sumTip(arr, n);

    return 0;
}