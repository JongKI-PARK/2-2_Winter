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
