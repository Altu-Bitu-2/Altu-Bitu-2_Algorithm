
#include <iostream>
#include <vector>
using namespace std;

//체스판 : 보드 col 홀수일때 결과값 자꾸 틀림. 

vector<vector<int>> board;
vector<vector<int>> chess;
const int B=1, W=0, MAX_ANSWER=64;

int calDiff(int i, int j){ //보드 각 자리에서 BW/WB 중 더 작은 값 리턴
    int cnt=0;
    for (int k=0; k<8;k++){
        for (int l=0; l<8;l++){
            if(board[i+k][j+l]!=chess[k][l]) cnt++;
        }
    }
    return min(cnt,64-cnt); //(BW~형식일때 바꿔야할 갯수)+(WB형식일때 ~) = 64개로 일정하므로
}

int findMinBlock(int r, int c){ //보드에 자리별 비교-> 최소값 갱신
    int answer=MAX_ANSWER;
    int i=0, j=0;
    do {
        answer = min(answer,calDiff(i,j));
        i++,j++;
    } while(i+8<=c && j+8<=r);
    return answer;
}

int main(){
    char Sq;
    int r,c;
    cin>> r >> c;

    //보드 입력
    board.assign(r,vector<int>(c,W));
    for (int i=0; i<r;i++){
        for (int j=0; j<c;j++){
            cin>> Sq;
            if (Sq=='B') board[i][j]=B;
        }
    }

    //기준 체스판 생성
    chess.assign(8,vector<int>(8,B));
    for (int i=0; i<8;i++){
        for (int j=0; j<8;j++){
            if((i%2==0 && j%2!=0) || (i%2!=0 && j%2==0)) chess[i][j]=W;
        }
    }
    
    //디버깅용
    // for (int i=0; i<r;i++){
    //     for (int j=0; j<c;j++){
    //         cout<< board[i][j];
    //     }
    //     cout<<'\n';
    // }
    // cout<<'\n';
    // for (int i=0; i<8;i++){
    //     for (int j=0; j<8;j++){
    //         cout<< chess[i][j];
    //     }
    //     cout<<'\n';
    // }

    cout<< findMinBlock(r,c);

    
    return 0;
}