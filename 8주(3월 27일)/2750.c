#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

void Swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void QuitSortInc(int arr[MAX_SIZE], int start, int end)
{
    int length = end - start + 1;
    if (length > 1)
    {
        int pivot = arr[start];
        int low = start;
        int high = end;
        while(low <= high) {
            if(arr[low] > pivot && arr[high] < pivot) {
                Swap(&arr[low], &arr[high]);
                low++;
                high--;
            }
            if(arr[low] <= pivot) low++;
            if(arr[high] >= pivot) high--;
        }

        Swap(&arr[start], &arr[high]);

        QuitSortInc(arr, start, high - 1);
        QuitSortInc(arr, high + 1, end);
    }
}

int main()
{
    int array[MAX_SIZE];
    memset(array, 0x00, MAX_SIZE);

    int N = 0;
    int length = 0;
    scanf("%d", &N);

    for (length; length < N; length++)
        scanf("%d", &array[length]);

    QuitSortInc(array, 0, length - 1);

    for (int x = 0; x < length; x++)
        printf("%d\n", array[x]);

    return 0;
}