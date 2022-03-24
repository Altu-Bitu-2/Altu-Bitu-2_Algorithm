#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//permutation 공부용

int main (){int cnt=0;
    vector<int> v = {0,1,0,1};
    do {
        for(auto I:v){
            cout<< I <<' ';
        }
        cout<< '\n';
        cnt++;
    } while (next_permutation(v.begin(),v.end()));
    cout<<cnt;
    return 0;
}