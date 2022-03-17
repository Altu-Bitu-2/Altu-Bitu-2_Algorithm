#include <iostream>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;
bool sortBySec (const pair<int,int> &a, const pair<int,int> &b){
    if (a.second!=b.second) return a.second>b.second;
    return a.first<b.first;
}

float avg(vector<int> &v){//
    return accumulate(v.begin(),v.end(),0.0)/v.size();
}

int mid(vector<int> &v){//중앙값
    sort(v.begin(),v.end());
    return v[(v.size()+1)/2-1];
}

int mod(vector<pair<int,int>> &m){
    sort(m.begin(),m.end(),sortBySec);
    if (m[0].second == m[1].second) return m[1].first;
    return m.begin()->first;
}

int rg(vector<pair<int,int>> &m){
    return (m[m.size()-1].first - m.begin()->first);
}

int main(){
    int N,input,median,mode,range,avgerage;
    cin>>N;
    vector<int> v;

    map<int,int> freq;
    //입력
    while(N--){
        cin>>input;
        freq[input]++;
        v.push_back(input);
    }
    vector<pair<int,int>> m(freq.begin(),freq.end());//value로 정렬해야해서 vector화

    //출력
    avgerage = (int)round(avg(v));//vector 이용
    median = mid(v);//중앙값 vector 정렬한 뒤 이용
    range = rg(m);//map의 정렬 성질 이용
    mode = mod(m);//map울 value값에 따라 재정렬 한 뒤 이용
    cout<<avgerage <<'\n';
    cout<< median <<'\n';
    cout<< mode <<'\n';
    cout<<  range <<'\n';

    return 0;
}