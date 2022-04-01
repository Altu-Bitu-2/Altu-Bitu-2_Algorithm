#include <iostream>
#include <vector>

using namespace std;

struct info { //컨테이어 각 벨트별 
    int power;//내구도
    bool is_on;//로봇 존재 여부
};

vector<info> belt;  //컨테이너 벨트 정보(내구도, 로봇 여부)
int zero_power;     //내구도가 0인 벨트 칸의 개수

int minusPosition(int n, int pos) { //인덱스 감소 함수
    if (--pos >= 0) {//순환성 띄므로, 양수일때는 그냥 ㄱㄱ
        return pos;//그대로 하나만 빼준거 넘기고
    }
    return n * 2 - 1;//음수일때 는 다시 full로 충전해줘야돼서 인자로 n 필요함
}

void second(int n, int start, int end) {//컨테이어벨트 돌아가는 상황
    int cur = end;//윗면 에서 움직일 수 있는 로봇은 움직인다. 
    while (cur != start) { //end - 1 부터 start 까지 검사 : 
        cur = minusPosition(n, cur);//왜냐면 움직일 수 있는 로봇은 end-1부터니까. 
        int next = (cur + 1) % (n * 2); //다음 위치 : 내 옆자리. 
        if (belt[cur].is_on && !belt[next].is_on && belt[next].power) { //현재 위치에 로봇이 있고, 다음 위치에 로봇이 없으며 내구성 1이상인 경우 -> 로봇 옮김
            belt[cur].is_on = false;//로봇 떠나가욥
            belt[next].power--;//로봇 새로 왔어욥
            if (next != end) { //내리는 위치 아닐 경우만 "언제든지 내리는 위치에 도달하면 그 즉시 내린다"
                belt[next].is_on = true; //로봇 옮기기
            }
            if (belt[next].power == 0) {//내구성 다 고갈됨
                zero_power++;//k에서 하나 추가요. 
            }
        }
    }
}

void third(int start) {
    if (belt[start].power) { //올리는 위치의 내구도가 0이 아니라면 로봇 올림
        belt[start].is_on = true;//로봇 올라가욥
        belt[start].power--;//내구성 떨어뜨린 후
        if (belt[start].power == 0) {//고갈됐는지 체크
            zero_power++;// 고갈 하나 추가요. 
        }
    }
}

/**
 * [컨베이어 벨트 위의 로봇 문제]
 * 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 * 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동 (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 * 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 * 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 * -> 1 ~ 3까지가 1단계
 *
 * [문제 풀이]
 * 벨트의 로봇을 옮기는 게 아니라, 올리는 위치와 내리는 위치의 인덱스 값을 바꿔서 접근****** 고정&변동 변수를 
 * 필요한 컨테이너: 내구도와 로봇의 존재여부를 체크할 배열
 *
 * 1번: 벨트의 방향이 오른쪽이므로, 벨트 한 칸 회전 시 올리는 위치와 내리는 위치의 인덱스 값은 하나 감소
 * 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
 * 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
 *
 * 해당 문제는 deque 자료구조를 사용해서도 구현 가능 (1번에서 회전하는 부분만 다르고 2번, 3번은 동일한 로직)
 */

int main() {
    ios_base::sync_with_stdio(false);//입출력 시간 향상
    cin.tie(NULL);

    int n, k; //변수 ,k

    //입력
    cin >> n >> k;//컨테이너 길이와 마감갯수
    belt.assign(n * 2, {0, false});//벨트 모두 내구성0, 로봇 없음으로 선언                                  
    for (int i = 0; i < n * 2; i++) {//벨트 하나하나
        cin >> belt[i].power;//주어진 내구도로 초기화
    }

    //연산
    int start = 0;    //올리는 위치
    int end = n - 1;  //내리는 위치
    int step = 0;     //단계 수
    while (true) {//기계 계속 돌립니다. 
        start = minusPosition(n, start);//컨테이너 벨트를 한칸씩 
        end = minusPosition(n, end);//오른쪽으로 ㄱㄱ. 여기서 주의 : 순환성 띄므로 함수처리
        if (belt[end].is_on) { //벨트 회전 후, 로봇이 내리는 위치에 있다면 내리기 - 만약 내 위에 로봇 있다면
            belt[end].is_on = false;//로봇 떨어져 나가욥 "즉시 내린다"
        }
        second(n, start, end);//움직일 수 있는 로봇은 움직여라. 
        third(start);//올릴수 있다면, 로봇을 올려라. 
        //여기까지가 한 단계
        step++;//한 단계 수행 완료 후, 
        if (zero_power >= k) {// 고갈된 벨트가 k개 '이상이라면'
            break;//기계를 멈춘다. 
        }
    }

    //출력
    cout << step;//몇 단계 거쳤는지
    return 0;
}