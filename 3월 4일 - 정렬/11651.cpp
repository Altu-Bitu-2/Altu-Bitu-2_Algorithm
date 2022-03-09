#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
//좌표정렬하기2
struct cor {int x, y;};

bool comp (const cor &a, const cor &b){
    if (a.y!=b.y) return a.y < b.y;
    else return a.x < b.x;
}

int main(){
    //입력
    int n;
    cin>> n; vector<cor> arr(n);
    for (int i=0; i<n; i++){
        cin>> arr[i].x >> arr[i].y;
    }

    //정렬
    sort(arr.begin(),arr.end(),comp);

    //출력
    for (int i = 0; i < n; i++) {
        cout << arr[i].x << " " << arr[i].y << '\n';
    }
    return 0;
}