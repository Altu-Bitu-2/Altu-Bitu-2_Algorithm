#include <iostream> 
using namespace std; 

//창용이의 시계 - 틀림 : 시계의 주기성 고려했으나 또 틀림.

int main(){
    const int HOUR = 3600;
    const int MINATE= 60;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, m, s, q, T, c; 
    cin >> h >> m >> s >> q; 
    long long time = h*HOUR + m*MINATE + s; 

    for (int i=0; i<q; i++){
        cin >> T;
        switch(T){
            case 1 : cin>>c; time+=c; break;
            case 2 : cin>>c; time-=c; while(time<0){time+=24*HOUR;} break;//음수일때 12시간 더해줘서 시간 표시. 
            case 3 : cout<< time/HOUR%24 << " "<< (time%HOUR)/MINATE << " "<< time%HOUR%MINATE <<'\n'; break;
            default: cout<<"wrong input"; break;
            }
    }

    return 0;
}

//계산하기 편한 상태로 변환해서 연산
//히든 케이스 찾기 : 범위 유의해서 너무 크다 싶으면 냅다 양극단 체크해보기

