#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//암호 만들기
//
bool satisfied(string crypto){
    int cnt_vowel=0, cnt_consonant=0;
    for (int i=0; i<crypto.size();i++){
        if (crypto[i]=='a' || crypto[i]=='e'|| crypto[i]=='i'|| crypto[i]=='o'|| crypto[i]=='u') cnt_vowel++;
        else cnt_consonant++;
    }
    if (cnt_vowel>=1 && cnt_consonant>=2) return 1;
    return 0;
}

set<string> guessCrypto(vector<string> alpha, int C, int L){

    set <string> cryptoSet;

    //조합 구하는데 필요한 0 & 1의 배열 생성
    vector<int> arr(C-L,0);
    int l=L;
    while (l--){
        arr.push_back(1);
    }

    //1. C개중 L개 뽑는 조합
    do {
        string crypto = "";
        for(int i=0; i<C;i++){
            if (arr[i]==1) crypto+= alpha[i];
        }
        if (!satisfied(crypto)) continue; //2. 1모음 2자음 이상인지 체크
        sort(crypto.begin(),crypto.end()); //3. 알파벳순으로 string 내 정렬
        cryptoSet.insert(crypto); //4. Set에 넣어 string 간 정렬

    } while(next_permutation(arr.begin(),arr.end()));

    return cryptoSet;
}



int main(){

    //입력
    int L, C;
    string input;
    vector<string> alpha;
    cin>>L >> C;
    int c=C;
    while (c--){
        cin>> input;
        alpha.push_back(input);
    }

    //set 출력
    for (auto i:guessCrypto(alpha, C, L)){
        cout<< i << '\n';
    }

    return 0;
}