#include <iostream>
#include <vector>

//문제에서 특정 틀 안에서 데이터를 주면 그럴만한 이유가 있는 것이다...
//연산자를 빈도수별로 주었다는건, 일단 냅다 4개 질러놓고 나중에 빈도수 확인해가며 가지치기 하라는거였음. 
//있는거가지고 괜히 낑낑거리면서 조합하려하지 말고 통크게 지르고 나서 수습하는게 깔끔. 
using namespace std;
const int INF_MAX = 1e9;//1B
const int SIZE = 11;//숫자의 최대 갯수

int n;//실제 숫자 갯수
vector<int> num(SIZE + 1);//숫자를 인덱스로 접근하려나보다(아님, 걍 넉넉하게 미리 선언한거임.. 근데 그럼 걍 SIZE여도 되지 않나?-> 아 마지막에 다음꺼를 접근할 가능성을 염두에 두고?)
vector<int> expression(4); //0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX;//+-1B를 기준으로 최대/최소 구하려는듯

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum);//최댓값 갱신
        min_value = min(min_value, sum);//최솟값 갱신
        return;
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) {//만약 해당 연산자가 남아있다면 - (안 남아있으면 가지치기!!!!)
            expression[i]--;//실행해고 하나 줄여
            int new_sum = 0;//갱신된 결과값 넣을 자리
            switch (i) { //연산자 종류에 따라
                case 0://덧셈이면
                    new_sum = sum + num[cnt + 1];//지금까지 연산 결과에, 다음꺼랑 더해주기
                    break;//스위치 탈출
                case 1://뺄셈이면
                    new_sum = sum - num[cnt + 1];//지금까지 연산 결과에, 다음꺼를 빼해주기
                    break;//스위치 탈출
                case 2://곱셈이면
                    new_sum = sum * num[cnt + 1];//지금까지 연산 결과에, 다음꺼랑 곱해주기
                    break;//스위치 탈출
                case 3://나눗셈이면
                    new_sum = sum / num[cnt + 1];//지금까지 연산 결과에, 다음꺼를 나눠주기
                    break;//스위치 탈출
            }
            backtracking(cnt + 1, new_sum);//다음 숫자 탐방 ㄱㄱ
            expression[i]++;//아아 취소취소
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    //입력
    cin >> n;//숫자 갯수
    for (int i = 0; i < n; i++) {//만큼 숫자를
        cin >> num[i];//입력받아요. 아. 인덱스로 접근하는게 아니라 그냥 벡터로 받는거였네. 
    }
    for (int i = 0; i < 4; i++) {//연산자 갯수만큼
        cin >> expression[i];//빈도수 받아서 벡터에 저장.
    }

    //연산
    backtracking(0, num[0]);//백트래킹...(깊이 건네주고, 초기 결과값인 맨 앞숫자!)

    //출력
    cout << max_value << '\n' << min_value;///최종 갱신값
    return 0;
}