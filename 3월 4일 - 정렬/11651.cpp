#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std; 
//좌표정렬하기2
typedef pair<int,int> cor;


bool comp (const cor &a, const cor &b){
    if (a.second!=b.second) return a.second < b.second;
    return a.first < b.first;
}

int main(){


    
    //입력
    int n;
    cin>> n; vector<cor> arr(n);
    for (int i=0; i<n; i++){
        cin>> arr[i].first >> arr[i].second;
    }

    //정렬
    sort(arr.begin(),arr.end(),comp);

    //출력
    for (int i = 0; i < n; i++) {
        cout << arr[i].first << " " << arr[i].second << '\n';
    }
    return 0;
}
//pair쓰기 - typedef pair<int, int> cor; 설정해서 일일이 자료형 쓰지 않고 cor로 대체하기!!!
//