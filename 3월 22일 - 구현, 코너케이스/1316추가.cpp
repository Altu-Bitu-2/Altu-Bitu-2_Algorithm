#include <iostream>
#include <vector>

using namespace std;

bool isGroup(string str) {//그룹 단어인가? (제일 까다로움. 무리에서 떨어졌는지 어떻게 알지?)
    char cur = NULL; //현재의 문자
    vector<bool> alphabet(26, false); //각 알파벳의 등장 여부를 체크

    for (int i = 0; i < str.size(); i++) {//각 알파벳 살펴볼건데
        if (str[i] == cur) { //연속해서 나타난 문자; 와 이렇게 표현하는구나. 같은 문자면 쭉쭉쭉 나가도록. 
            continue;
        }
        //이전의 문자와 다른 문자가 나타났을 때
        if (alphabet[str[i] - 'a']) { //이전에 등장했던 문자면 떨어져서 나타난 것
            return false;//ALPHABET 배열이 TRUE라면, 그룹단어 아니다. 
        }
        cur = str[i];//그냥 NEW 경우라면 CURRENT 옮겨줘. 
        alphabet[str[i] - 'a'] = true; //그리고 해당 ALPHABET TRUE해줘. 
    }
    return true;//모든 알파벳 살펴봤는데 그룹단어 맞음
}

/**
 * [그룹 단어 체커] - 단순 구현 문제
 * - 이미 등장한 알파벳을 배열의 인덱스(알파벳)를 활용해서 정보 true/false로 저장
 * - set으로 체크할 수도 있겠지만 검색, 삽입 시마다 O(logN)의 시간복잡도가 걸리므로 인덱스 접근이 가능한 배열이 효율적
 * - 처음 등장하는 알파벳은 배열 정보 업데이트 하고, 무리에서 떨어졌는데 이미 등장한 알파벳이면 그룹 단어가 아니다.
 */

int main() {
    int n, result = 0;

    //입력
    cin >> n;//n개 단어
    while (n--) {//받아서
        string word;//개별 단어를
        cin >> word;//입력받음

        //연산
        if (isGroup(word)) { //그룹 단어인지 확인
            result++;//맞다면 가능 갯수에 추가
        }
    }

    //출력
    cout << result;//최종결과
    return 0;
}
//
//1. isGroup처럼 함수 이름 가독성있게 짓기. str...
//2. 연속성 나타내기? 같은 문자면 쭉쭉쭉 나가. CONTINUE 표현법 기억. 
//3. 트리 형태의 가능 케이스, 문제 풀기 전에 연상할 수 있도록. 