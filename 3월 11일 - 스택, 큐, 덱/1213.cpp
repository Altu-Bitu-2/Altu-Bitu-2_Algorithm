#include <iostream>
#include <map>
using namespace std;

bool possible(map<char,int> &freq){
    int cnt=0;
    for (auto iter:freq){
        if (iter.second%2!=0) cnt++;//빈도수가 홀수인 char가 1개 이하일때만
    }
    if (cnt>1) return 0;
    return 1;//가능
}

int main(){
    
    string name;
    string plnd = "";
    map<char,int> freq;
    //입력
    cin>>name;
    //각 알파벳 빈도수 나타낸 map 형성
    for (int i=0; i<name.size();i++){
        freq[name[i]]++; 
    }

    //안 되는 경우
    if (!possible(freq)){cout<<"I'm Sorry Hansoo";return 0;}


    //팰린드롬 앞부분
    for (auto iter:freq){
        int n=iter.second/2;
        while(n--){
            plnd += iter.first;
            iter.second--;
        }
        
    }

    //만약 홀수라면 가운데 글자 넣기
    for (auto iter:freq){
        if(iter.second%2==1){plnd+=iter.first; iter.second--;}
    }
    //팰린드롬 뒷부분
    for (auto iter=freq.rbegin();iter!=freq.rend();iter++){
        while ((*iter).second!=0) {
            plnd += (*iter).first;
            (*iter).second--;}
    }
    cout<<plnd;

    return 0;
}