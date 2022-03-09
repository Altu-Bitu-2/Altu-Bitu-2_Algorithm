#include <iostream> 
using namespace std; 

//창용이의 시계 - 틀림 : 출력값은 맞는데 출력되는 타이밍이 이상함. 

int main(){
    int h, m, s, q, T, c; 
    cin >> h >> m >> s >> q; 
    int time = h*3600 + m*60 + s; 

    for (int i=0; i<q; i++){
        cin >> T;
        switch(T){
            case 1 : cin>>c; time+=c; break;
            case 2 : cin>>c; time-=c; break;
            case 3 : if (time<0) {cout<< 0;}
            cout<< time/3600%24 << " "<< (time%3600)/60 << " "<< time%3600%60 <<'\n'; break;
            default: cout<<"wrong input"; break;
        } 
        
    }

    return 0;
}

//계산하기 편한 상태로 변환해서 연산
//히든 케이스 찾기 : 범위 유의해서 너무 크다 싶으면 냅다 양극단 체크해보기