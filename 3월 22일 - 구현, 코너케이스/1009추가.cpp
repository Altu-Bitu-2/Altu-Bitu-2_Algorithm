#include <iostream>
#include <vector>

using namespace std;

vector<int> findPattern(int num) {//일의 자리 패턴 찾아주는 함수
    vector<int> pattern = {num};//일단 1번 곱했을때. 

    int temp = num;//임시저장
    while (num != (temp * num) % 10) {//만약 고유패턴이 끝나고 주기성을 띄거든 그만둬라 
        temp *= num;//거듭제곱
        temp %= 10;//일의자리만 남기기 (불필요한 앞자리 제거)
        pattern.push_back(temp);//pattern 크기 자유로운만큼, push_back
    }
    return pattern;
}

/**
 * [분산처리]
 *
 * - a^b의 일의 자리를 구하는 문제
 * - 일의 자리는 0 ~ 9 중 하나 이므로, 어떤 수를 계속 곱해 나가면 일의 자리는 패턴을 가지게 되어 있음
 *     ex) 2 -> 4 -> 8 -> 6 -> 2 ...
 * - 0 ~ 9까지 일의 자리 패턴을 미리 구한 후, a의 일의 자리에 대한 (b - 1 % 패턴의 길이)번째 수를 출력하면 된다.
 * - 0이 나올 경우 10번 컴퓨터가 처리하므로, 0이 출력되지 않도록 예외처리
 */

int main() {
    int t, a, b;//반복횟수, 밑, 지수

    //0 ~ 9까지 일의 자리 패턴 미리 구하기 : 확장성 고려(본인은 그때그때 구하려 했는데..)
    vector<vector<int>> last_digit(10, vector<int>(0));//row 10개 선언, col 크기 자유롭게
    vector<int> pattern_size(10, 1);//10개 각각의 패턴 사이즈, 내용 1로 초기화
    for (int i = 0; i < 10; i++) {//0~9까지 돌기
        last_digit[i] = findPattern(i);// 패턴 찾아서 vector로 돌려주는 함수
        pattern_size[i] = last_digit[i].size();//패턴 크기 저장
    }

    //입력
    cin >> t;//테스트 케이스
    while (t--) {//t번 동안 반복
        cin >> a >> b; //지수, 밑 입력
        a %= 10; //필요한 일의자리수만 취하겠다

        if (a == 0) {//10의 자리라면 (특수...이자 0 나오지 않도록.)
            cout << "10\n";//바로 정답 출력 (10의 n승은 뭘하도 일의 자리 0이라서) 
            continue;//다음 테스트 케이스로. 
        }
        //인덱스가 0부터 시작하므로 (b - 1)로 계산해야 함을 주의
        cout << last_digit[a][(b - 1) % pattern_size[a]] << '\n';//b는 패턴 위에서 주기성을 띄므로 패턴크기만큼 모듈러해줌. 
    }
    return 0;
}
//느낀점/기억할점
//1. 패턴 미리 구해놔서 저장해둠. 패턴사이즈까지. 
//2. findPattern때 while문 조건 깔끔하게 구현함. 나라면 그렇게 못할 거 같았음. 
//3. row 고정, col 자유로운 2차 배열 구현 바로 안 떠오름. 
//4. 10번 특수케이스인거 자각 못함. 표면적으로 1~10으로 구현하지 않고 0~9까지 해야(어차피 10으로 나누어야하니까)