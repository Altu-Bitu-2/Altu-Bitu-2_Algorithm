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
    }
    if (cnt_vowel>=1 && crypto.size()-cnt_vowel >=2) return 1;//
    return 0;
}

void guessCrypto(vector<string> alpha, int c, int l){

    set <string> cryptoSet;

    //조합 구하는데 필요한 0 & 1의 배열 생성
    vector<int> arr(c-l,0);
    for (int i=0; i<l; i++){
        arr.push_back(1);
    }
    sort(arr.begin(),arr.end(),greater<int>()); //3. string 간 정렬

    //1. C개중 L개 뽑는 조합
    do {
        string crypto = "";
        for(int i=0; i<c;i++){
            if (arr[i]==1) crypto+= alpha[i];
        }
        if (!satisfied(crypto)) continue; //2. 1모음 2자음 이상인지 체크
        cout<<crypto<<'\n';
    } while(prev_permutation(arr.begin(),arr.end()));

}



int main(){

    //입력
    int l, c;
    string input;
    vector<string> alpha;
    cin>>l >> c;

    for(int i=0; i<c; i++){
        cin>> input;
        alpha.push_back(input);
    }
    sort(alpha.begin(),alpha.end()); //4. string 내 정렬

    //출력
    guessCrypto(alpha, c, l);

    return 0;
}