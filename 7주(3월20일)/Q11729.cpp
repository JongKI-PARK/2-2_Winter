// Q11729.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

void hanoiTower(int n, int a, int b);
void hanoiCount(int num);

int main()
{
    int num;
    //scanf_s("%d", &num);
    cin >> num;
    cout << "\n";
    hanoiCount(num);
    hanoiTower(num, 1, 3);
   
    
    return 0;
}

void hanoiTower(int n, int a, int b) {

    int c;

    if (n <= 1) {   //남은 원판이 1개면 그냥 옮긴다.
        //printf("%d번 원판: %d -> %d\n\n", n, a, b);
        cout << a << " -> " << b << "\n\n";

    }
    else {
        c = 6 - a - b;  //나머지 기둥, 6 = 1 + 2 + 3

        hanoiTower(n - 1, a, c);     //처음 목표가 1(a) > 3(b) 옮기는 거라면 n-1개를 1 > 2(c = 6 - a - b)로 옮겨야 한다.
        //printf("%d번 원판: %d -> %d\n\n", n, a, b);
        cout << a << " -> " << b << "\n\n";
        hanoiTower(n - 1, c, b);     //n-1개를 목표 기둥으로 옮긴다.
    }

}

void hanoiCount(int num) {
    int count = (int)pow(2, num) - 1;
    cout << count << "\n\n";
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
