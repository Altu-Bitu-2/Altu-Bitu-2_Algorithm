#include <iostream>
#include <vector>
#include <string>
//배운점
//1. SET으로 구현하려 했는데, 시간 때문에 틀렸겠군. 되도록 배열 쓰는법, 
//    특히 배열의 인덱스(!!!)를 활용하도록 습관들여야겠음. 
        //이렇게 이렇게 하라!고 해서 꼭 그 실체를 그대로 구현할 필요는 없고,
        //적절한 틀/형식을 짜서 필요한 기능만 제공할 수 있으면 된다. 
//2. 명령cmd
//3. switch 생각보다 잘 안 쓰이는듯. if문으로 구현 보편적. 
//4. 명령 만 & 명령+숫자 조합등 2가지cmd 다룰때, 
//    우선 명령 먼저 앞에 if문 배치해서 직렬로 구현가능. (굳이 병렬적으로 구분할 필요 없음)
//   "공통점 뽑아내서" 간결하게 하는 원칙 엿볼 수 있음. 



using namespace std;
const int SIZE = 21;

/**
 * [집합] - 단순 구현 문제
 *
 * ver1. 배열 사용 풀이
 * set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸려요.
 * 입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 배열을 이용합니다.
 *
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */

int main() {
    ios::sync_with_stdio(false);//연산 3M이므로 시간 중요. 
    cin.tie(NULL);//입출력 개선. 

    int m, num;//연산수,
    string cmd;// cmd 종류
    vector<bool> s(SIZE, false);//배열 인덱스 활용해서 여부 확인. 

    cin >> m;
    while (m--) {//반복
        cin >> cmd;//명령 입력
        if (cmd == "all") {//명령 'all'이라면
            s.assign(SIZE, true);//배열 해당 모든 원소 '있다'고 상태바꿈
            continue;//다음 명령 받기
        }
        if (cmd == "empty") {//명령 '비움'이라면
            s.assign(SIZE, false);//배열 해당 모든 원소 '없다'고 상태바꿈
            continue;//다음 명령 받기
        }

        cin >> num;// 숫자 조합 
        if (cmd == "add") {//명령 '더하기'라면
            s[num] = true;//해당원소 '있다'고 바꿈
            continue;//다음 명령 받기
        }
        if (cmd == "remove") {//명령 '빼기'라면
            s[num] = false;//해당원소 '없다'고 바꿈
            continue;//다음 명령 받기
        }
        if (cmd == "check") {//명령 '확인'이라면
            cout << s[num] << '\n'; //bool 형을 출력하면 true: 1, false: 0으로 출력
            continue;//다음 명령 받기
        }
        if (cmd == "toggle") {//명령 '바꾸기'이라면
            s[num] = !s[num];// not 명령으로 교체
            continue;//다음 명령 받기
        }
    }
    return 0;
}

