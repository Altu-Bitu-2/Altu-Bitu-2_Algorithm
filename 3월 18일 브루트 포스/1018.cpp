
#include <iostream>
#include <vector>
using namespace std;

//체스판

vector<vector<char>> board;
vector<vector<char>> chess;
const int MAX_ANSWER=64;

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

    for(int i=0;i<=r-8;i++){
        for(int j=0;j<=c-8;j++){
            answer = min(answer,calDiff(i,j));
        }
    }
    return answer;
}

int main(){
    string row;
    int r,c;
    cin>> r >> c;

    //보드 입력 - 행 자체를 string으로 받아버려도 공백 입력을 처리할 수 있답니다
    board.assign(r,vector<char>(c,'W'));
    for (int i=0; i<r;i++){
        cin>> row;
        for (int j=0; j<c;j++){
            if (row[j]=='B') board[i][j]='B';//자료형 불일치
        }
    }

    //기준 체스판 생성 - 규칙 활용(합이 일정) (사실 생성 안해도 규칙활용해서 문제 풀 수 있음)
    chess.assign(8,vector<char>(8,'B'));
    for (int i=0; i<8;i++){
        for (int j=0; j<8;j++){
            if((i+j)%2==1) chess[i][j]='W';
        }
    }

    cout<< findMinBlock(r,c);

    
    return 0;
}