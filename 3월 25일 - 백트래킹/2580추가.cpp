#include <iostream>

using namespace std;

const int MAX = 9; //스도쿠 한 행 사이즈

int sudoku[MAX][MAX];         //스도쿠 정보
bool check_row[MAX][MAX + 1]; //각 행의 숫자 존재 여부 체크
bool check_col[MAX][MAX + 1]; //각 열의 숫자 존재 여부 체크
bool check_3x3[MAX][MAX + 1]; //각 3x3 사각형의 숫자 존재 여부 체크

bool fillSudoku(int idx) {//각 칸 0~부터 80까지. 
    if (idx == MAX * MAX) { //스도쿠 모두 채움 (기저 조건)
        return true;//끝, 완성
    }
    int row = idx / MAX;//0~80 몫==행
    int col = idx % MAX;// 0~80 나머지 ==열

    if (sudoku[row][col]) { //이미 숫자가 채워진 칸이라면 다음 칸으로 넘어감
        return fillSudoku(idx + 1);//이런식으로 인덱스를 깊이로 지정. 
    }
    //0이고, 내가 채워넣어야할 자리.
    for (int i = 1; i <= MAX; i++) { //1~9까지 넣어보기
        if (!check_row[row][i] && !check_col[col][i] && !check_3x3[(row / 3) * 3 + col / 3][i]) {//가지치기 : 만약 i가 row/col/3x3 에 하나라도 있는 수라면 가지치고, 셋 다 없으면
            check_row[row][i] = true;//체크
            check_col[col][i] = true;//체크
            check_3x3[(row / 3) * 3 + col / 3][i] = true;//체크해준뒤
            sudoku[row][col] = i;//해당 자리에 넣어주고
            if (fillSudoku(idx + 1)) {//옆칸으로 넘어가줌. 
                return true; //생각해보기 : 이 부분이 없으면 어떻게 될까요? - 여기서 바로 리턴해주지 않으면 밑에 있는 'go back' 연산들을 수행해서, 기껏 열심히 채워놓은 스도쿠들을 도로 다시 지워버리게 됩니다. ㅠㅠ
            }
            check_row[row][i] = false;//돌아온 경우; 다시 언체크해줘야 다음에 사용가능. 
            check_col[col][i] = false;//언체크
            check_3x3[(row / 3) * 3 + col / 3][i] = false;//언체크
            sudoku[row][col] = 0;//해당 자리 비워두기(지우기)
        }
    }
    return false;//스도쿠가 막혀버린 케이스가 되면, 틀렸다고 해서 go back해줌. 가지치기. 
}

/**
 * 가지치기 효율: 80ms
 *
 * 9X9의 스도쿠에서 각 행, 열, 3x3 사각형에 1~9가 존재하는지 체크하는 2차원 배열 활용
 * 각 2차원 배열의 행: 어느 부분에 대한 체크인지(행, 열, 3x3), 0번 인덱스부터 시작
 * 각 2차원 배열의 열: 1 ~ 9 숫자 체크
 *
 * 행과 열은 바로 사용하면 됨
 * (ex) check_row[3][2] = true;  //3행에 2라는 숫자가 존재한다는 것
 *      check_col[8][9] = false; //8열에 9라는 숫자가 존재하지 않는다는 것
 *
 * 3x3 사각형 (하나를 각 구역이라고 표현)
 * -> 행을 3으로 나눈 몫과 열을 3으로 나눈 몫으로 구역 0부터 8까지 다음과 같이 나타낼 수 있음
 * (0,0) (0,1) (0,2)
 * (1,0) (1,1) (1,2)
 * (2,0) (2,1) (2,2)
 * -> 1차원 배열 인덱스로 구분하기 위해 각 (행 / 3)값에 3을 곱한 후 (열 / 3)을 더함
 * -> 따라서 3x3 사각형의 구간은 (row / 3) * 3 + (col / 3) = 0 ~ 8인 구간으로 나눌 수 있음
 */

int main() {
    //입력
    for (int i = 0; i < MAX; i++) {//주어진 스도쿠
        for (int j = 0; j < MAX; j++) {//가로세로
            cin >> sudoku[i][j];//각 자리수 입력받기
            if (sudoku[i][j]) { //스도쿠 상태 보고, check배열들 초기화
                check_row[i][sudoku[i][j]] = true;//-라는 숫자 존재한다
                check_col[j][sudoku[i][j]] = true;//-라는 숫자 존재한다
                check_3x3[(i / 3) * 3 + j / 3][sudoku[i][j]] = true;//-라는 숫자 존재한다
            }
        }
    }

    //연산
    fillSudoku(0);//백트래킹

    //출력
    for (int i = 0; i < MAX; i++) {//완성된 스도쿠
        for (int j = 0; j < MAX; j++) {//가로세로만큼 출력
            cout << sudoku[i][j] << ' ';// 각 자리 띄어쓰기
        }
        cout << '\n';//행 구분
    }
    return 0;
}