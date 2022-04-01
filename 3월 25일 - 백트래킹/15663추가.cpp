#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 8; //배열 크기

int n, m;
vector<int> num(SIZE);//미리 초기화
vector<int> ans(SIZE);//
vector<bool> check(SIZE);//중복 제거용

void backtracking(int cnt) {
    if (cnt == m) { //길이 m 이라면 (기저조건)
        for (int i = 0; i < m; i++) {//정답 길이 m만큼
            cout << ans[i] << ' ';//정답 출력
        }
        cout << '\n';
        return;
    }
    int prev = 0; //이전에 선택한 값 만 따지면, 
    for (int i = 0; i < n; i++) {//주어진 경우의 수(num 안의 선택지)
        if (!check[i] && prev != num[i]) { //<수 위치 중복 체크 : 가로축에서 같은 값 나오는 것 가지치기> && <이전에 탐색한 값이 아니라면 : 세로 축에서 같은 값-sort 되어있으니 가능- 또 나오는 것 가지치기>
            prev = num[i];//(아마도 처음 나온)현재 값 저장해두기, 후에 같은 숫자 나오면 피할 수 있도록. 
            ans[cnt] = num[i];//정답에 넣어줌
            check[i] = true;//이용됐다 체크
            backtracking(cnt + 1);//다음 깊이로 넘어가
            check[i] = false;//탈출했으니 다시 이용해도 되도록 언체크
        }
    }
}

/**
 * 1. 우선 수열을 사전 순으로 증가하는 순서로 출력해야 하므로 주어진 수열을 오름차순 정렬
 * 2. 이 상태에서 우선, 같은 위치의 수를 또 선택하지 않도록 중복제거 (check 배열 사용)를 해줌
 * 3. 그 후, 중복되는 "수열"을 거르는 방법은 이전에 선택한 값을 변수에 저장해서, 수열을 만들다 다시 루트 노드로 돌아왔을 때
 *    이전에 선택한 값과 같은 값이면 넘어가면 됨! -> 어차피 같은 수이므로 같은 과정 반복해서 똑같은 수열이 나올 것
 */

int main() {
    //입력
    cin >> n >> m;//숫자 갯수, 선택 갯수 입력받기
    for (int i = 0; i < n; i++) {//숫자갯수만큼
        cin >> num[i];//숫자 받아서 넣어주기
    }

    //연산
    sort(num.begin(), num.begin() + n);//큰 순서대로(num은 배열 넉넉히 해놨으니까 end말고, n만큼만 띄어서)

    //백트래킹 & 출력
    backtracking(0);
    return 0;
}