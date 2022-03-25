
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//블랙잭 


int calSum(vector<int> arr, vector<int> &card){
    int size = arr.size(), sum = 0;
    for (int i=0; i<size; i++){
        if (arr[i]==1) sum+=card[i];
    }
    return sum;
}

int findDiff(vector<int> &card, int M){  //M>=answer 이므로, M-answer>=0 인 minimum 값 찾기.  
    
    //nC3 구하기 위한 배열 {0,0,...,0,0,1,1,1}
    vector <int> arr(card.size(),0);
    for (int i=0; i<3; i++){
        arr[i]=1;
    }

    int answer = 0;
    //3개합 구하고, 최솟값 갱신
    do {
        int sum= calSum(arr, card);
        if (sum<=M){
            answer = max(answer,sum);
        }
    }  while (prev_permutation(arr.begin(),arr.end()));

    return answer;
}

int main(){
    int N, M, input;
    cin>> N>>M;
    vector<int> card(N,0);
    for(int i=0; i<N; i++){
        cin>>card[i];
    }

    cout<< findDiff(card, M);
    return 0;
}