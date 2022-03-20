#include <iostream>
#include <math.h>

using namespace std;
//공약수 두 수를 GCD, LCM으로 갖는 자연수 쌍 A, B가 있다고 할때
//A=a*GCD, B=b*GCd, LCD = a*b*GCD 로 표현 가능. 
//고로 a,b가 최솟값인 경우 구할 것. 

int gcd(int a, int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

bool coprime (int a, int b){
    if (gcd(a,b)==1) return 1;
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int G, L, a,b;

    cin>> G >> L;
    if (G>L) swap(G,L);
    if (L%G!=0) return 0;// 조건 만족하는 output 없는 경우. 
    int a_b=L/G; // a*b를 의미

    for (int i=sqrt(a_b);i>0;i--){
         //a*b 약수쌍 중 1)서로소인 것 2) 제일 작은 것
        if (a_b%i!=0) continue;
        if (!coprime(i,a_b/i)) continue;
        a=i; break;
    }

    b=a_b/a;

    cout<<G*a<<' '<<G*b;

    return 0;
}