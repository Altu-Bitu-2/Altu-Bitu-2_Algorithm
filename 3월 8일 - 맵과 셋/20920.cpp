#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
//영단어 문제 - 못 풀겠어서 추가제출
//map으로 각 단어 빈도수 세서 정렬한 다음, vector로 그 순서대로 받아서 나머지 2개 기준대로 재정렬하려고 했으나 
//막힘+ 너무 복잡하고 어수선한 코드인 것 같아서 그만둠. 
bool comp(const vector<string,int> &a, const vector<string,int> &b){
    if (a).length()!=(*b).length())
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int N,M; string word;
    map<string,int, greater<int>> freq;
    cin>> N,M;
    while(N--){
        cin>>word;
        if (word.length()<=M) continue;
        if(freq.find(word)!=freq.end()) freq[word]++; //이미 map에 속한 원소라면 빈도수 1 늘리기
        else freq[word]=1; //새 원소라면 빈도수 1로 저장
    }

    vector<string,int> vocab(freq.size());
    for (auto iter:freq){
        vocab.push_back(iter.first);
    }

    sort(vocab.begin(),vocab.end(),comp);
    for(auto iter:vocab){
        cout << iter;
    }
    return 0;
}