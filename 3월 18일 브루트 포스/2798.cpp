
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//블랙잭 

const int MAX_M = 3e5;


unsigned int calSum(vector<int> arr, vector<int> &card){
    int size = arr.size(), sum = 0;
    for (int i=0; i<size; i++){
        if (arr[i]==1) sum+=card[i];
    }
    return sum;
}

int findDiff(vector<int> &card, int M){  //M>=answer 이므로, M-answer>=0 인 minimum 값 찾기.  
    
    //nC3 구하기 위한 배열 {0,0,...,0,0,1,1,1}
    vector <int> arr(card.size()-3,0);
    int c=3;
    while(c--){
        arr.push_back(1);
    }

    //for(auto i:arr){cout<< i << '\n';} //디버깅용

    unsigned int answer = MAX_M;
    //3개합 구하고, 최솟값 갱신
    do {
        answer = min(answer,M-calSum(arr, card));//unsigned로 해줘서 음수 나오면 값이 어마무시하게 커지므로 자동탈락

    }  while (next_permutation(arr.begin(),arr.end()));

    return answer;
}

int main(){
    int N, M, input;
    cin>> N>>M;
    vector<int> card;
    while(N--){
        cin>> input;
        card.push_back(input);
    }

    cout<< M-findDiff(card, M); //M에서 minimum Diff 뺴기. 
    return 0;
}