#include <stdio.h>
#include <string.h>
#include <math.h>

int HanoiTower(int num, char cur, char to) {
    if(num == 1) {
        printf("%d %d\n", cur, to);
        return 0;
    }

    char behind_to = cur ^ to;

    HanoiTower(num - 1, cur, behind_to);
    printf("%d %d\n", cur, to);

    HanoiTower(num - 1, behind_to, to);

    return 0;
}

int main() {
    int num = 0;
    scanf("%d", &num);

    printf("%d\n", ((int)pow(2.0, (double)num) - 1));
    HanoiTower(num, 1, 3);

    return 0;
}