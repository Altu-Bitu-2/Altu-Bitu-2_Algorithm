#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef pair<int, int> ci;

struct baseball {//질문과 답 세트
    string num;       //서로 다른 세 자리 수
    int strike, ball; //스트라이크 개수, 볼 개수
};

ci cntStrikeBall(string &s1, string &s2) {//두 수 사이 스트라이크와 볼 세는 함수
    int strike_cnt = 0; //s1과 s2사이의 strike 개수
    int ball_cnt = 0;   //s1과 s2사이의 ball 개수

    for (int i = 0; i < 3; i++) {// 세자리 수이므로 3번 돌기
        if (s1[i] == s2[i]) { //위치+수 정확히 일치 -> 
            strike_cnt++;//스트라이크에 해당
        }
        else if (s1.find(s2[i]) != s1.npos) { //위치 다른데 수가 존재
            ball_cnt++;//볼에 해당
        }
    }

    return ci(strike_cnt, ball_cnt);//@@@@@@@@@@@한번에 선언하고 리턴값으로 보내주기. 
}

int game(int n, vector<baseball> &question) {//문답 갯수/ 데이터벡터 건네받아
    int ans = 0; //정답 개수

    for (int i = 123; i <= 987; i++) {//세자리 경우의 수 다 돌기
        bool check = true;//일단 다 인정. 
        string s1 = to_string(i);  //특징 잡기 쉽게 string화. 

        if (s1[0] == '0' || s1[1] == '0' || s1[2] == '0') { //0이 하나라도 있다면
            continue;//해당 X 건너뛰기
        }
        if (s1[0] == s1[1] || s1[0] == s1[2] || s1[1] == s1[2]) { //서로 같은 수 하나라도 있다면
            continue;//해당 X 건너뛰기
        }

        for (int j = 0; j < n; j++) {//문답 갯수만큼
            string s2 = question[j].num; //질문으로 들어온 수를 가지고
            ci cnt = cntStrikeBall(s1, s2); //s1과 s2사이의 스트라이크와 볼 개수를 구해서
            if (cnt.first != question[j].strike || cnt.second != question[j].ball) { //하나라도 다르면
                check = false;//가차없이 후보 목록에서 제외.
                break; //아하!@@@@@@@@@ 문답 중 하나라도 걸리면 나머지는 볼 것도 없으니까. 
            }
        }

        if (check) {//후보 목록에 남아있는 수라면
            ans++;//가능 정답 갯수 늘려주기
        }
    }

    return ans;//가능 정답 갯수 리턴
}

/**
 * [숫자 야구]
 * 서로 다른 세 자리 수에서 위치 + 수 같으면 스트라이크, 위치는 다르고 수가 존재하면 볼
 * n개의 질문으로 수와 스트라이크와 볼 개수가 주어질 때, 이를 모두 만족하는 서로 다른 세 자리 정답 수의 개수
 *
 * [풀이]
 * 서로 다른 세 자리수는 123 ~ 987이 가능하다. 이는 총 865가지
 * 질문 n의 범위는 최대 100
 * 따라서 123부터 하나씩 증가시키며 정답이 되는지 검사해도 865 * 100 * 3(자릿수)으로 접근 충분히 가능!
 */

int main() {//메인
    int n;//입력값

    //입력
    cin >> n; //질문-답 세트 갯수 입력받음

    vector<baseball> question(n);//질문과 답 세트 n 개만큼 받을 그릇
    for (int i = 0; i < n; i++) {// n번 돌아가면서
        cin >> question[i].num >> question[i].strike >> question[i].ball; //질문-답 세트 받아내기
    }

    //연산 + 출력
    cout << game(n, question);//게임 함수

    return 0;
}