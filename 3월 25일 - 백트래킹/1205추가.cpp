#include <iostream>
#include <vector>

using namespace std;

int findRanking(int n, int new_score, int p, vector<int> &ranking) {
    int idx = 1;//현재 위치 1등에 <비교 인덱스> 위치시키기
    int ans = 1;//정답
    //새로운 점수를 어느 위치에 넣을지 탐색
    while (idx <= n) {//현재 위치를 n번재까지 비교(작아야 계속 나아감)
        if (new_score > ranking[idx]) {//더 크면 그만 두기
            break;
        }
        if (new_score < ranking[idx]) {//작으면 현재 순위 바로 다음 순위
            ans = idx + 1;//정답 갱신
        }
        idx++;//비교할 인덱스 이동 : 굳이 이걸 밖으로 빼낸 이유 & index랑 ans 분리시킨 이유 : 동점일때 맨 끝으로 가야해서. 
    }
    if (idx == p + 1) { //랭킹 리스트에 들어가지 못하는 경우 : N==P인데 하필 그 N개 중 꼴지/동점 한 경우..
        return -1;//-1 리턴
    }
    return ans;
}

/**
 * [등수 구하기]
 *
 * 1. n = 0일 때, 고려
 * 2. 등수는 p보다 작지만, 점수가 더 좋을 때만 랭킹이 갱신되므로 랭킹 리스트에 들어가지 못하는 경우 고려 (동점)
 *
 * 현재 랭킹에 올라간 n까지 등수와 새로운 점수를 비교하며 새로운 점수 몇 등인지 계산
 * 새로운 점수가 현재 탐색 등수의 점수보다 작다면 -> 현재 탐색 등수 + 1
 * 동점일 경우 -> 그 전 등수 그대로 사용 -> 아무 처리도 하지 않음!
 */

int main() {
    int n, new_score, p;//인풋

    //입력
    cin >> n >> new_score >> p;//숫자 갯수, 내 점수, 랭킹 보여지는 범위
    vector<int> ranking(p + 1, 0);//벡터 초기화; 인덱스로 등수 접근할거라서 p+1
    for (int i = 1; i <= n; i++) {//숫자 갯수만큼
        cin >> ranking[i];//주어지는 점수로 벡터 초기화
    }

    //연산 & 출력
    cout << findRanking(n, new_score, p, ranking);//내 랭킹 찾기
    return 0;
}