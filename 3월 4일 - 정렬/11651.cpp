#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std; 
//좌표정렬하기2
pair<int,int> cor;


bool comp (const pair<int,int> &a, const pair<int,int> &b){
    if (a.second!=b.second) return a.second < b.second;
    return a.first < b.first;
}

int main(){


    
    //입력
    int n;
    cin>> n; vector<pair<int,int>> arr(n);
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
//pair쓰기
//