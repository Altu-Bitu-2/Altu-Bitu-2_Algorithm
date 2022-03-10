#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//카드 역배치
void print(vector<int> card) {
	for (int i = 0; i < 20; i++) {
		cout << card[i] << ' ';
	}
	cout << "\n";

}

void swapCard(const vector<int> card){
	int a, b;
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;  a--, b--;
		int n = b - a;//영역 크기
		for (int j = 0; j <= n / 2; j++) {//양쪽 끝을 스왑
			swap(card[a], card[b]);
			a++, b--;//가운데로 이동
		}
	}
}
int main() {
	//카드 초기화
	vector<int> card(20);
	for (int i = 0; i < 20; i++) {
		card[i] = i + 1;
	}
	//연산
	swapCard(card);
	//출력
	print(card);
	return 0;
}

//기억할 점
//sort는 통째로 이동. 고정해야할 변수 있을때 쓰는거 아님. 
//하나의 변수가 2가지 용도일때 주의 : 변수 a,b는 1)각 카드 위치(템포 내 실시간 변화) 2) 한 템포 당 swap 갯수 세기 (템포 내 고정)