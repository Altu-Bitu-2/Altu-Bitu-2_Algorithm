#include <iostream>
#include <string>
using namespace std;

typedef pair<int, int> pr;

int gcd(pr pair){
    int a=pair.first, b=pair.second;
    if (a<b) swap(a,b);
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}


pr getNum(string input){
    pr pair;
    int colon = input.find(':');
    pair.first = stoi(input.substr(0,colon));
    pair.second = stoi(input.substr(colon+1));
    return pair;
}

//백대열 문제
int main(){
    string input;
    cin>>input;
    pr pair = getNum(input);
    cout << pair.first / gcd(pair) << ':' << pair.second / gcd(pair);
}